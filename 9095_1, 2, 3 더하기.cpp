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

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n;
		cin >> n;
		
		int arr[n+1];
		arr[0] = 1; // arr[0] = 1은 초기값
		
		for(int i = 1; i < 4; i++){ // 1이 들어가는 경우의 수부터 3이 들어가는 경우의 수까지 따지기 위함
			for(int j = i; j < n+1; j++){ // 현재 i보다 작은 값은 i로 만들 수 없기 때문에 i부터 시작해야함
				arr[j] = 0;
				for(int k = 1; k <= i; k++){ // 이전 i개의 배열 값을 더해줌
					arr[j] += arr[j-k];
				}
			}
		}
		
		cout << arr[n] << '\n';
	}
	return 0;
}
*/
