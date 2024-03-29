source("data_processing.R")
library(Rcpp)
loadModule("fundamental",TRUE)

sm <- function(men,women){
  return(post_process(stable_marriage(men,women)))
}

