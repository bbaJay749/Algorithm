#include <iostream>
#include <vector>
using namespace std;

int n, m, h, ans = 4;
vector<vector<bool> > loc(30, vector<bool>(10));
bool check_ladder();
void brute_force(int cnt, int x, int y);

int main() {
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		loc[a - 1][b - 1] = 1;
	}

	brute_force(0, 0, 0);

	if (ans < 4) cout << ans << "\n";
	else cout << "-1\n";

	return 0;
}

bool check_ladder() {
	for (int i = 0; i < n; i++) {
		int k = i;
		for (int j = 0; j < h; j++) {
			if (loc[j][k]) k += 1;	// if current location is true, go right
			else if (k > 0 && loc[j][k - 1]) k -= 1;	// else if left location is true, go left
		}
		if (i != k) return false;	//	at the bottom, check i == k or not
	}
	return true;
}

void brute_force(int cnt, int x, int y) {
	if (ans <= cnt) return;		

	if (check_ladder()) {	// check if the ladder is ok or not
		if (ans > cnt) ans = cnt;	
		return;
	}

	if (cnt == 3) return;

	for (int i = x; i < h; i++, y = 0) {
		for (int j = y; j < n - 1; j++) {
			if (loc[i][j]) {
				j += 1;	// if it's connected, go to [i][j+2]
			}
			else {
				loc[i][j] = 1;	// if it's not connected, connect it and go to [i][j+2]
				brute_force(cnt + 1, i, j + 2);
				loc[i][j] = 0;	// unconnect
			}
		}
	}
}


/* revised from https://rebas.kr/790 */
