library(Rcpp)
loadModule("fundamental",TRUE)

post_process <- function(matching){
  match_mat <- do.call(rbind,matching)
  colnames(match_mat) <- c("Man","Woman")
  rownames(match_mat) <- rep("",nrow(match_mat))
  return(match_mat)
}
sm <- function(men,women){
  stuff <- post_process(stable_marriage(men,women))
  print("A")
  return(stuff)
}

