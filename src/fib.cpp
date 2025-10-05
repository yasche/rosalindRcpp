#include <Rcpp.h>
using namespace Rcpp;

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
