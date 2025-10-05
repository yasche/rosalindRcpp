#include <Rcpp.h>
#include <fstream>
using namespace Rcpp;

//' A simple FASTA-parser, implemented in C++
//'
//' @description
//' Parses a FASTA file and returns the content as a named list.
//'
//' @param file_path The path of a FASTA file.
//'
//' @return A named list with the contents of the FASTA file.
//' @export
// [[Rcpp::export]]
List parse_fasta(std::string file_path)
{
  std::string line;

  // create an empty vector to store sequences in
  List sequences {};

  std::string curr_name {""};
  std::string curr_sequence {""};

  std::ifstream myfile (file_path);
  if (myfile.is_open())
  {
    while ( getline (myfile, line) )
    {
      if (line.front() == '>')
      {
        // save last sequence & name to map
        sequences[curr_name] = curr_sequence;
        curr_sequence = "";
        curr_name = line;
        curr_name.erase(0, 1);
      } else {
        curr_sequence.append(line);
      }
    }
    // save final sequence & name to map
    sequences[curr_name] = curr_sequence;

    myfile.close();
  } else {
    stop("Can't open fasta file!");
  }

  sequences.erase(sequences.begin());

  return sequences;
}
