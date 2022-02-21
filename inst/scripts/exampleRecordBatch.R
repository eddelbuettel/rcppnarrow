
## little demo note, tucked away to not inflate dependencies

## start with the penguins
pp <- palmerpenguins::penguins

## make a narrow array
na <- as_narrow_array(pp)
print(na)

## turn it easily in an Arrow RecordBatch type
from_narrow_array(na, ptype=arrow::RecordBatch)

## and something else from there
tibble::as_tibble( from_narrow_array(na, ptype=arrow::RecordBatch) )
