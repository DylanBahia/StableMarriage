library(Rcpp)
loadModule("fundamental",TRUE)

sm <- function(men,women){
  return(stable_marriage(men,women))
}
