#include <iostream>
#include <vector>
#include <deque>
using namespace std;


struct Pos {
	int x, y, dis;
};

int w, h, num_dirts;
vector<vector<char> > room(20, vector<char>(20, 0));
vector<vector<int> > dist(20, vector<int>(20, 0));
deque<Pos> dirts;
int getDist(Pos s, Pos e);
int getTime(int s, int move, int now, int prev, vector<bool> visit);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		Pos robot = { 0, 0 };

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> room[i][j];
				if (room[i][j] == 'o') dirts.push_front({ i, j, 0 });   // robot
				else if (room[i][j] == '*') dirts.push_back({ i, j, 0 });   // dirts
			}
		}

		num_dirts = dirts.size();   // to get distances
		for (int i = 0; i < num_dirts; i++) {
			for (int j = i; j < num_dirts; j++) {
				if (i == j) {
					dist[i][j] = 0;
					continue;
				}
				int d = getDist(dirts[i], dirts[j]);   // get distances between each dirts & robot
				dist[i][j] = d;
				dist[j][i] = d;
			}
		}

		vector<bool> visit(num_dirts, 0);
		printf("%d\n", getTime(1, -1, 0, 0, visit));

		while (!dirts.empty())dirts.pop_back(); // return to the initial state
		room = vector<vector<char> >(20, vector<char>(20, 0));   
		dist = vector<vector<int> >(20, vector<int>(20, 0));
	}

	return 0;
}

int getDist(Pos s, Pos e) {   // get the distance between S and E
	int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

	vector<vector<bool> > visit(h, vector<bool>(w, 0));

	visit[s.x][s.y] = true;

	deque<Pos> q;
	q.push_back(s);
	while (!q.empty()) {
		Pos p = q.front();
		q.pop_front();

		for (int d = 0; d < 4; d++) {
			int x = p.x + dir[d][0], y = p.y + dir[d][1];
			if (x >= 0 && x < h && y >= 0 && y < w) {
				if (visit[x][y] == false && room[x][y] != 'x') {
					if (x == e.x && y == e.y) {
						return p.dis + 1;
					}
					q.push_back({ x,y,p.dis + 1 });
					visit[x][y] = true;
				}
			}
		}
	}

	return -1;
}

int getTime(int s, int move, int now, int prev, vector<bool> visit) {
	if (s == num_dirts) {
		if (move < 0 || move > now) {
			move = now;
		}
		return move;
	}

	for (int i = 1; i < num_dirts; i++) {
		if (visit[i] == false && dist[prev][i] != -1) {
			visit[i] = true;
			move = getTime(s + 1, move, now + dist[prev][i], i, visit);
			visit[i] = false;
		}
	}

	return move;
}
