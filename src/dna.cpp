#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector dna(std::string s)
{
  int n_a = { 0 };
  int n_c = { 0 };
  int n_g = { 0 };
  int n_t = { 0 };

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
    }
  }
  IntegerVector return_vec = {n_a, n_c, n_g, n_t};

  return return_vec;
}
