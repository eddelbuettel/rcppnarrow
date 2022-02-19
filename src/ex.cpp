#include <Rcpp/Lightest>
#if defined(HAVE_NARROW)
#include <narrow.h>
#endif

//' Count Null Elements in Arrow Object
//'
//' @param array_data_xptr An external pointer to an Arrow object
//' @return The number of null elements
//' @examples
//' extract_null_count(narrow::as_narrow_array(c(NA, NA, 1:5))$array_data)
// [[Rcpp::export]]
SEXP extract_null_count(SEXP array_data_xptr) {
#if defined(HAVE_NARROW)
    struct ArrowArray* array_data = (struct ArrowArray*) R_ExternalPtrAddr(array_data_xptr);
    return Rf_ScalarInteger(array_data->null_count);
#else
    message("Functionality unavailable. Rebuild the package with 'narrow' present.");
    return R_NaInt;
#endif
}
