library(Rcpp)
loadModule("fundamental",TRUE)

sm <- function(men,women){
  name_change <- pre_process(men,women)
  men <- name_change[1]
  women <- name_change[2]
  dict <- name_change[3]
  return(post_process(stable_marriage(men,women),dict))
}

