library(Rcpp)
loadModule("fundamental",TRUE)

sm <- function(men,women){
  print(men)
  name_change <- pre_process(men,women)
  men <- name_change$men
  women <- name_change$women
  dict <- name_change$dict
  print(men)
  return(post_process(stable_marriage(men,women),dict))
}

