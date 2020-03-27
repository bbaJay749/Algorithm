#include <cstdio>
#include <iostream>
using namespace std;

void cal(int DP[]);

int main() {
    int N = 0, i = 0, j = 0, cases = 0;
    int DP[11];

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    cin >> N;

    for (i = 0; i < N; i++) {
        cal(DP);
    }

    return 0;
}

void cal(int DP[]) {
    int M = 0;
    cin >> M;

    for (int j = 4; j <= M; j++) {
        DP[j] = DP[j - 1] + DP[j - 2] + DP[j - 3];
    }
    
    cout << DP[M] << endl;
}

/* 재귀
#include <iostream>
using namespace std;

int getSum(int n, int cnt){
	if(n == 0){ // n == 0: 1,2,3으로 이루어진 더하기 모두 완성
		return cnt+1;
	}
	
	for(int i = 1; i <= 3; i++){
		if(n-i >= 0){ // n-i가 0보다 작으면 최종적으로 n보다 큰 덧셈 만들어짐, 따라서 조건문으로 걸러줌
			cnt = getSum(n-i,cnt); // +i로 만들어주고 n에서 i빼줌(이를 재귀적으로 수행)
		}
	}
	
	return cnt;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n;
		cin >> n;
		
		cout << getSum(n,0) << "\n";
	}
	
	return 0;
}
*/
