## fixFastq
Fix broken fastq files with corrupted reads that crash the aligner.

### Installation
build with clang++ or g++ parsing the -std=c++0x flag to use c++11:
```
g++ -std=c++11 fixFastq.cpp -o fixFastq
```

### Run
```
./fixFastq infile.fastq outfile.fastq
```

### Errors
If there is an error running fixFastq you may need to upgrade your compiler or remove the regular expression from the cpp file: 
```
 regex_match(sequence, regex("[CGATNcgatn]*")) &&
 ```
