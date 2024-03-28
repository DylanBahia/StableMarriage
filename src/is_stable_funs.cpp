#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>


//finds index of element 'element' in vector 'vec'.
int index(const std::vector<int>& vec, const int& element){
	int index {std::distance(vec.begin(),std::find(vec.begin(),vec.end(),element))};
	return index;
}
//checks if given matching is stable using given preference tables.
bool is_stable(const std::unordered_map<int,std::vector<int>>& men,
	      const std::unordered_map<int,std::vector<int>>& women,
	      const std::vector<std::vector<int>>& matching){
	//iterates over each matching.
	for(const std::vector<int>& marriage: matching){
		//man in marriage being considered.
		int man{marriage[0]};
		//woman in marriage being considered.
		int woman{marriage[1]};
		//list of preferences of man.
		std::vector<int> full_m_prefs {men.at(man)};
		
		//list of women that man prefers to current partner.
		int w_index {index(full_m_prefs,woman)};
		std::vector<int> m_preferences {full_m_prefs.begin(),full_m_prefs.begin()+w_index};
		
		//iterates over prospective women that the man would prefer to marry.
		for(const int& pros_woman: m_preferences){
			//finds partner of prospective woman.
			int curr_partner;
			for(const std::vector<int>& marriage: matching){
				if(pros_woman==marriage[1]){curr_partner=marriage[0];}
			}
			//gets preference lists of prospective woman.
			std::vector<int> w_prefs {women.at(pros_woman)};
			
			//if prospective woman prefers man to current partner, the matching is unstable.
			int man_index {index(w_prefs,man)};
			int curr_index {index(w_prefs,curr_partner)};
			if(man_index<curr_index){
				return false;
			}
		}
	}
	//if all marriages are stable then the matching is stable.
	return true;
}
