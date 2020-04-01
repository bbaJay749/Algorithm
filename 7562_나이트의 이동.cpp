#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int BFS(int sx, int sy, int dx, int dy, int I, vector<vector<bool> > visited);

struct pos {
	int x;
	int y;
	int step;
};

int move_x[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int move_y[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main(void)
{
	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int I = 0;
		int sx = 0, sy = 0, dx = 0, dy = 0;
		cin >> I >> sx >> sy >> dx >> dy;

		vector<vector<bool> > visited(I, vector<bool>(I, 0));

		cout << BFS(sx, sy, dx, dy, I, visited) << endl;
	}
	
	return 0;
}

int BFS(int sx, int sy, int dx, int dy, int I, vector<vector<bool> > visited) {
	queue<pos> q;

	q.push({ sx,sy,0 });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int now_x = q.front().x;
		int now_y = q.front().y;
		int step = q.front().step;
		q.pop();

		if (now_x == dx && now_y == dy)	return step;

		for (int i = 0; i < 8; i++) {
			int next_x = now_x + move_x[i];
			int next_y = now_y + move_y[i];

			if (next_x >= 0 && next_x < I && next_y >= 0 && next_y < I) {
				if (!visited[next_x][next_y]) {
					visited[next_x][next_y] = true;
					q.push({ next_x, next_y, step + 1 });
				}
			}
		}
	}
}
