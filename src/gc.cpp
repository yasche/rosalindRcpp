#include <Rcpp.h>
#include "parse_fasta.h"
#include "dna.h"
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector gc(std::string file_path)
{
  List sequences = parse_fasta(file_path);
  CharacterVector sequence_names = sequences.names();

  double highest { -1.0 };
  std::string highest_name { };
  double curr_g_c_frac { };
  double curr_g_c { };
  double curr_total_nuc { };
  IntegerVector curr_vec { };

  for (int i = 0; i < sequences.size(); ++i) {
    curr_vec = dna(sequences[i]);

    // the vector returned from dna() holds n_c at position 1 and n_g at position 2
    curr_g_c = curr_vec[1] + curr_vec[2];
    curr_total_nuc = curr_vec[0] + curr_vec[1] + curr_vec[2] + curr_vec[3];
    curr_g_c_frac = curr_g_c * 100 / curr_total_nuc;
    if (curr_g_c_frac > highest) {
      highest = curr_g_c_frac;
      highest_name = sequence_names[i];
    }

  }

  NumericVector highest_v = NumericVector::create(Named(highest_name, highest));
  return highest_v;
}
