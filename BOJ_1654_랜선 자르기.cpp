#include <iostream>
#include <vector>
using namespace std;

int K, N;
int numLAN;
long long mincable, maxcable,lenLAN;

int main() {
	cin >> K >> N;
	vector<long long> cables(K, 0);

	mincable = 1, maxcable = 0;
	for (int i = 0; i < K; i++) {
		cin >> cables[i];
		if (cables[i] > maxcable) maxcable = cables[i];
	}

	lenLAN = maxcable; //우선 가장 긴 케이블 길이부터 시작

	while (mincable != lenLAN) {
		numLAN = 0;

		/* 지정한 길이로 자르면 총 몇 개? */
		for (int i = 0; i < K; i++) {
			numLAN += cables[i] / lenLAN;
		}

		/* 원하는 개수보다 많으면 */
		if (numLAN >= N) {
			mincable = lenLAN;	// 미니멈 길이는 랜선길이로
			lenLAN = (maxcable + lenLAN) / 2;	// 랜선 길이는 반띵 늘려준다.
		}
		/* 원하는 개수보다 적으면 */
		else {
			maxcable = lenLAN;  // 최대 길이를 랜선 길이로
			lenLAN = (mincable + lenLAN) / 2;	// 랜선 길이는 반띵 줄여준다.
		}
	}

	cout << lenLAN << endl;

	return 0;
}
