#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 3340;
const int MOD = 19301;
int dp[maxn];
int n;
int main()
{
    cin >> n;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        for (int j = 0; j <= i - 2; ++j)
            dp[i] = (dp[i] + dp[j] * dp[i - 2 - j]) % MOD;
    }
    cout << dp[n];
    return 0;
}
