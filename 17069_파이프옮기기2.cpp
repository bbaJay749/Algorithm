#include <iostream>
#include <vector>
using namespace std;

typedef long long int LL;
int N, temp;
vector<vector<bool> > movePos(3, vector<bool>(2));

int main() {
	cin >> N;

	vector<vector<int> > house(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 1) house[i][j] = true;
			else if (temp == 0) house[i][j] = false;
		}
	}

	vector<vector<vector<LL>>> dp(3, vector<vector<LL>>(N, vector<LL>(N, 0)));
	// 3D vector to save routes of Horizontal, Vertical, Diagonal states 
	dp[0][0][1] = 1; // initial location

	movePos = { {1, 0}, {0, 1}, {1, 1} }; 
	/* cuz every state can be moved diagonally.
	   this represents each state can be moved vertically and horizontally (available = true) */

	int dir[2][2] = { {0,1},{1,0} }; // vertical & horizontal move
	for (int x = 0; x < N; x++) {	// x loc
		for (int y = 0; y < N; y++) {  // y loc
			for (int k = 0; k < 3; k++) { // vertical, horizontal, diagonal
				for (int m = 0; m < 2; m++) { // to move ver or hor
					if (movePos[k][m] == 1) { // if it's possible
						/* should be in the range & there should be no wall*/
						int dx = x + dir[m][0], dy = y + dir[m][1];
						if (dx < N && dy < N && house[dx][dy] == 0) { 
							/* add the num of cases of current loc to the next loc's num of cases*/
							dp[m][dx][dy] += dp[k][x][y];
						}
					}
				}

				// vertical move
				if (x + 1 < N && y + 1 < N) { // range check
					if (house[x + 1][y] == 0 && house[x][y + 1] == 0 && house[x + 1][y + 1] == 0) { 
						/* add the num of cases of current loc to the next loc's num of cases*/
						dp[2][x + 1][y + 1] += dp[k][x][y]; 
					}
				}
			}
		}
	}

	/* add all three num of cases to get the destination (ver, hor, diagon) */
	cout << dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1]; 

	return 0;
}
