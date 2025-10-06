#include <Rcpp.h>
using namespace Rcpp;

//' Solution for Problem "Counting Point Mutations"
//'
//' @description
//' Calculates the Hamming distance dH(s,t) of DNA strings s and t (i.e., the number of point mutations).
//'
//' @param s A DNA sequence as a string.
//' @param t A DNA sequence as a string.
//'
//' @return The number of point mutations.
//' @export
// [[Rcpp::export]]
int hamm(std::string s, std::string t)
{
  int n_mut { 0 };

  if (s.size() != t.size()) {
    stop("Arguments `s` and `t` differ in their length.");
  }

  for(std::string::size_type i = 0; i < s.size(); ++i) {
    if (s[i] != t[i]) {
      n_mut = n_mut + 1;
    }
  }

  return n_mut;
}
