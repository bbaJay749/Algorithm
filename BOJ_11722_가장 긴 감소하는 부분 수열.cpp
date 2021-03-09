#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int N = 0;
	cin >> N;

	vector<int> nums(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	int max = 1;
	vector<int> LDS(N, 0);
	
	LDS[0] = 1;
	for (int i = 0; i < N; i++) {
		LDS[i] = 1;
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[i] && LDS[j] + 1 > LDS[i]) {
				LDS[i]++;
			}
		}
		if (max < LDS[i]) max = LDS[i];
	}

	cout << max;

	return 0;
}
