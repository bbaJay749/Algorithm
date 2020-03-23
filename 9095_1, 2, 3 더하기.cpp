#include <cstdio>
#include <iostream>
using namespace std;

void cal(int DP[]);

int main() {
    int N = 0, i = 0, j = 0, cases = 0;
    int DP[11];

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    cin >> N;

    for (i = 0; i < N; i++) {
        cal(DP);
    }

    return 0;
}

void cal(int DP[]) {
    int M = 0;
    cin >> M;

    for (int j = 4; j <= M; j++) {
        DP[j] = DP[j - 1] + DP[j - 2] + DP[j - 3];
    }
    
    cout << DP[M] << endl;
}
