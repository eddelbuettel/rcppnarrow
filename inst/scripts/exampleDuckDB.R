## little demo note, tucked away to not inflate dependencies

## start with the penguins
pp <- palmerpenguins::penguins

## make a narrow array
na <- as_narrow_array(pp)
# print(na) # -- 'narrow' type with Arrow schema and data

## turn it easily in an Arrow RecordBatch type
arr <- from_narrow_array(na, ptype=arrow::RecordBatch)
# now a proper Arrow RecordBatch

## so let's get a database connection to DuckDB
con <- DBI::dbConnect(duckdb::duckdb())

## and register the 'arr' arrow object as a DuckDB view
tbl <- arrow::to_duckdb(arr, table_name = "arrow_table", con = con)

## to run DuckDB SQL query
result <- DBI::dbGetQuery(con, "SELECT * FROM arrow_table where bill_length_mm > 50")
dim(result) # 52 from the original 344

DBI::dbDisconnect(con)
