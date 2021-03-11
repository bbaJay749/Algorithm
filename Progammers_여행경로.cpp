#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool dfs(string departure, vector<vector<string>> &tickets, vector<string> &answer, vector<bool> &visited, vector<string> &temp_course, int finishCnt) 
{   
    /* add city into the course */
    temp_course.push_back(departure);

    /* if a course completed */
    if(finishCnt == tickets.size()) 
    {
        answer = temp_course;
        return true;
    }

    /* scan all the tickets and find a matching ticket */
    for(int i = 0; i < tickets.size(); i++) 
    {
        /* if cities match each other and never used that ticket */
        if(tickets[i][0] == departure && !visited[i]) 
        {
            visited[i] = true;
            bool success = dfs(tickets[i][1], tickets, answer, visited, temp_course, finishCnt + 1);
            
            /* if there's matching ticket */
            if(success) {
                return true;
            }
            else {
                visited[i] = false;
            }
        }
    }
    
    temp_course.pop_back(); // if there are no matching ticket with the city
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) 
{
    vector<string> answer, temp_course;
    vector<bool> visited(tickets.size());

    /* alphabet ascending order */
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", tickets, answer, visited, temp_course, 0);

    return answer;
}

/* revised from https://hochoon-dev.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%97%AC%ED%96%89%EA%B2%BD%EB%A1%9C-c */
