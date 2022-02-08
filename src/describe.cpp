#include <Rcpp/Lightest>
#include "narrow.h"

// A narrow_schema() is an external pointer to a struct ArrowSchema, a
// narrow_array_data() is an external pointer to a struct ArrowArray,
// and a narrow_array() is a list() of a narrow_schema() and a
// narrow_array_data().

//' Describe An Arrow Schema
//'
//' @param ptr An external pointer object for an \code{ArrowSchema} structure
//' @return None. The function is invoked for the side effect of display schema info.
// [[Rcpp::export]]
void describeArrowSchema(Rcpp::XPtr<ArrowSchema> ptr) {
    struct ArrowSchema* schema = schema_from_xptr(ptr, "");
    Rcpp::Rcout << "Format  : " << schema->format << "\n"
                << "Name    : " << schema->name  << "\n"
      // a list in R            << "Metadata: " << schema->metadata  << "\n"
                << "Flags   : " << schema->flags  << "\n"
                << "Children: " << schema->n_children << "\n";
}

//' Describe An Arrow Array
//'
//' @param ptr An external pointer object for an \code{ArrowArray} structure
//' @return None. The function is invoked for the side effect of display schema info.
// [[Rcpp::export]]
void describeArrowArray(Rcpp::XPtr<ArrowArray> ptr) {
    struct ArrowArray* array = array_data_from_xptr(ptr, "");
    Rcpp::Rcout << "Length  : " << array->length << "\n"
                << "Nulls   : " << array->null_count << "\n"
                << "Offset  : " << array->offset << "\n"
                << "Buffers : " << array->n_buffers << "\n"
                << "Children: " << array->n_children << "\n";
}
