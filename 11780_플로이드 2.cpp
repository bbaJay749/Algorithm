#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int INF = 987654321;
int n, m;
void calculate();
vector<vector<int> > cost(101, vector<int>(101, INF));
vector<vector<int> > via(101, vector<int>(101, 0));
void reconstruct(int u, int v, vector<int>& path);

int main() {
	cin >> n >> m;

	int a, b, c;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
	}
	for (int i = 1; i <= n; i++) {
		cost[i][i] = 0;
	}

	calculate();

	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= n; j++) { 
			cout << cost[i][j] << " ";
		} 
		printf("\n"); 
	} 

	vector<int> path;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// if i == j, print 0 (itself)
			if (i == j) {
				printf("0\n");
				continue;
			}

			reconstruct(i, j, path);

			// print path
			cout << path.size() << " ";
			for (int i = 0; i < path.size(); i++) {
				cout << path[i] << " ";
			}
			cout << "\n";
			path.clear();
		}
	}
	return 0;
}

void calculate() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cost[i][k] == 0 || cost[k][j] == 0 || i == j) continue;

				if (cost[i][k] + cost[k][j] < cost[i][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
					via[i][j] = k;
				}
			}
		}
	}

	return;
}

void reconstruct(int u, int v, vector<int>& path) {
	// if u -> v directly,
	if (via[u][v] == 0) {
		path.push_back(u);	// push u and if u != v, push v
		if (u != v) {
			path.push_back(v);
		}
		// if u == v, the path is itself
	}

	// if u -> v going by somewhere else
	else {
		int w = via[u][v];	// w == via point

		// call this function with u -> w
		reconstruct(u, w, path);
		path.pop_back();
		// call this function with w -> v
		reconstruct(w, v, path);
	}
}

/* revised from https://www.crocus.co.kr/713 */
