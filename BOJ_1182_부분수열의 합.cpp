#include<iostream>
#include<vector>

using namespace std;

int n, s, ans = 0;
vector<int> nums;

void dfs(int sum, int idx, int leng) {
    sum += nums[idx];

    if (idx >= n)
        return;

    if (sum == s && leng >= 1)
        ans++;

    dfs(sum, idx + 1, leng + 1);
    dfs(sum - nums[idx], idx + 1, leng);
}

int main(void) {
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    dfs(0, 0, 1);
    cout << ans;
    return 0;
}
