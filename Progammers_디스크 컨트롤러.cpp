#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// ascending order of consume time
struct comp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end()); // sort in Ascending order (requested time) 
    priority_queue<vector<int>, vector<vector<int>>, comp> pq; // min heap
    
    int len = jobs.size();
    int i = 0; // jobs index
    int time = 0; // the time when current job would be done
    
    
    while(i < len || !pq.empty()) 
    { 
        /* if current job has arrived and there are more jobs*/
        if(i < len && jobs[i][0] <= time) 
        {
            pq.push(jobs[i]); // push into the pq
            i++;    // increase job index
            continue;
        }
        /* if pq is not empty */
        if(!pq.empty()) 
        {
            time += pq.top()[1]; // add current work time 
            answer += time - pq.top()[0]; // calculate total work time
            pq.pop();   // job done 
        }
        /* if pq is empty, immediately do next job */
        else 
        {
            time = jobs[i][0];
        }
    }

    return answer/len;
}

/* revised from https://dokylee.tistory.com/68 */