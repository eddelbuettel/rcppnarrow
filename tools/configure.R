
haveNarrow <- function() {
    if (isFALSE(requireNamespace("narrow", quietly=TRUE)))
        return(FALSE)
    if (packageVersion("narrow") < "0.0.1.20220215")
        return(FALSE)
    return(TRUE)
}

flag <- ifelse(haveNarrow(), paste0("-I", system.file("include", package="narrow"), " -DHAVE_NARROW"), "")

txt <- readLines("src/Makevars.in")
txt <- gsub("@NARROW@", flag, txt)
con <- file("src/Makevars", "wb")       # to ensure we get unix line ends and no warning ...
writeLines(txt, con, sep="\n")
close(con)
