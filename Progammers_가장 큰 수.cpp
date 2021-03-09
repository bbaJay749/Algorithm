#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
/* return 1 if a + b is bigger*/
bool cmp(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> numbers) { 
	string answer = "";
	vector<string> tmp;
    
	for (int i = 0; i < numbers.size(); i++) 
    {
        tmp.push_back(to_string(numbers[i]));
    }
    
	sort(tmp.begin(), tmp.end(), cmp); // sort in func cmp 
    
	for (int i = 0; i < tmp.size(); i++)
    {
        answer += tmp[i]; 
    }
    
    /* handling expection like 00 */
	if (answer[0] == '0') return "0"; 
    
	return answer;
}

/* revised from https://mungto.tistory.com/22 */