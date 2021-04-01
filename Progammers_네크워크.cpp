#include <string>
#include <vector>
#include <queue>
using namespace std;

queue <int> forBFS;
int answer;

int solution(int n, vector<vector<int>> computers) {
    vector<int> comVisit(n + 1, 0);   // Max 200 computers
    int answer = 0;
    int cnt = 0;

    for(int v = 0; v < n; v++) {
    	if(comVisit[v] == 0) {  // if the computer has never visited
        	cnt++;  // add network
        	comVisit[v] = cnt;  // to check network number
        	forBFS.push(v);    
    	}

        while(!forBFS.empty()) {
        	int check = forBFS.front();
          	forBFS.pop();

          	for(int i = 0; i < n; i++) {
              		if(computers[check][i] != 0 && i != check) {  // if there's connection
                 	    if(comVisit[i] == 0) {  // never visited
                      	    comVisit[i] = cnt;  // assgin network num
                        	forBFS.push(i);
                  	    }
              	    }
          	}
    	}
    }
    
    return cnt;
}