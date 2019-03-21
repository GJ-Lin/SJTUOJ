#include <iostream>
using namespace std;
const int P = 1e9 + 7;
const int MAXNUM = 1000 + 5;
int dp[MAXNUM];

void init()
{
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < MAXNUM; ++i)
    {
        dp[i] = 0;
        int j = (i & 1) ? 1 : 0;
        for (; j <= i; j += 2)
        {
            dp[i] += dp[(i - j) / 2];
            dp[i] %= P;
        }
    }
}

int main()
{
    init();
    int N;
    cin >> N;
    cout << dp[N];
    return 0;
}
