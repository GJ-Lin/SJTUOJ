#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 2100;
int image[MAXNUM][MAXNUM] = {};
int nowcnt = 0, mincnt = 1000005;
inline int Max(const int &a, const int &b)
{
    return (a > b ? a : b);
}

inline int Min(const int &a, const int &b)
{
    return (a < b ? a : b);
}

int calc(int blocks, int k)
{
    int black, white;
    int sum = 0;
    for (int i = 1; i <= blocks; ++i)
    {
        for (int j = 1; j <= blocks; ++j)
        {
            black = image[k * i][k * j] - image[k * (i - 1)][k * j] - image[k * i][k * (j - 1)] + image[k * (i - 1)][k * (j - 1)];
            sum += Min(black, k * k - black);
        }
    }
    return sum;
}

int main()
{
    int n, m;
    char tmp[1005];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        
        scanf("%s", &tmp);
        for (int j = 1; j <= m; ++j)
        {
            image[i][j] = tmp[j - 1] - '0' + image[i - 1][j] + image[i][j - 1] - image[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = m + 1; j < MAXNUM; ++j)
            image[i][j] = image[i - 1][j] + image[i][j - 1] - image[i - 1][j - 1];
    }
    for (int i = n + 1; i < MAXNUM; ++i)
    {
        for (int j = 1; j < MAXNUM; ++j)
            image[i][j] = image[i - 1][j] + image[i][j - 1] - image[i - 1][j - 1];
    }

    int maxlen = Max(n, m);

    for (int k = 2; k <= maxlen; ++k)
    {
        int blocks = 0;

        if (n > m)
        {
            if (n % k == 0) blocks = n / k;
            else blocks = n / k + 1;
        }
        else
        {
            if (m % k == 0) blocks = m / k;
            else blocks = m / k + 1;
        }

        nowcnt = calc(blocks, k);
        if (nowcnt < mincnt) mincnt = nowcnt;
    }
    printf("%d", mincnt);
    return 0;
}