library(Rcpp)
loadModule("fundamental",TRUE)

sm <- function(men,women){
  stuff <- stable_marriage(men,women)
  print("A")
  return(stuff)
}

