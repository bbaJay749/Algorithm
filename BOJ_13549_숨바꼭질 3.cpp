#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int Subin, Sis;
int Max = 100001;
int INF = 987654321;
vector<int> visit(Max, INF);
int count;

int BFS() {
    queue<int> paraBFS;
    paraBFS.push(Subin);
    visit[Subin] = 0;

    while (!paraBFS.empty()) {
        int Pos = paraBFS.front();
        paraBFS.pop();

        if (Pos == Sis) return visit[Sis];

        if (Pos + 1 < Max && visit[Pos + 1] > visit[Pos] + 1) {
            visit[Pos + 1] = visit[Pos] + 1;
            paraBFS.push(Pos + 1);
        }   // if Position + 1 is within the range and the index+1 case should be worse than value+1

        if (Pos - 1 >= 0 && visit[Pos - 1] > visit[Pos] + 1) {
            visit[Pos - 1] = visit[Pos] + 1;
            paraBFS.push(Pos - 1);
        }

        if (Pos * 2 < Max && visit[Pos * 2] > visit[Pos])
        {
            visit[Pos * 2] = visit[Pos];
            paraBFS.push(Pos * 2);
        }
    }
}

int main() {
    cin >> Subin >> Sis;
    
    cout << BFS() << "\n";

    return 0;
}
