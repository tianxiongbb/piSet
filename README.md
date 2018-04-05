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
After installing genome, running pipeline for s

