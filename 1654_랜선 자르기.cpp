#include <iostream>
#include <vector>
using namespace std;

int main() {
	int K = 0, N = 0;
	cin >> K >> N;
	vector<long long> cables(K, 0);

	long long mincable = 1, maxcable = 0;
	for (int i = 0; i < K; i++) {
		cin >> cables[i];
		if (cables[i] > maxcable) maxcable = cables[i];
	}

	long long lenLAN = maxcable;
	int numLAN = 0;

	while (mincable != lenLAN) {
		numLAN = 0;
		for (int i = 0; i < K; i++) {
			numLAN += cables[i] / lenLAN;
		}

		if (numLAN >= N) {
			mincable = lenLAN;
			lenLAN = (maxcable + lenLAN) / 2;
		}
		else {
			maxcable = lenLAN;
			lenLAN = (mincable + lenLAN) / 2;
		}
	}

	cout << lenLAN << endl;

	return 0;
}
