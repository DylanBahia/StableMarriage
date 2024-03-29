# Functionality of package
This package implements the Fundamental Algorithm for solving the Stable Marriage Problem. Given two preference tables, it outputs a stable matching. 

# How to install

1) Install the 'devtools' package.
2) Load the 'devtools' package into the environment.
3) Run the following line of code: devtools::install_github("DylanBahia/StableMarriage",force=T)

# How to use
In order to get a stable matching, you need to use the 'sm' function. As it's inputs it requires the two preference table. Each preference table must be represented by a list of vectors. Each vector in the list represents an individual and their ordered preferences. The first element of the vector is the name of the individual and the elements which follow are their ordered preferences. The names of the individuals can be of either numeric or string types, and the names of individuals need not be of the same type. For example, suppose you have the following preference table:

| Man | 1st preference | 2nd preference | 3rd preference |
| ----| ---| --- | ---|
| 1 | 4 | 5|6|
| 2 | 5 |6|4|
| 3 | 6 |5|4|
