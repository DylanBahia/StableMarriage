library(Rcpp)
loadModule("fundamental",TRUE)

sm <- function(men,women){
  return(post_process(stable_marriage(men,women)))
}

