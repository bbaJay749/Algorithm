#include <iostream>
#include <vector>
using namespace std;

int N, result;

int main() {
	cin >> N;
	vector<vector<int> > cal(N + 1, vector<int>(10, 0));

	for (int i = 0; i <= 9; i++) {
		cal[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				cal[i][k] += cal[i - 1][j];
				cal[i][k] %= 10007;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		result += cal[N][i];
	}

	cout << result % 10007 << "\n";

	return 0;
}

/* revised from https://jaemin8852.tistory.com/167 */
