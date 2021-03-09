#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int M, N, K;
int A, B, C, D;
int q, w, e, r;
queue<pair<int, int> > parabfs;
pair<int, int> temp_pair;
vector<pair<int, int> > dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
vector<int> area_size;

void bfs(vector<vector<bool> > map, vector<vector<bool> > visit) {

	for (int a = 0; a < M; a++) {
		for (int b = 0; b < N; b++) {
			if (!visit[a][b] && !map[a][b]) {
				int count = 0;
				parabfs.push({ a, b });
				visit[a][b] = true;
				count += 1;

				while (!parabfs.empty()) {
					temp_pair = parabfs.front();
					parabfs.pop();

					for (int i = 0; i < 4; i++) {

						q = temp_pair.first;
						w = temp_pair.second;
						e = dir[i].first;
						r = dir[i].second;

						if (q + e >= 0 && q + e < M && w + r >= 0 && w + r < N) {
							if (!visit[q + e][w + r] && !map[q + e][w + r]) {
								parabfs.push({ q + e, w + r });
								visit[q + e][w + r] = true;
								count += 1;
							}
						}
					}
				}
				area_size.push_back(count);
			}
		}
	}
}

int main()
{
	cin >> M >> N >> K;
	vector<vector<bool> > map(M, vector<bool>(N, false));
	vector<vector<bool> > visit(M, vector<bool>(N, false));

	/* check all the not-interested area */
	for (int a = 0; a < K; a++) {
		cin >> A >> B >> C >> D;
		int temp = 0;
		for (int i = A; i < C; i++) {
			for (int j = B; j < D; j++) {
				map[j][i] = true;
			}
		}
	}

	bfs(map, visit);

	cout << area_size.size() << "\n";
	sort(area_size.begin(), area_size.end());

	for (int i = 0; i < area_size.size(); i++) {
		cout << area_size[i] << " ";
	}

	return 0;
}
