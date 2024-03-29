#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <list>
#include "is_stable_funs.h"
#include "fund_alg_funs.h"
#include "marshall.h"

#include "Rcpp.h"
using namespace Rcpp;

std::vector<std::vector<int>> fund_alg_r(std::list<std::vector<int>>,
					 std::list<std::vector<int>>);
