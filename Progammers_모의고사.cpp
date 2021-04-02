#include <string>
#include <vector>
using namespace std;

vector<int> answer1 {1, 2, 3, 4, 5}; 
vector<int> answer2 {2, 1, 2, 3, 2, 4, 2, 5}; 
vector<int> answer3 {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int count1, count2, count3;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int answers_size = answers.size(); 
    
    for(int i = 0; i < answers_size; ++i) {
        int i1 = i % 5; // 0 ~ 4 
        int i2 = i % 8; // 0 ~ 7 
        int i3 = i % 10; // 0 ~ 9 
        
        if(answers[i] == answer1[i1]) count1++; 
        if(answers[i] == answer2[i2]) count2++; 
        if(answers[i] == answer3[i3]) count3++; 
    }
    
    int maxCount = max(count1, max(count2, count3)); 
    
    if(maxCount == count1) answer.push_back(1); 
    if(maxCount == count2) answer.push_back(2); 
    if(maxCount == count3) answer.push_back(3);

    return answer;
}