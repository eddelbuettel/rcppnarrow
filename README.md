
## RcppArrow: Light(er)weight Arrow Data Structure Interface

[![CI](https://github.com/eddelbuettel/rcpparrow/actions/workflows/ci.yaml/badge.svg)](https://github.com/eddelbuettel/rcpparrow/actions/workflows/ci.yaml)
[![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](https://www.gnu.org/licenses/gpl-2.0.html)
[![Last Commit](https://img.shields.io/github/last-commit/eddelbuettel/rcpparrow)](https://github.com/eddelbuettel/rcpparrow)

### What and Why

The [arrow](https://cloud.r-project.org/package=arrow) package is featureful but can be a little challenging to install (from source, on Linux, for CI, ...).
The [narrow](https://github.com/paleolimbot/narrow) package (also named at earlier times, respectively, `arrowctrs`, `carrow` and `sparrow`) provides a very clean and dependency-free interface for (portable) C interface of Arrow.
Our [fork of narrow](https://github.com/eddelbuettel/narrow) adds support for C-level access from another package---which is what we test and demonstrate here.

### What

Because neither [narrow](https://github.com/paleolimbot/narrow) nor our [fork of
narrow](https://github.com/eddelbuettel/narrow) are on CRAN, the packages uses the fork via
`Suggests:` which would normally prevent compile-time access---but we use the same approach of
detecting in `configure` if `narrow` is present and if so enabling the extended build.

### Who

Dirk Eddelbuettel

### Licence

GPL (>= 2)
