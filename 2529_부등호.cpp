#include <cstdio>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int count_num(vector<int> inequalities, int i, int N);
int nthmax(vector<bool> num, int i);
int nthmin(vector<bool> num, int i);

int main() {
	int N = 0;
	cin >> N;

	vector<int> inequalities;	// input
	vector<int> num_in_row;		// count how many < or > in a row
	vector<bool> max_num_use(10, 1);	// numbers used : 1
	vector<bool> min_num_use(10, 1);
	vector<int> maxarray(N + 1, 0);		// output num
	vector<int> minarray(N + 1, 0);

	for (int i = 0; i < N; i++) {
		char k;
		cin >> k;
		inequalities.push_back(k);
	}

	for (int i = 0; i < N; i++) {
		int a = count_num(inequalities, i, N);
		num_in_row.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		if (inequalities[i] == 60) {
			maxarray[i] = nthmax(max_num_use, num_in_row[i]);	// find nth max num
			minarray[i] = nthmin(min_num_use, 0);
			max_num_use[maxarray[i]] = 0;	// make nth max num into used one
			min_num_use[minarray[i]] = 0;
		}
		else if (inequalities[i] == 62) {
			maxarray[i] = nthmax(max_num_use, 0);
			minarray[i] = nthmin(min_num_use, num_in_row[i]);	// find nth min num
			max_num_use[maxarray[i]] = 0;	
			min_num_use[minarray[i]] = 0;	// make nth min num into used one
		}
	}
	maxarray[N] = nthmax(max_num_use, 0);
	minarray[N] = nthmin(min_num_use, 0);	//last digits 

	for (int i = 0; i <= N; i++) {
		cout << maxarray[i];
	}
	cout << endl;
	for (int i = 0; i <= N; i++) {
		cout << minarray[i];
	}
	cout << endl;

	return 0;
}

/* count how many < or > are in a row */
int count_num(vector<int> inequalities, int i, int N) {	
	int num = 1;

	for (int k = i; k < N - 1; k++) {
		if (inequalities[k] == inequalities[k + 1]) {
			num += 1;
		}
		else return num;
	}

	return num;
}

/* find nth max value among available digits */
int nthmax(vector<bool> max_num_use, int i) {
	int count = 0;

	for (int k = 9; k >= 0; k--) {
		if (count == i && max_num_use[k]) {	// if the digit is not used and it's nth max value
			return k;
		}
		if (max_num_use[k]) count++;	// if the digit is not used
	}
}

int nthmin(vector<bool> min_num_use, int i) {
	int count = 0;

	for (int k = 0; k <= 9; k++) {
		if (count == i && min_num_use[k]) {
			return k;
		}
		if (min_num_use[k]) count++;
	}
}
