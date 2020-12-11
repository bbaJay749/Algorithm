#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int N;
    vector<long long int> dp(1000001, 0);
    dp[2] = 1;
    
    cin >> N;

    for(int i = 3; i <= N; i++) 
    {
            dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % 1000000000;
    }

    cout << dp[N] << endl;

    return 0;
}
