#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int x, y, a, b;
queue<pair<int, int> > BFS_move;
queue<pair<int, int> > BFS_light;
vector<vector<int> > dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int result;

void bfs(vector<vector<queue<pair<int, int> > > > barn, vector<vector<bool> > light_map)
{
	vector<vector<bool> > visit(N, vector<bool>(N, false));
	visit[0][0] = true;

	/* push initial location & switches */
	BFS_move.push({ 0, 0 });
	BFS_light = barn[0][0];

	/* start BFS */
	while (true) {
		int flag = false; // true == light switch on, false == light switch off

		queue<pair<int, int> > temp = BFS_move;	// get possible locations
		while (!temp.empty())	// for all possible locations 
		{
			pair<int, int> room = temp.front();
			temp.pop();
			BFS_light = barn[room.first][room.second];	// get the switch queue of possible loc

			/* turn on all the light possible */
			while (!BFS_light.empty())
			{
				pair<int, int> temp_swtch = BFS_light.front();
				BFS_light.pop();

				if (!light_map[temp_swtch.first][temp_swtch.second]) {
					light_map[temp_swtch.first][temp_swtch.second] = true;
					flag = true;
					result++;
				}
			}
		}

		if (!flag) break;	// if no swithc has turned on

		/* get current loctaion */
		pair<int, int> temp_loc = BFS_move.front();
		BFS_move.pop();

		queue<pair<int, int> > temp_BFS_move;
		temp_BFS_move.push(temp_loc);

		/* after turning on all the possible switches, new possible rooms need to be visited */
		vector<vector<bool> > new_visit(N, vector<bool>(N, false));
		new_visit[temp_loc.first][temp_loc.second] = true;

		/* move to all possible loc */
		while (!temp_BFS_move.empty()) {
			pair<int, int> a = temp_BFS_move.front();
			temp_BFS_move.pop();

			for (int i = 0; i < 4; i++) {
				int next_x = a.first + dir[i][0];
				int next_y = a.second + dir[i][1];

				if (next_x < N && next_x >= 0 && next_y < N && next_y >= 0) {
					/* if the room never visited after turning on all the possible switches */
					if (!new_visit[next_x][next_y]) {
						/* if light is on, go there */
						if (light_map[next_x][next_y]) {
							temp_BFS_move.push({ next_x, next_y });
							new_visit[next_x][next_y] = true;

							/* if the room has never visited before, the switches in the room need to be turned on */
							if (!visit[next_x][next_y]) {
								visit[next_x][next_y] = true;
								BFS_move.push({ next_x, next_y });
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
	cin >> N >> M;

	/* initialize N x N barn */
	vector<vector<queue<pair<int, int> > > > barn(N, vector<queue<pair<int, int> > >(N));
	vector<vector<bool> > light_map(N, vector<bool>(N, false));
	light_map[0][0] = true;

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> a >> b;
		barn[x - 1][y - 1].push({ a - 1, b - 1 });
	}

	bfs(barn, light_map);

	cout << result + 1 << "\n"; // cuz the light of barn[0][0] was on from the very first

	return 0;
}
