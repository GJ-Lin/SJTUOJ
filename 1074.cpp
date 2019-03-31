#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 2000;
char x;
int M, N;
int field[MAXNUM][MAXNUM]{};
int sum[MAXNUM][MAXNUM]{};
int ans[MAXNUM][MAXNUM]{};
int maxk = 0;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> x;
            field[i][j] = (x == 'X' ? 1 : 0);
            sum[i][j] = field[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 2; j <= M; ++j)
        {
            if (field[i][j]) continue;

            for (int k = ans[i - 1][j] + 1; k >= 1; --k)
            {
                if (i - k + 1 <= 0 || j - 2 * k + 1 <= 0) continue;
                if (sum[i][j] - sum[i - k][j] - sum[i][j - 2 * k] + sum[i - k][j - 2 * k] == 0)
                {
                    ans[i][j] = k;
                    if (k > maxk) maxk = k;
                    break;
                }
            }
        }
    }
    printf("%d", 2 * maxk * maxk);
    return 0;
}