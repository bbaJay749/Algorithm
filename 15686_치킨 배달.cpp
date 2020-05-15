#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
#include<set>

using namespace std;

int INF = 987654321;
int N, M;
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;
set<vector<int> > choice_chicken;
vector<int> temp_perm;

void dfs(int cnt, int t, vector<bool> visit, int choice_num) {
    if (cnt == choice_num) {
        // to get rid of the redundant permutations
        vector<int> q = temp_perm;
        sort(q.begin(), q.end());
        choice_chicken.insert(q);
        return;
    }

    for (int j = t; j < chicken.size(); j++) {
        if (!visit[j]) {
            temp_perm.push_back(j);
            visit[j] = true;
            dfs(cnt + 1, t + 1, visit, choice_num);
            visit[j] = false;
            temp_perm.pop_back();
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // get the positions of the houses and the chicken places
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a = 0;
            cin >> a;

            if (a == 1) house.push_back({ i, j });
            else if (a == 2) chicken.push_back({ i, j });  
        }
    }

    // make a vector contains the distances between each of the houses and the chicken places
    int chicken_num = chicken.size();
    int house_num = house.size();
    vector<vector<int> > distance(house_num, vector<int>(chicken_num, INF));
    for (int i = 0; i < house_num; i++) {
        for (int j = 0; j < chicken_num; j++) {
            distance[i][j] = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
        }
    }

    // choose chicken places to shut down
    vector<bool> visit(chicken_num, false);
    dfs(0, 0, visit, chicken_num - M);

    int result = INF;
    int choice_chicken_case = choice_chicken.size();
    set<vector<int> >::iterator itr;
    for (itr = choice_chicken.begin(); itr != choice_chicken.end(); itr++) {
        // get a chicken place choice
        vector<int> a = *itr;
        int temp_result = 0;
        vector<vector<int> > temp_dis = distance;
        
        // make distance to INF between houses and the chicken place shut down
        for (int j = 0; j < a.size(); j++) {
            int chick = a[j];

            for (int k = 0; k < house_num; k++) {
                temp_dis[k][chick] = INF;
            }
        }

        // get the min chicken distance
        for (int i = 0; i < house_num; i++) {
            int min = INF;
            for (int j = 0; j < chicken_num; j++) {
                if (min > temp_dis[i][j]) min = temp_dis[i][j];
            }
            temp_result += min;
        }
        if (result > temp_result) result = temp_result;
    }

    cout << result << "\n";

    return 0;
}
