#include <Rcpp.h>
using namespace Rcpp;

//' Return "Hello world" as a string
//'
//' @description
//' This is only a test.
//'
//' @return A string containing "Hello world"
//' @export
// [[Rcpp::export]]
String hello_world()
{
  String s("Hello world");
  return s;
}
