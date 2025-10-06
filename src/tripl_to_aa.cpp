#include <Rcpp.h>
#include "misc.h"
using namespace Rcpp;

// [[Rcpp::export]]
String triplet_to_aa(std::string triplet)
{
  auto it = aa_lookup.find(triplet);
  if (it != aa_lookup.end()) {
    return it->second;
  } else {
    return NA_STRING;
  }
}
