#include <Rcpp/Lightest>
#include "narrow.h"

//' Count Null Elements in Arrow Object
//'
//' @param array_data_xptr An external pointer to an Arrow object
//' @return The number of null elements
//' @examples
//' extract_null_count(narrow::as_narrow_array(c(NA, NA, 1:5))$array_data)
// [[Rcpp::export]]
SEXP extract_null_count(SEXP array_data_xptr) {
    struct ArrowArray* array_data = (struct ArrowArray*) R_ExternalPtrAddr(array_data_xptr);
    return Rf_ScalarInteger(array_data->null_count);
}
