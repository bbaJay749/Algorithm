#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N = 0, K = 0;
	cin >> N >> K;

	vector<vector <long> > cases(201, (vector<long>(201, 1)));

	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j <= 200; j++) {
			cases[i][j] = cases[i - 1][j] + cases[i][j - 1];
			cases[i][j] %= 1000000000;
		}
	}

	cout << cases[N][K - 1] << endl;

	return 0;
}
