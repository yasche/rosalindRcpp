#include <Rcpp.h>
using namespace Rcpp;

//' Solution for Problem "Counting DNA Nucleotides"
//'
//' @description
//' Counts DNA nucleotides in sequence `s` and returns the number of A, C, G and T in that order. Letters other than A, C, G and T will be ignored.
//'
//' @param s A string holding the sequence.
//'
//' @return A vector with the number of A, C, G and T in that order.
//' @export
// [[Rcpp::export]]
IntegerVector dna(std::string s)
{
  int n_a { 0 };
  int n_c { 0 };
  int n_g { 0 };
  int n_t { 0 };

  std::string non_nucl { "" };

  for(std::string::size_type i = 0; i < s.size(); ++i)
  {
    if (s[i] == 'A') {
      n_a = n_a + 1;
    } else if (s[i] == 'T') {
      n_t = n_t + 1;
    } else if (s[i] == 'G') {
      n_g = n_g + 1;
    } else if (s[i] == 'C') {
      n_c = n_c + 1;
    } else {
      non_nucl += s[i];
    }
  }

  if (non_nucl != "") {
    std::string warning_message = {"The sequence `s` contains the following letters that do not correspond to a nucleotide: "};
    warning_message += non_nucl;
    warning(warning_message);
  }

  IntegerVector return_vec = {n_a, n_c, n_g, n_t};

  return return_vec;
}
