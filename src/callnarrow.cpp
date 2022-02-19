
// quick litmus test to access an exported C function

#include <Rcpp/Lightest>
#if defined(HAVE_NARROW)
#include <narrow.h>
#include <narrowAPI.h>
#endif

//' Call array info
//'
//' @param adxpt An external pointer to array data object
//' @return A list with array info
//' @examples
//' if (requireNamespace("narrow", quietly=TRUE) {
//'     x <- narrow::as_narrow_array(c(NA, 2, NA, 4:7))
//'     narrow_array_info(x$array_data)
//' }
// [[Rcpp::export]]
SEXP narrow_array_info(SEXP adptr) {
#if defined(HAVE_NARROW)
    return(narrow_c_array_info(adptr));
#else
    return(R_NilValue)
#endif
}
