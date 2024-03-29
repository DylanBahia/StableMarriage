post_process <- function(matching,dict){
  match_mat <- do.call(rbind,matching)
  for(i in nrow(match_mat)){
    for(j in ncol(match_mat)){
      match_mat[i,j] <- dict[dict[,1]==match_mat[i,j]][2]
    }
  }
  
  colnames(match_mat) <- c("Man","Woman")
  rownames(match_mat) <- rep("",nrow(match_mat))
  
  return(match_mat)
}

pre_process <- function(men,women){
  w_names <- men[[1]][-1]
  m_names <- women[[1]][-1]
  n <- length(w_names)
  
  dict <- cbind(seq(1,2*n),c(m_names,w_names))
  
  for(i in 1:n){
    for(j in 1:n){
      men[[i]][j] <- as.integer(dict[dict[,2]==men[[i]][j]][1])
      women[[i]][j] <- as.integer(dict[dict[,2]==women[[i]][j]][1])
    }
  }
  return(list(men=men,women=women,dict=dict))
}
