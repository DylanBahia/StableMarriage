library(Rcpp)
loadModule("fundamental",TRUE)

sm <- function(men,women){
  stuff <- post_process(stable_marriage(men,women))
  return(stuff)
}

