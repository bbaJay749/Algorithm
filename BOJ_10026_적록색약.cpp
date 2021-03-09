#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N;
queue<pair<int, int> > parabfs;
pair<int, int> temp_pair;
vector<pair<int, int> > dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
pair<int, int> areanum;
int count_disable, count_able;

void bfs(vector<vector<char> > map, vector<vector<bool> > visit) 
{
	/* for disabled */
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (!visit[a][b]) {
				parabfs.push({ a, b });
				visit[a][b] = true;
				count_disable += 1;

				while (!parabfs.empty()) {
					temp_pair = parabfs.front();
					char temp = map[temp_pair.first][temp_pair.second];
					parabfs.pop();

					for (int i = 0; i < 4; i++) {
						/* within the range */
						if (temp_pair.first + dir[i].first >= 0 && temp_pair.first + dir[i].first < N && temp_pair.second + dir[i].second >= 0 && temp_pair.second + dir[i].second < N) {
							/* haven't visited */
							if (!visit[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second]) {
								/* should be same char */
								if ((temp == 'R' && map[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second] == 'G')
									|| (temp == 'G' && map[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second] == 'R') 
									|| (temp == map[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second])) 
								{
									
									parabfs.push({ temp_pair.first + dir[i].first, temp_pair.second + dir[i].second });
									visit[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second] = true;
								}
							}
						}
					}
				}
			}
		}
	}

	visit = vector<vector<bool> > (N, vector<bool>(N, false));

	/* for abled */
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (!visit[a][b]) {
				parabfs.push({ a, b });
				visit[a][b] = true;
				count_able += 1;

				while (!parabfs.empty()) {
					temp_pair = parabfs.front();
					char temp = map[temp_pair.first][temp_pair.second];
					parabfs.pop();

					for (int i = 0; i < 4; i++) {
						/* within the range */
						if (temp_pair.first + dir[i].first >= 0 && temp_pair.first + dir[i].first < N && temp_pair.second + dir[i].second >= 0 && temp_pair.second + dir[i].second < N) {
							/* haven't visited */
							if (!visit[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second]) {
								/* should be same char */
								if (temp == map[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second]) {
									parabfs.push({ temp_pair.first + dir[i].first, temp_pair.second + dir[i].second });
									visit[temp_pair.first + dir[i].first][temp_pair.second + dir[i].second] = true;
								}
							}
						}
					}
				}
			}
		}
	}

}


int main()
{
	cin >> N;
	vector<vector<char> > map(N, vector<char>(N, false));
	vector<vector<bool> > visit(N, vector<bool>(N, false));

	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			map[j][i] = temp;
		}
	}

	bfs(map, visit);

	cout << count_able << " " << count_disable << "\n";

	return 0;
}
