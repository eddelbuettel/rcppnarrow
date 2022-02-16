
// quick litmus test to access an exported C function

#include <Rcpp/Lightest>
#include <narrow.h>
#include <narrowAPI.h>

//' Call array info
//'
//' @param adxpt An external pointer to array data object
//' @return A list with array info
//' @examples
//' x <- narrow::as_narrow_array(c(NA, 2, NA, 4:7))
//' narrow_array_info(x$array_data)
// [[Rcpp::export]]
SEXP narrow_array_info(SEXP adptr) {
    return(narrow_c_array_info(adptr));
}
