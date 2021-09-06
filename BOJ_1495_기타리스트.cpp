#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int NumofSongs, InitVol, MaxVol;
int result = -1;
vector<int> Vols;
vector<vector<bool> > dp(101, vector<bool>(1001, false));

void dfs(int index, int tempVol) {
    if (tempVol < 0 || tempVol > MaxVol) {
        return;
    }

    /* this is necessary to remove redundant cases, there can be cases like this 
       
       (Order, Volume)
       (0, 5) -> (1, 6) -> (2, 7)
                        -> (2, 5) 
              -> (1, 4) -> (2, 5) then this case doesn't even need to be calculated 
                        -> (2, 3) this case need to be calculated
    */
    if (dp[index][tempVol]) {
        return;
    }

    if (index == NumofSongs) {
        result = max(result, tempVol);
        return;
    }

    dp[index][tempVol] = true;

    dfs(index + 1, tempVol + Vols[index]);
    dfs(index + 1, tempVol - Vols[index]);
}


int main() {
    cin >> NumofSongs >> InitVol >> MaxVol;
   
    int tempvol;
    for (int i = 0; i < NumofSongs; i++) {
        cin >> tempvol;
        Vols.push_back(tempvol);
    }

    dfs(0, InitVol);

    cout << result << "\n";

    return 0;
}
