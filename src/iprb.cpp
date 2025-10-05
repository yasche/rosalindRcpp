#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double iprb(double k, double m, double n)
{
  double summed_pop { };
  double prob { };
  summed_pop = k + m + n;

  prob = (1 * n/summed_pop * (n - 1) / (summed_pop - 1)) + (0.5 * n/summed_pop * (m) / (summed_pop - 1)) + (0.5 * m/summed_pop * (n) / (summed_pop - 1)) + (0.25 * m/summed_pop * (m - 1) / (summed_pop - 1));

  return 1 - prob;
}
