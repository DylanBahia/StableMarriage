library(Rcpp)
loadModule("fundamental",TRUE)

sm <- function(men,women){
  print(men)
  name_change <- pre_process(men,women)
  men <- name_change[1]
  women <- name_change[2]
  dict <- name_change[3]
  print(men)
  return(post_process(stable_marriage(men,women),dict))
}

