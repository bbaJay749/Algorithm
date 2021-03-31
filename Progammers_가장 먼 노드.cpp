#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
 
using namespace std;
 
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int> > graph(n + 1, vector<int> ());
    vector<bool> visit(n + 1, false);
    vector<int> dist(n + 1, 0);
    queue<int> q;
    
    /* push edge info into graph */
    for (int i = 0; i < edge.size(); i++) 
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    /* start BFS */
    q.push(1);
    visit[1] = true;
    dist[1] = 0;
    
    while (!q.empty()) 
    {
        int start = q.front();
        q.pop();
        

        for (int i = 0; i < graph[start].size(); i++) //    check all the next nodes
        {
           if (visit[graph[start][i]] == false) // if never visited
           {   
                q.push(graph[start][i]);    // push into the queue
                visit[graph[start][i]] = true;  // check visit
                dist[graph[start][i]] = dist[start] + 1;    // add distance + 1
           }
        }
    }
    
    sort(dist.begin(), dist.end(), greater<int>()); // descending order
    
    for (int i = 0; i <= n; i++) {
        if (dist[i] == dist[0]) {   // if dist value is same with the biggest value
            answer++;
        }
    }
    
    return answer;
}

/* revised from https://dvpzeekke.tistory.com/35 */