#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

struct Pos {
	int x, y, time;
};

int putVirus(int N, int M, int s, int count, int min_time, int** lab, vector<Pos> loc_virus, vector<Pos> v);
int spread(int N, int M, int count, int** lab, vector<Pos> v);

int main() {
	int N, M;
	cin >> N >> M;

	int** lab = new int* [N];	// map of the lab
	for (int i = 0; i < N; i++) {
		lab[i] = new int[N];
	}

	vector<Pos> loc_virus;		// available locations of virus
	int count = (N * N) - M;	// num of the locations virus can attack (all - wall - virus')
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> lab[i][j];

			if (lab[i][j] == 2) {	
				loc_virus.push_back({ i,j,0 });
			}
			else if (lab[i][j] == 1) {
				count--;
			}
		}
	}

	vector<Pos> v;
	int t = putVirus(N, M, 0, count, 10000000, lab, loc_virus, v);

	if (t == 10000000) { // if t is still 10000000, that means virus can't conquer the lab
		cout << -1;
	}
	else {
		cout << t;
	}

	return 0;
}

int putVirus(int N, int M, int s, int count, int min_time, int** lab, vector<Pos> loc_virus, vector<Pos> v) { // 바이러스가 놓여질 수 있는 곳들 중 M개를 선택하기 위한 함수(조합을 구하는 것과 동일)
	if (v.size() == M) { // when M locations are selected
		int t = spread(N, M, count, lab, v);

		if (min_time > t) { // to get min time
			min_time = t;
		}

		return min_time;
	}

	int v_size = loc_virus.size();
	// s is starting point
	for (int i = s; i < v_size; i++) { // to select M locations
		v.push_back(loc_virus[i]);	// push & back to keep changing the choice
		int t = putVirus(N, M, i + 1, count, min_time, lab, loc_virus, v); 
		// Next putVirus starts from the next location of current virus location
		v.pop_back();

		if (min_time > t) {
			min_time = t;
		}
	}

	return min_time;
}

int spread(int N, int M, int count, int** lab, vector<Pos> v) { // time consumption of virus' conquest
	bool** visit = new bool* [N];	// check visit 
	for (int i = 0; i < N; i++) {
		visit[i] = new bool[N];
		memset(visit[i],false,sizeof(bool)*N);
	}

	queue<Pos> q; // queue for BFS
	for (int i = 0; i < M; i++) {
		Pos p = v[i];
		visit[p.x][p.y] = true;

		q.push(p);	// initially, put every virus' locations to a queue
	}

	int t = 0; // time consumption
	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; // UDLR
	while (!q.empty()) {
		Pos p = q.front();
		q.pop();	// take the front location and pop it

		for (int d = 0; d < 4; d++) {
			int x = p.x + dir[d][0];
			int y = p.y + dir[d][1];
			if (x >= 0 && x < N && y >= 0 && y < N) {
				if (visit[x][y] == false && lab[x][y] != 1) { 
					/* if never visited and it's not wall 
					push every UDLR locations into the queue */
					q.push({ x,y,p.time + 1 });
					visit[x][y] = true;
					count--;
					t = p.time + 1;
				}
			}
		}
	}

	if (count == 0) { // if count is 0, all potential locations are contaminated. 
		return t;
	}
	else {
		return 10000000;
	}
}
