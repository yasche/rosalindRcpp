#include <Rcpp.h>
using namespace Rcpp;

//' Solution for Problem "Transcribing DNA into RNA"
//'
//' @description
//' Replaces each T with an U.
//'
//' @param t A string holding the sequence.
//'
//' @return A string where each T has been replaced with an U.
//' @export
// [[Rcpp::export]]
std::string rna(std::string t)
{
  std::string rna_str { "" };

  for(std::string::size_type i = 0; i < t.size(); ++i)
    {
    if (t[i] == 'T') {
      rna_str += 'U';
    } else {
      rna_str += t[i];
    }
  }

  return rna_str;
}
