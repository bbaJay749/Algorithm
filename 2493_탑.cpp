#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> top(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> top[i];
	}

	for (int i = 0; i < N; i++) {
		int receive = 0; 
		for (int j = i - 1; j >= 0; j--) {
			if (top[i] < top[j]) { 
				receive = j + 1;
				break;
			}
		}
		cout << receive << " ";
	}

	return 0;
}
