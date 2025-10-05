#include <Rcpp.h>
using namespace Rcpp;

//' Solution for Problem "Rabbits and Recurrence Relations"
//'
//' @description
//' Calculates the number of rabbit pairs after n months.
//'
//' @param n The number of months as an integer.
//' @param k The number of rabbit pairs as an integer.
//'
//' @return The number of rabbit pairs after n months.
//' @export
// [[Rcpp::export]]
long long int fib(int n, int k)
{
  long long int small_rabbits { 1 };
  long long int large_rabbits { 0 };
  long long int small_rabbits_new { 0 };

  for (int i = 0; i < n - 1; i = i + 1) {
    small_rabbits_new = large_rabbits * k;
    large_rabbits = large_rabbits + small_rabbits;
    small_rabbits = small_rabbits_new;
  }
  return small_rabbits + large_rabbits;
}
