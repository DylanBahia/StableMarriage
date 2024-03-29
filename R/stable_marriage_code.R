library(Rcpp)
loadModule("fundamental",TRUE)

#finds a stable matching given a pair of preference tables.
sm <- function(men,women){
  name_change <- pre_process(men,women)
  men <- name_change$men
  women <- name_change$women
  dict <- name_change$dict
  return(post_process(stable_marriage(men,women),dict))
}

