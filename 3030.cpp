#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 1005;
struct mushroom
{
    int time;
    int value;
}arr[105];
int dp[MAXNUM][MAXNUM] = {};

inline int Max(const int &a, const int &b)
{
    return a > b ? a : b;
}

int main()
{
    int T, M;
    scanf("%d%d", &T, &M);
    for (int i = 0; i < M; ++i)
        scanf("%d%d", &arr[i].time, &arr[i].value);
    
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 0; j < arr[i].time; ++j)
            dp[i][j] = dp[i][j - 1];
        for (int j = arr[i].time; j <= T; ++j)
            dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - arr[i].time] + arr[i].value);
    }
    printf("%d", dp[M][T]);
    return 0;  
}