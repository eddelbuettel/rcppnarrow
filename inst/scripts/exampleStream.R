
## stream example from the narrow README.md

example_readr <- function() {
    csv_file <- readr::readr_example("mtcars.csv")
    counter <- -1
    rows_per_chunk <- 5

    schema <- as_narrow_array(readr::read_csv(csv_file, n_max = 0,
                                              col_types = readr::cols(.default = readr::col_double())))$schema

    stream2 <- narrow_array_stream_function(schema, function() {
        counter <<- counter + 1L
        result <- readr::read_csv(csv_file,
                                  skip = 1 + (counter * rows_per_chunk),
                                  n_max = rows_per_chunk,
                                  col_names = c("mpg", "cyl", "disp", "hp", "drat",
                                                "wt", "qsec", "vs", "am", "gear", "carb"),
                                  col_types = readr::cols(.default = readr::col_double()))
        print(result)
        if (nrow(result) > 0) result else NULL
    })

    reader <- narrow_array_stream_to_arrow(stream2)

    as.data.frame(reader$read_table())
}


example_readr()
