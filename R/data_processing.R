#converts c++ output into a matrix and 
#maps the integer names back to original names
post_process <- function(matching,dict){
  
  match_mat <- matrix(nrow=length(matching),ncol=2)
  for(i in 1:length(matching)){
    for(j in 1:ncol(match_mat)){
      match_mat[i,j] <- dict[dict[,1]==matching[[i]][j]][2]
    }
  }
  
  colnames(match_mat) <- c("Man","Woman")
  rownames(match_mat) <- rep("",nrow(match_mat))
  
  return(match_mat)
}

#if preference tables are given in files, they are extracted.
#the preference tables are then augmented to use integer names.
pre_process <- function(men,women,file){
  if(file = TRUE){
    men_dat <- readLines(men)
    women_dat <- readLines(women)
    
    men <- list()
    women <- list()
    for(i in 1:length(men_dat)){
      men[[i]] <- strsplit(men_dat[i])[[1]]
      women[[i]] <- strsplit(women_dat[i])[[1]]
    }
  }
  return(mapping(men,women))
}

#replaces names of people with integer names
mapping <- function(men,women){
  
  #finds all the names of people.
  w_names <- men[[1]][-1]
  m_names <- women[[1]][-1]
  n <- length(w_names)
  
  #maps each name to a unique integer to ensure
  #integer names are used.
  dict <- cbind(seq(1,2*n),c(m_names,w_names))
  
  #replaces all names in the preference tables
  #with integer names according to the mapping.
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
  
  #returns the preference table with integer names,
  #along with the mapping so this can be reversed
  #in post-processing.
  return(list(men=men,women=women,dict=dict))
}
