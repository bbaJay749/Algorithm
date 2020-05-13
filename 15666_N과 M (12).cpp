#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M;
vector<int> nums;
vector<int> output;
set<vector<int> > outputs;
void Genpm(int cnt, int t);

int main() {
	int temp;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		nums.push_back(temp);
	}

	sort(nums.begin(), nums.end(), less<int>());
	
	Genpm(0, 0);

	set<vector<int> >::iterator itr;
	for (itr = outputs.begin(); itr != outputs.end(); itr++) {
		vector<int> A = *itr;
		for (int q = 0; q < A.size(); q++) {
			cout << A[q] << " ";
		}
		cout << "\n";
	}

	return 0;
}

void Genpm(int cnt, int t) {
	if (cnt == M) {
		outputs.insert(output);
		return;
	}

	for (int j = t; j < N; j++) {
		output.push_back(nums[j]);
		Genpm(cnt + 1, j);
		output.pop_back();
	}
}
