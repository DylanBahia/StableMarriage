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
    man <- rep(0,n+1)
    woman <- rep(0,n+1)
    for(j in 1:(n+1)){
      man[j] <- as.integer(dict[dict[,2]==men[[i]][j]][1])
      woman[j] <- as.integer(dict[dict[,2]==women[[i]][j]][1])
    }
    men[[i]] <- man
    women[[i]] <- woman
  }
  return(list(men=men,women=women,dict=dict))
}
