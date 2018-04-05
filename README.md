# piSet: a set of pipeline for piRNA analysis

---
## 1. installation
piSet is based on a bunch of software, most of the dependencies is pre-installed but three of them still need to be installed by users:  
1). [Htseq](https://htseq.readthedocs.io/en/release_0.9.1/) 2). [miRDeep2](https://github.com/rajewsky-lab/mirdeep2) 3). [cutadapt](http://cutadapt.readthedocs.io/en/stable/guide.html)   
You can use miniconda for easy install.  
To get [miniconda](https://conda.io/miniconda.html "miniconda"), run:  
```
wget https://repo.continuum.io/miniconda/Miniconda2-latest-Linux-x86_64.sh  
bash ./Miniconda2-latest-Linux-x86_64.sh 
conda config --add channels defaults  
conda config --add channels conda-forge  
conda config --add channels bioconda
```

After installing miniconda, typing commands below to install dependencies:
```
conda install htseq=0.9.1   
conda install mirdeep2=2.0.0.8  
conda install cutadapt=
