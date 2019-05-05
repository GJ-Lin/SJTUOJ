#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 35;
int n;
int arr[maxn];
int dp[maxn][maxn];
int root[maxn][maxn];

int build(int l, int r)
{
    if (l > r) return 1;

    if (dp[l][r]);
    else if (l == r)
    {
        dp[l][r] = arr[l];
        root[l][r] = l;
    }
    else
    {
        for (int i = l; i <= r; ++i)
        {
            int tmp = build(l, i - 1) * build(i + 1, r) + arr[i];
            if (tmp > dp[l][r])
            {
                dp[l][r] = tmp;
                root[l][r] = i;
            }
        }
    }
    return dp[l][r];
}
void preOrder(int l, int r)
{
    if (l > r) return;
    printf("%d ", root[l][r]);
    preOrder(l, root[l][r] - 1);
    preOrder(root[l][r] + 1, r);
}
int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    cout << build(1, n) << endl;
    preOrder(1, n);
    return 0;
}