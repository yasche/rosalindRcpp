#include <Rcpp.h>
#include "tripl_to_aa.h"
using namespace Rcpp;

// [[Rcpp::export]]
String prot(std::string s)
{
  String protein_string { };
  int triplet_position { 0 };
  std::string curr_triplet { "" };
  String curr_aa { };

  for (std::string::size_type i = 0; i < s.size(); ++i) {
    curr_triplet += s[i];
    triplet_position += 1;

    if (triplet_position == 3) {
      curr_aa = triplet_to_aa(curr_triplet);
      if (curr_aa == "Stop") {
        break;
      } else {
        protein_string += curr_aa;
        triplet_position = 0;
        curr_triplet = "";
      }
    }
  }

  return protein_string;
}
