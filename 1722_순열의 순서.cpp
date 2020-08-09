#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ull;
vector<ull> fac(21, 0);
int N, M;

void setFac() {
	fac[0] = 1;
	for (int i = 1; i <= 20; i++) {
		fac[i] = fac[i - 1] * i;
	}
}

void getpermut(int N) {
	ull k = 0;
	cin >> k; // K th permut

	vector<int> initial;
	for (int i = 1; i <= N; i++) {
		initial.push_back(i);
	}

	vector<int> ans;

	k--;
	int p = N - 1;
	while (p >= 0) {
		int div = k / fac[p];	// N / (p!)
		ans.push_back(initial[div]);
		initial.erase(initial.begin() + div); // erase checked vector 
		k %= fac[p];
		p--;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

void getorder(int N) {
	vector<int> permut(N + 1, 0);
	ull order = 1; // the last one ++

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		permut[i] = temp;
	}

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int k = 1; k <= i; k++) {
			if (permut[i] > permut[k]) cnt++;	// count all the nums smaller than current
		}
		order += (ull(permut[i]) - 1 - cnt) * fac[N - i];
	}

	cout << order << endl;
}

int main() {
	setFac(); // put 1! ~ 20!

	cin >> N >> M;

	if (M == 1) getpermut(N);
	else if (M == 2) getorder(N);

	return 0;
}
