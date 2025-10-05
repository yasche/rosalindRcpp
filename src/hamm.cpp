#include <Rcpp.h>
using namespace Rcpp;

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
