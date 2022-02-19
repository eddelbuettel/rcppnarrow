#include <Rcpp/Lightest>
#if defined(HAVE_NARROW)
#include <narrow.h>
#else
#include <arrow_c_api.h>
#endif

// A narrow_schema() is an external pointer to a struct ArrowSchema, a
// narrow_array_data() is an external pointer to a struct ArrowArray,
// and a narrow_array() is a list() of a narrow_schema() and a
// narrow_array_data().

//' Describe An Arrow Schema
//'
//' @param ptr An external pointer object for an \code{ArrowSchema} structure
//' @return None. The function is invoked for the side effect of displaying the
//' schema info.
// [[Rcpp::export]]
void describeArrowSchema(Rcpp::XPtr<ArrowSchema> ptr) {
#if defined(HAVE_NARROW)
    struct ArrowSchema* schema = schema_from_xptr(ptr, "");
    Rcpp::Rcout << "Format  : " << schema->format << "\n"
                << "Name    : " << schema->name  << "\n"
      // a list in R            << "Metadata: " << schema->metadata  << "\n"
                << "Flags   : " << schema->flags  << "\n"
                << "Children: " << schema->n_children << "\n";
#else
    Rcpp::Rcout << "Functionality unavailable. Rebuild the package with 'narrow' present.\n";
#endif
}

//' Describe An Arrow Array
//'
//' @param ptr An external pointer object for an \code{ArrowArray} structure
//' @return None. The function is invoked for the side effect of displaingy some
//' array info.
// [[Rcpp::export]]
void describeArrowArray(Rcpp::XPtr<ArrowArray> ptr) {
#if defined(HAVE_NARROW)
    struct ArrowArray* array = array_data_from_xptr(ptr, "");
    Rcpp::Rcout << "Length  : " << array->length << "\n"
                << "Nulls   : " << array->null_count << "\n"
                << "Offset  : " << array->offset << "\n"
                << "Buffers : " << array->n_buffers << "\n"
                << "Children: " << array->n_children << "\n";
#else
    Rcpp::Rcout << "Functionality unavailable. Rebuild the package with 'narrow' present.\n";
#endif
}


//' Print uint64_t vector
//'
//' @param ptr An external pointer object for an \code{uint64_t} vector
//' @return None. The function is invoked for the side effect of display schema info.
// [[Rcpp::export]]
void print_uint64(Rcpp::XPtr<ArrowArray> ptr) {
#if defined(HAVE_NARROW)
    struct ArrowArray* array = array_data_from_xptr(ptr, "");
    const uint64_t *data = reinterpret_cast<const uint64_t*>(array->buffers[1]);
    for (int64_t i = 0; i < array->length; i++) {
        Rprintf("%llu\n", data[i]);
    }
#else
    Rcpp::Rcout << "Functionality unavailable. Rebuild the package with 'narrow' present.\n";
#endif
}

#if 0
// r -lRcppArrow,arrow,narrow
//   -e'v <- arrow::Array$create(1:5)$cast(arrow::uint64());
//      print(v);
//      n <- as_narrow_array(v, schema=narrow_schema("L"));
//      print(n);
//      print_uint64(n$array_data)'
#endif
