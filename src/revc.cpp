#include <Rcpp.h>
using namespace Rcpp;

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
