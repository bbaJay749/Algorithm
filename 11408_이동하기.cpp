#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    vector<vector<int> > maze(N + 1, vector<int>(M + 1, 0));
    vector<vector<int> > DP(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int result = max(DP[i - 1][j - 1], max(DP[i - 1][j], DP[i][j - 1]));
            DP[i][j] = result + maze[i][j];
        }
    }

    cout << DP[N][M] << "\n";

    return 0;
}
