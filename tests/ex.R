
library(RcppArrow)

if (requireNamespace("narrow", quietly=TRUE)) {
    stopifnot( extract_null_count( narrow::as_narrow_array(c(NA, NA, 1:5))$array_data ) == 2)
}
