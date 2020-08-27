#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, temp;
vector<int> pack;

int getMaxPrice(vector<int> DP)
{
	/* DP is the max price for N cards */
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++)
			DP[i] = max(DP[i], DP[i - j] + pack[j]);
	}

	return DP[N];
}

int main()
{
	cin >> N;
	vector<int> DP(N + 1, 0);

	pack.push_back(0);
	for (int i = 0; i < N; i++){
		cin >> temp;
		pack.push_back(temp);
	}
		
	cout << getMaxPrice(DP);
}
