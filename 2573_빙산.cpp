/* Dumb way again 

#include <cstdio>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int check_yrs(vector<vector<int>> iceberg, int N, int M);
int check_peices(vector<vector<int>> iceberg, int N, int M);
int melt_num(vector<vector<int>> iceberg, int i, int j, int N, int M);
void getpeices(vector<vector<int>> iceberg, vector<vector<bool>> checker, int i, int j, int N, int M, int peices, int flag);

int main() {
	int N, M = 0;
	cin >> N >> M;

	vector<vector<int>> iceberg(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> iceberg[i][j];
		}
	}

	cout << check_yrs(iceberg, N, M) << endl;

	return 0;
}

int melt_num(vector<vector<int>> iceberg, int i, int j, int N, int M) {
	int counter = 0;

	if (i < N && iceberg[i + 1][j] == 0) counter++;
	if (i < M && iceberg[i][j + 1] == 0) counter++;
	if (0 < i && iceberg[i - 1][j] == 0) counter++;
	if (0 < j && iceberg[i][j - 1] == 0) counter++;

	return counter;
}

int check_peices(vector<vector<int>> iceberg, int N, int M) {
	int peices = 0;
	int flag = 0;
	
	vector<vector<bool>> checker(N, vector<bool>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			flag = 0;
			getpeices(iceberg, checker, i, j, N, M, peices, flag);
		}
	}

	return peices;
}

void getpeices(vector<vector<int>> iceberg, vector<vector<bool>> checker, int i, int j, int N, int M, int peices, int flag) {
	if (!checker[i][j]) {
		checker[i][j] = true;
		if (iceberg[i][j]) {
			if (!flag) {
				flag = true; peices++;
			}
			if (0 < i) getpeices(iceberg, checker, i - 1, j, N, M, peices, flag);
			if (i < N) getpeices(iceberg, checker, i + 1, j, N, M, peices, flag);
			if (0 < j) getpeices(iceberg, checker, i, j - 1, N, M, peices, flag);
			if (j < M) getpeices(iceberg, checker, i, j + 1, N, M, peices, flag);
		}
	}
	else;
}


int check_yrs(vector<vector<int>> iceberg, int N, int M) {
	int yrs = 0;
	int peices = 0;

	while (peices < 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				iceberg[i][j] -= melt_num(iceberg, i, j, N, M);
			}
		}
		peices = check_peices(iceberg, N, M);
		yrs++;
	}

	return yrs;
}
*/
