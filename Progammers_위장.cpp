#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> cloth_map;
    
	/* push into the map */
    for(auto cloth : clothes)
    {
       cloth_map[cloth[1]]++; 
    }
    
	/* get map elements by auto iter */
    for(auto iter = cloth_map.begin() ; iter != cloth_map.end(); iter++){
		answer *= (iter->second + 1); 
	}
    
    return answer - 1;
}

/* revised from https://rooted.tistory.com/14 */