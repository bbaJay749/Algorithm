#include <string>
#include <vector>
#include <queue>
using namespace std;

int low_1st_scoville, low_2nd_scoville;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    
    while (pq.top() < K) {
		// if there are no more dishes to mix
		if (pq.size() == 1) return answer = -1;
    
        // get the dishes have 1st & 2nd lowest scoville
		low_1st_scoville = pq.top();
		pq.pop();
		low_2nd_scoville = pq.top();
		pq.pop();
		
        // push to the priority_queue
		pq.push(low_1st_scoville + (low_2nd_scoville * 2));

		//횟수 추가
		answer++;
	}

    return answer;
}

/* revised from http://blog.naver.com/PostView.nhn?blogId=h0609zxc&logNo=221492095742 */
