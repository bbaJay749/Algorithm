#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> node;
vector<node> location;
int testcase;
int n, u, v;

int main() {
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		cin >> n;
		// home
		cin >> u >> v;
		location.push_back(node(u, v));
		// CV
		for (int i = 0; i < n; i++) {
			cin >> u >> v;
			location.push_back(node(u, v));
		}
		// Fiesta
		cin >> u >> v;
		location.push_back(node(u, v));

		vector<vector<bool> > conn(n + 2, vector<bool>(n + 2, false));
		// num of CVs + home + fiesta

		// initialize
		for (int i = 0; i < location.size(); i++) {
			for (int j = 0; j < location.size(); j++) {
				if (i == j) continue;

				int dist = abs(location[i].first - location[j].first) + abs(location[i].second - location[j].second);	// cal distance 

				if (dist <= 1000) {
					conn[i][j] = true;
				}
			}
		}

		// verify node connectivity
		for (int k = 0; k < n + 2; k++) {
			for (int i = 0; i < n + 2; i++) {
				for (int j = 0; j < n + 2; j++) {
					if (i == j) continue;
					if (i == k || j == k) continue;

					if (!conn[i][j]) {
						if (conn[i][k] && conn[k][j]) {
							conn[i][j] = true;
						}
					}
				}
			}
		}

		// print result
		if (conn[0][n + 1])
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";

		location.clear();
	}
}
