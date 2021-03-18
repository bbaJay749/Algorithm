#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> map_participant;
    
    // assign everyone 1
    for(string name : participant)
        map_participant[name]++;
    
    // assign finisher 0
    for(string name : completion)
        map_participant[name]--;
    
    // find someone has 1
    for(string name : participant){
        if(map_participant[name] == 1) {
            answer = name;
            break;
        }
    }
    
    return answer;
}