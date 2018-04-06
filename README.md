# piSet: a set of pipeline for piRNA analysis

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
Once you have installed piSet, you need to install the download or make all the genome annotation needed in the pipeline. Simply typing: `piSet_install_genome` to get help information.  

To install mouse mm10 genome, run:
```
piSet_install_genome -g mm10 -s "Mus musculus" -c 16  
```
piSet will automaticlly download the latest version of a genome, to install genome in lower version like mm9, run:
```
piSet_install_genome -g mm10 -s "Mus musculus" -c 16 -T "http://www.repeatmasker.org/genomes/mm9/RepeatMasker-rm328-db20090604/mm9.fa.out.gz"
```
tips: -T provides rmsk.url for downloading repeat element annotation in different genome version. The url can be found in [RepeatMasker Website](http://www.repeatmasker.org/genomicDatasets/RMGenomicDatasets.html)  

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
After installing genome, running pipeline is quite easy. For smallRNAseq data for mouse mm10, simply run:
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
6. bed2_summary/XXX.cov files which store the normalized signal across the while body of each piclusters and transposons.
7. **bed2_summary/XXX.cov** files which store all the information like uniq/all mapped sense/antisense reads/species for each piclusters, transposons, genes and other noncoding genes. Also, ping-pong zscore and pairs are available for piclusters and transposons. These files is very useful if you want to get detailed information of some piclusters, transposons or genes. Or if you want to make a systematic figures yourselves.
8. figures/XXX.scatter.pdf files are final results which compare all the samples 1-to-1 by scatter plot.
9. figures/XXX.pdf files are final results which use length distribution, ping-pong and buckets to get more detailed comparison of all the samples.  

---
## 4. rnaseq pipeline
