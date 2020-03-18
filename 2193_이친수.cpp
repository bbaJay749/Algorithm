#include <iostream>
#include <vector>
using namespace std;

long long Pinary(int num){
	vector<long long> pinary(90, 0);		// why long long ??
	pinary[0] = 0;
	pinary[1] = 1; 

	for (int i = 2; i < num + 1; i++) {

		pinary[i] = pinary[i - 1] + pinary[i - 2];

	}

	return pinary[num];
}

int main() {
	int N;
	cin >> N;

	cout << Pinary(N) << endl;

	return 0;
}

