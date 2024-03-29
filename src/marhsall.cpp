#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

std::unordered_map<int,std::vector<int>> marshall(std::vector<std::vector<int>> table)
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