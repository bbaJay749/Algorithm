#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
 
using namespace std;
 
vector<int> solution(vector<string> operations) 
{
    vector<int> answer;
    deque<int> dq;
    string opr;
    int num;
    
    int op_size = operations.size();
    for (int i = 0; i < op_size; i++)
    {
        opr = operations[i];
        num = stoi(opr.substr(2));  // get number
        
        if (opr[0] == 'I')
        {
            dq.push_back(num);
            sort(dq.begin(), dq.end());   
        }
        else 
        {
            if (dq.empty()) continue;
            
            if (num == 1) dq.pop_back();
            else dq.pop_front();
        }
    }
    
    if (dq.empty()) 
    {
        answer = {0, 0};
    }
    else 
    {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}