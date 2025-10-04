#include <Rcpp.h>
using namespace Rcpp;

//' Combine "Hello world" and `your_name` and return it as a string
//'
//' @description
//' This is only a test.
//'
//' @param your_name Your name
//'
//' @return A string containing "Hello world", combined with your name
//' @export
// [[Rcpp::export]]
String hello_world(String your_name)
{
  String s("Hello world, ");
  s += your_name;
  return s;
}
