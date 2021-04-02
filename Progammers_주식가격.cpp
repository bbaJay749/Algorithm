#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int a = 0; a < prices.size(); a++) {
        int cnt = 0;
        for(int b = a + 1; b < prices.size(); b++) {
            if(prices[b] >= prices[a]) {
                cnt++;
            }
            else {
                cnt++;
                break;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}