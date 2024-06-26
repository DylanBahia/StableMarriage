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

// [[Rcpp::plugins("cpp17")]]

//marshalls the inputs and runs the fundamental algorithm.
std::vector<std::vector<int>> fund_alg_r(std::list<std::vector<int>> men,
					 std::list<std::vector<int>> women)
{
	//converts men's preference table into unordered_map.
	std::unordered_map<int,std::vector<int>> men_map {marshall(men)};
	//converts women's preference table into unordered_map.
	std::unordered_map<int,std::vector<int>> women_map {marshall(women)};
	
	//returns result of fundamental algorithm.
	return fund_alg(men_map,women_map);
}


RCPP_MODULE(fundamental){
	function("stable_marriage",&fund_alg_r);
}
