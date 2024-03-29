library(Rcpp)
loadModule("fundamental",TRUE)

sm <- function(men,women){
  print("A")
  return(post_process(stable_marriage(men,women)))
}

