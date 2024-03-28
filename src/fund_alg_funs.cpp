#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include "is_stable_funs.h"

//given two preference tables, returns a matching as produced by the fundamental algorithm.	
std::vector<std::vector<int>> fund_alg(std::unordered_map<int,std::vector<int>> men,
					std::unordered_map<int,std::vector<int>> women){
	
	//creates new name which will represent the undersirable imaginary man.
	std::vector<int> m_names {women.begin()->second};				
	int max {*std::max_element(m_names.begin(),m_names.end())};
	int imag_man {max+1};
	//adds imaginary man to the end of each woman's preference list.
	for(auto& i: women){
		i.second.push_back(imag_man);
	} 
	
	//number of men/women.
	int n {m_names.size()};
	
	//initially marries each woman to the imaginary man.
	std::vector<std::vector<int>> matching(n,std::vector<int>(2,imag_man));
	std::vector<int> w_names {men.begin()->second};
	for(int i=0; i<n; i++){
		matching[i][1] = w_names[i];
	}
	
	//fundamental algorithm.
	for(int k=0; k<n; k++){
		//(k+1)-st man.
		int x_m {m_names[k]};
		while(x_m != imag_man){
			//best remaining choice on x_m's list.
			std::vector<int> x_m_prefs {men.at(x_m)};
			int x_w {x_m_prefs[0]};
			
			//finds current partner of x_w.
			int curr_partner;
			for(const std::vector<int>& marriage: matching){
				if(x_w==marriage[1]){curr_partner=marriage[0];}
			}
			
			//gets preference lists of x_w.
			std::vector<int> x_w_prefs {women.at(x_w)};
			
			
			
			//if x_w prefers x_m to current partner, engage x_w to x_m, and set x_m to prior partner of x_w.
			int x_m_index {index(x_w_prefs,x_m)};
			int curr_index {index(x_w_prefs,curr_partner)};
			if(x_m_index<curr_index){
				for(const std::vector<int>& marriage: matching){
					if(x_w==marriage[1]){
						matching.erase(std::remove(matching.begin(),matching.end(),marriage),matching.end());
						std::vector<int> new_marriage {{x_m,x_w}};
						matching.push_back(new_marriage);
					}				
				}
				x_m = curr_partner;
			}
			
			
			//if x_m is not the imaginary man, remove x_w from the preference list of x_m.
			if(x_m != imag_man){
				x_m_prefs = men.at(x_m);
				x_m_prefs.erase(x_m_prefs.begin());
				men[x_m] = x_m_prefs;
			}
		} 
	}
	
	return matching;	
}
