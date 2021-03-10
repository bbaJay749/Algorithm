#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++) 
    {   
        /* create temp array for sorting */
        vector<int> temp_sort;
        
        /* get elements from commands[i][0] to commands[i][1] */
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            temp_sort.push_back(array[j]);
        }
        
        /* sort in acsending order */
        sort(temp_sort.begin(), temp_sort.end(), less<int>());
        /* get commands[i][2]th element */
        answer.push_back(temp_sort[commands[i][2] - 1]);
    }
    
    
    return answer;
}