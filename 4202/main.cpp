#include <iostream>
#include <cstdio>
using namespace std;

const int MINNUM = -2147483648;
int dp[100005][3][2];
int n;
int sum[4];

struct tree
{
    int a, b, c;
}arr[100005];

inline int Max(int n1, int n2)
{
    return (n1 > n2 ? n1 : n2);
}

int Maxsum(int n1, int n2, int n3, int n4)
{
    return Max(Max(n1, n2), Max(n3, n4));
}

void Evaluate()
{
    for (int i = 1; i < n; ++i)
    {
        dp[i][0][0] = arr[i].a + Max(dp[i - 1][1][1], dp[i - 1][2][1]);
        dp[i][1][0] = arr[i].b + dp[i - 1][2][1];
        dp[i][1][1] = arr[i].b + dp[i - 1][0][0];
        dp[i][2][1] = arr[i].c + Max(dp[i - 1][1][0], dp[i - 1][0][0]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c);
    }

    dp[0][0][0] = arr[0].a;
    dp[0][1][0] = dp[0][1][1] = dp[0][2][1] = MINNUM;
    Evaluate();
    sum[0] = Max(dp[n - 1][1][1], dp[n - 1][2][1]);

    dp[0][1][0] = arr[0].b;
    dp[0][0][0] = dp[0][1][1] = dp[0][2][1] = MINNUM;
    Evaluate();
    sum[1] = dp[n - 1][2][1];

    dp[0][1][1] = arr[0].b;
    dp[0][0][0] = dp[0][1][0] = dp[0][2][1] = MINNUM;
    Evaluate();
    sum[2] = dp[n - 1][0][0];

    dp[0][2][1] = arr[0].c;
    dp[0][1][0] = dp[0][1][0] = dp[0][1][1] = MINNUM;
    Evaluate();
    sum[3] = Max(dp[n - 1][0][0], dp[n - 1][1][0]);

    printf("%d\n", Maxsum(sum[0], sum[1], sum[2], sum[3]));
}
