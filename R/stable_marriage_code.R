library(Rcpp)
loadModule(fundamental)

sm <- function(men,women){
  return(stable_marriage(men,women))
}

