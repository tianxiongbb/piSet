# piSet: a set of pipeline for piRNA and transposon analysis

---
## 0. Why piSet?
Due to the fast accumulation of sequencing data for different species, it is necessary to use a comprehensive pipeline for analyzing piRNA and transposons.

Our old sofwares [piPipes](https://github.com/bowhan/piPipes) and [TEMP](https://github.com/JialiUMassWengLab/TEMP) and great for piRNA and transposon analysis. However, piPipes is not user-fridenly for **newly assembled species** like koala or scorpion and TEMP is not good at calling **transposon insertion with low penetrance** (eg. newly acquired transposon insertion).

In another aspect, piRNA cluster/gene annotation is still a challenge though several scientist have started the first step in this aspect like [piClust](http://epigenomics.snu.ac.kr/piclustweb/), [proTRAC](http://www.smallrnagroup.uni-mainz.de/software/proTRAC_documentation_v2.4.1.pdf) and [Xin's method](https://www.tandfonline.com/doi/pdf/10.4161/cc.24989) for piRNA gene annotation using RNAseq, smallRNAseq, CAGE and PAS. piClust only use piRNA reads with up to 5 multiple mapped location which will impede the accurate annotation of piRNA cluster 3'/5' end. proTRAC used a probolistic mode with assumption of a uniform distribution for piRNA cluster annotation which may not be assumed. Xin's method can annotate piRNA cluster with pretty accurate 5'/3' ends and even gene structure (eg. exons, introns, isforms) but is not appropariate for all the species due to lack of CAGE and PAS data and manually fix needed.

So, we develop a new conprehensive pipeline **piSet** which can handle piRNA and transposon analysis for almost all the species with assembled genome and output all-round results and elegant figures. Further more, piSet also contains a module **piFinder** which can automaticlly annotate high quality piRNA cluster/genes with accurate 3'/5' ends and higher sensitivity/specificity for animals via smallRNAseq [and RNAseq] data in gonads. Also, piSet upgrade [TEMP](https://github.com/JialiUMassWengLab/TEMP) that only use transposon ends mapped discoordant reads for transposon insertion calling to decrease false positive that may be cause by chimeric reads.

---
## 1. install piSet
piSet is based on a bunch of software, most of the dependencies is pre-installed but three of them still need to be installed by users:  
1). [Htseq](https://htseq.readthedocs.io/en/release_0.9.1/) 2). [miRDeep2](https://github.com/rajewsky-lab/mirdeep2) 3). [cutadapt](http://cutadapt.readthedocs.io/en/stable/guide.html)   
You can use miniconda for easy install.  
To get [miniconda](https://conda.io/miniconda.html "miniconda"), run:  
```
wget https://repo.continuum.io/miniconda/Miniconda2-latest-Linux-x86_64.sh  
bash ./Miniconda2-latest-Linux-x86_64.sh 
source ~/.bashrc
conda config --add channels defaults  
conda config --add channels conda-forge  
conda config --add channels bioconda
```

After installing miniconda, typing commands below to install dependencies:
```
conda install htseq=0.9.1   
conda install mirdeep2=2.0.0.8  
conda install cutadapt=1.15  
```

After installing all the dependencies, simply go to the directory you want to store piSet and run:
```
git clone https://github.com/tianxiongbb/piSet.git  
cd piSet  
bash install.sh
source ~/.bashrc
```
By default, piSet will add piSet/bin to your PATH. Enjoy the journey with piSet :frog::frog::frog:  

---
## 2. install genome
Once you have installed piSet, you need to install and download or make all the genome annotation needed in the pipeline. Simply typing: `piSet_install_genome` to get help information.  

To install mouse mm10 genome, run:
```
piSet_install_genome -g mm10 -s "Mus musculus" -c 16  
```
piSet will automaticlly download the latest assembled version of a genome, to install genome in lower assembled version like mm9|hg19|dm3, simply run with -O:
```
piSet_install_genome -g mm9 -s "Mus musculus" -c 16 -O
```
Right now, piSet only support genome in old assembled version of mm9, hg19 and dm3. To get old assembled genome except mm10, hg19 and dm3, eg: bosTau7, you need to give the gene annotation gtf/gff file as piSet/annotation/bosTau7/bosTau7.(gtf|gff) and  run:
```
piSet_install_genome -g bosTau7 -s "Bos taurus" -c 16 -O -T http://www.repeatmasker.org/genomes/bosTau7/RepeatMasker-rm405-db20140131/bosTau7.fa.out.gz
```
tips: -T provides rmsk.url for downloading repeat element annotation in different genome version. The url can be found in [RepeatMasker Website](http://www.repeatmasker.org/genomicDatasets/RMGenomicDatasets.html)  
gene annotation file can be found in [Ensembl](https://useast.ensembl.org/info/data/ftp/index.html) or [iGenome](https://support.illumina.com/sequencing/sequencing_software/igenome.html)

To install a genome without well miRNA annotation like scopion, you may want to denovo annotate miRNA use smallRNAseq data. You can run: 
```
piSet_install_genome -g Cscu -s "Centruroides sculpturatus" -c 16 -i srnaseq.fastq -a adapter_sequence|0
```
tips: -i provides smallRNAseq data for miRNA annotation via miRDeep2.  
-a provides adapter to be remove in 3END via cutadapt, set to 0 if you don't know the adapter and piSet will automaticlly guess what adapter is in your data.   

To install a genome without well repeat element annotation like scopion, you may want to denovo annotate repeat element. You can run:  
```
piSet_install_genome -g Cscu -s "Centruroides sculpturatus" -c 16 -t
```
tips: set -t to enable denovo repeat element annotation via RepeatModeler and RepeatMasker. piSet will try to pile up all the consensus repeat sequences via RepeatModeler and then combine with known repbase sequences to annotate repeat element coordinates in genome via RepeatMasker.  

Also, if you want to denovo annotate RNA/DNA virus via RNAseq data, you can run:
```
piSet_install_genome -g Cscu -s "Centruroides sculpturatus" -c 16 -v -L left.rnaseq,fastq -R right.rnaseq.fastq
```
tips: -v enables denovo virus annotation.
-L and -R provide paired-end rnaseq.fastq for virus annotation via Trinity and diamond.

---
## 3. smallRNAseq pipeline
After installing genome, running smallRNAseq pipeline is quite easy. For smallRNAseq data for mouse mm10, simply run:
```
piSet_srnaseq -i srnaseq.fastq -g mm10 -o output_dir
```
tips: piSet_srnaseq will automaticlly running two main scripts (*piSet_srnamap, piSet_run_bed2_summary*) with default parameters. 

Especially, you may want to compare several srnaseq data at one time, then you can run:
```
piSet_srna_map -i "amybHet1.fastq amybHet2.fastq amybMut1.fastq amybMut2.fastq" -g mm10 -o output_dir -p amyb_HetMut -E -N allSM -a 0
```
tips: -E will enable piSet use EM algorithm to assign multiple mapped reads more accurately.  
set -a to 0 to automaticlly guess the adapter sequence and remove adapter for each samples.  
set -N to allSM to normalize results via all mapped reads including miRNA and other small noncoding RNAs (eg: snoRNA, snRNA)  

:runner::runner::runner:After finishing piSet_srnaseq, you may get a bunch of stuffs in output directory, which main includes results below:
1. XXX.insert files which store raw reads, reads after removing rRNA [and miRNA [and sncRNA]] and unaligned reads.
2. XXX.bed2 files which store all the mapping results including mapping to rRNA, miRNA, sncRNA, genome, puclusters, transposons and/or virus.
3. XXX.log files which store all the log for debugging.
4. bed2_summary/XXX.lendis files which store all the length distribution for each piclusters and transposons. Also there will be length distribution for all mRNA exons, CDSs, 5UTRs, 3UTRs, introns and other noncoding RNA exons and introns.
5. bed2_summary/XXX.pp files which store all the ping-pong pair information for each piclusters and transposons. Also there will be ping-pong pair information for all mRNA exons, CDSs, 5UTRs, 3UTRs, introns and other noncoding RNA exons and introns.
6. bed2_summary/XXX.phasing files which store all the phasing information for each piclusters and transposons. Also there will be ping-pong pair information for all mRNA exons, CDSs, 5UTRs, 3UTRs, introns and other noncoding RNA exons and introns.  
7. bed2_summary/XXX.cov files which store the normalized signal across the while body of each piclusters and transposons.
8. **bed2_summary/XXX.cov** files which store all the information like uniq/all mapped sense/antisense reads/species for each piclusters, transposons, genes and other noncoding genes. Also, ping-pong zscore and pairs are available for piclusters and transposons. These files is very useful if you want to get detailed information of some piclusters, transposons or genes. Or if you want to make a systematic figures yourselves.
9. figures/XXX.scatter.pdf files are final results which compare all the samples 1-to-1 by scatter plot.
10. figures/XXX.pdf files are final results which use length distribution, ping-pong and buckets to get more detailed comparison of all the samples.  

---
## 4. RNAseq pipeline
For running RNAseq pipeline for mm10, typing:  
```
# single-end RNAseq
piSet_rnaseq -l left.fq -g mm10 -o output_dir
# paired-end RNAseq
piSet_rnaseq -l left.fq -r right.fq -g mm10 -o output_dir
```

Similar to smallRNAseq pipeline, RNAseq pipeline also accept multiple input files at one time and compare them one to one. For example, if you want to compare several RNAseq data in dm3:  
```
piSet_rnaseq -l "Bill.RNAseq.gen.Thoc7_Df.ovary.r1.1.fastq Bill.RNAseq.gen.Thoc7_Df.ovary.r2.1.fastq Bill.RNAseq.gen.wt.r1.1.fastq Bill.RNAseq.gen.wt.r2.1.fastq Bill.RNAseq.gen.wt.r3.1.fastq Bill.RNAseq.gen.Thoc5e_1.092816.r1.1.fastq Bill.RNAseq.gen.Thoc5e_1.092816.r2.1.fastq" -r "Bill.RNAseq.gen.Thoc7_Df.ovary.r1.2.fastq Bill.RNAseq.gen.Thoc7_Df.ovary.r2.2.fastq Bill.RNAseq.gen.wt.r1.2.fastq Bill.RNAseq.gen.wt.r2.2.fastq Bill.RNAseq.gen.wt.r3.2.fastq Bill.RNAseq.gen.Thoc5e_1.092816.r1.2.fastq Bill.RNAseq.gen.Thoc5e_1.092816.r2.2.fastq" -g dm3 -o output_dir -t sample_information.tab -P Thoc7or5e.Mut
```
Tips1: For comparison mode with multiple input files, -p specified the output prefix name and -t which specified a sample information file is also needed.
sample_information.tab maybe like:
```
#if RNAseq is paired-end, please use the first file as file_name
#file_name  sample_type
Bill.RNAseq.gen.Thoc7_Df.ovary.r1.1.fastq Thoc7_DF
Bill.RNAseq.gen.Thoc7_Df.ovary.r2.1.fastq Thoc7_DF
Bill.RNAseq.gen.wt.r1.1.fastq Wild_type
Bill.RNAseq.gen.wt.r2.1.fastq Wild_type
Bill.RNAseq.gen.wt.r3.1.fastq Wild_type
Bill.RNAseq.gen.Thoc5e_1.092816.r1.1.fastq  Thoc5e_DF
Bill.RNAseq.gen.Thoc5e_1.092816.r2.1.fastq  Thoc5e_DF
```
Tips2: If you are not sure which replicates you want to use for differential expression calling, please run piSet_rnaseq with --no-deseq2 and then use piSet_deseq2 to do differential expression analysis after determine which replicates to use with a new(or same if all the replicates is OK) sample_information.tab
```
piSet_rnaseq -l "Bill.RNAseq.gen.Thoc7_Df.ovary.r1.1.fastq Bill.RNAseq.gen.Thoc7_Df.ovary.r2.1.fastq Bill.RNAseq.gen.wt.r1.1.fastq Bill.RNAseq.gen.wt.r2.1.fastq Bill.RNAseq.gen.wt.r3.1.fastq Bill.RNAseq.gen.Thoc5e_1.092816.r1.1.fastq Bill.RNAseq.gen.Thoc5e_1.092816.r2.1.fastq" -r "Bill.RNAseq.gen.Thoc7_Df.ovary.r1.2.fastq Bill.RNAseq.gen.Thoc7_Df.ovary.r2.2.fastq Bill.RNAseq.gen.wt.r1.2.fastq Bill.RNAseq.gen.wt.r2.2.fastq Bill.RNAseq.gen.wt.r3.2.fastq Bill.RNAseq.gen.Thoc5e_1.092816.r1.2.fastq Bill.RNAseq.gen.Thoc5e_1.092816.r2.2.fastq" -g dm3 -o output_dir -t sample_information.tab -P Thoc7or5e.Mut
 --no-deseq2
piSet_deseq2 sample_information.tab output_dir
```

:runner::runner::runner:After finishing piSet_rnaseq, you may get a bunch of stuffs in output directory, which main includes results below:  
1. bowtie2/* rRNA removing results.
2. STAR/* genome mapping results with XXX.bed12 file stands for split reads mapping information with fixed strand.
3. log_file/* all log files in pipeline.
4. signal/XXX.rmsk.rpkm All mapped RPKM for all transposons, with the same transposon family copies added into one record.
5. signal/XXX.picluster.rpkm Unique mapped RPKM for all piclusters.
6. signal/XXX.gene.rpkm Unique mapped RPKM for all genes calculated by HTSeq and then normalized to read depth and gene length.
7. signal/XXX.[rmsk|pucluster|gene].readCounts The same as 4, 5, 6 but just raw reads. This is useful for differtial expression calling using DEseq2.
8. replicates_quality/* Assessing of replicates quality in three levels: 1) pearson and spearman correlation between between all the samples; 2) principal components analysis for all the samples; 3) scatterplot showed how coordant of each replicates. You may get a overall view of each replicates quality.
8. comparison/XXX.vs.XXX.de Defferential expression results for all transposons, piclusters and genes called by DEseq2.
9. comparison/XXX.vs.XXX.norNy.[rpkm|quantile|deseq2].pdf Scatter plot to compare mean expression levels of replicates for all the transposons, piclusters and genes. Three normalization methods will be applied: 1) standard rpkm value; 2) readCounts value with quantile normalization of all the samples in all conditions; 3) readCounts value with DEseq2 normalization of all the samples in two conditions.

---
## 5. DNAseq pipeline
For running DNAseq pipeline for dm3 and enable transposon insertion finding, typing:
```
piSet_dnaseq -l left.fq -r right.fq -p out_dir/out_prefix -g dm3 -T -F -s 500
```
Tips: -T enables running TEMP and -F enables using upgraded TEMP mode for more accurate transposon insertion finding.

---
## 6. ChIPseq/CUT_and_RUN pipeline
To run H3K4me3 ChIPseq pipeline for mm10 and enable peak calling via MACS2, typing:
```
# single-end ChIPseq
piSet_chipseq -l left.fq -g mm10 -P -T -o output_dir -p output_preifx -R -m
# paired-end ChIPseq
piSet_chipseq -l left.fq -r right.fq -g mm10 -P -T -o output_dir -p output_preifx -R -m
# paired-end CUT_and_RUN
piSet_chipseq -l left.fq -r right.fq -g mm10 -P -T -o output_dir -p output_preifx -m
```
Tips1: -P and -T enable analysis of piclusters and transposons while -m enables peak calling via MACS2 and -R enables duplicates remving via samtools rmdup.  
Tips2: When running pipeline for CUT_and_RUN data, it is almost the same to ChIPseq data. But just keep in mind that it is better not set -R to disable PRC duplicates removing cause CUT_and_RUN will get many reads from one exactly site.

Also, piSet_chipseq accept multiple samples like RNAseq, with sample_information.tab:
```
piSet_chipseq -l "mouse_wt_chip_rep1.1.fq mouse_wt_chip_rep2.1.fq mouse_mnkMut_amyb_chip_rep1.fq"
```
