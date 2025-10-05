#include <Rcpp.h>
using namespace Rcpp;

//' Solution for Problem "Complementing a Strand of DNA"
//'
//' @description
//' Reverses the sequence `s` and replaces each nucleotide with the complement (i.e., A<->T and G<->C). Non-nucleotide letters will be ignored.
//'
//' @param s A string holding the sequence.
//'
//' @return The complement, sc, of string s.
//' @export
// [[Rcpp::export]]
std::string revc(std::string s)
{
  std::string rev_s { "" };
  rev_s = s;
  std::reverse(rev_s.begin(), rev_s.end());

  std::string complement_s {};

  std::string non_nucl = { "" };

  for (std::string::size_type i = 0; i < rev_s.size(); ++i) {
    if (rev_s[i] == 'A') {
      complement_s += 'T';
    } else if (rev_s[i] == 'T') {
      complement_s += 'A';
    } else if (rev_s[i] == 'G') {
      complement_s += 'C';
    } else if (rev_s[i] == 'C'){
      complement_s += 'G';
    } else {
      non_nucl += rev_s[i];
    }
  }

  if (non_nucl != "") {
    std::string warning_message = {"The sequence `s` contains the following letters that do not correspond to a nucleotide: "};
    warning_message += non_nucl;
    warning(warning_message);
  }

  return complement_s;
}
