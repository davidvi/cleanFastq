//David van IJzendoorn, 2017
//clang++ -std=c++0x fixFastq.cpp -o fixFastq && ./fixFastq
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
using namespace std;

int main(int argc, char* argv[]) {
  //declare variables
  cout << "infile = " << argv[1] << endl << "outfile = " << argv[2] << endl;
  ifstream infileFastq(argv[1]); //L4052-N_R2.fastq
  ofstream outfileFastq(argv[2]);
  string lineFastq;

  //loop through file and save good reads
  int i = 0;
  string identifier;
  string sequence;
  string sep;
  string quality;
  while(getline(infileFastq, lineFastq)){
    switch(i) {
      case 0:
        identifier = lineFastq;
        break;
      case 1:
        sequence = lineFastq;
        break;
      case 2:
        sep = lineFastq;
        break;
      case 3:
        quality = lineFastq;
        if(regex_match(sequence, regex("[CGATNcgatn]*")) && boost::starts_with(identifier, "@") && boost::starts_with(sep, "+") && quality.length() > 0) {
          outfileFastq << identifier << endl;
          outfileFastq << sequence << endl;
          outfileFastq << sep << endl;
          outfileFastq << quality << endl;
        }
        break;
      default:
        break;
    }
    if(i < 3) {
      i++;
    } else {
      i = 0;
    }
  }

  outfileFastq.close();
  return 0;
}
