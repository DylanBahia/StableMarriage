#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <list>

// converts a list of vectors into an unordered map, where the first element of a vector
// is a key and the following elements comprise the value.
std::unordered_map<int,std::vector<int>> marshall(std::list<std::vector<int>> table)
{
	std::unordered_map<int,std::vector<int>> table_map;
	
	for(auto& person:table)
	{
		std::vector<int> prefs;
		
		for(int i=1; i<person.size(); i++)
		{
			prefs.push_back(person[i]);
		}
		
		int name {person[0]};
		table_map[name] = prefs;
	
	}	
		
	return table_map;

}
