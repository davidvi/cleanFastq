## fixFastq
Fix broken fastq files with corrupted reads that crash the aligner.

### Installation
build with clang++ or g++ parsing the -std=c++0x flag to use c++11:
```
clang++ -std=c++0x fixFastq.cpp -o fixFastq
```

### Run
```
./fixFastq infile.fastq outfile.fastq 
```
