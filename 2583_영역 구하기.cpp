#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int M, N, K;
int A, B, C, D;
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
						if (temp_pair.first + dir[i].first >= 0 && temp_pair.first + dir[i].first < M && temp_pair.second + dir[i].second >= 0 && temp_pair.second + dir[i].second < N) {
							if (!visit[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second] && !map[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second]) {
								parabfs.push({ temp_pair.first + dir[i].first, temp_pair.second + dir[i].second });
								visit[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second] = true;
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
