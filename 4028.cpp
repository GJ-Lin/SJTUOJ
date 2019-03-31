#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 1005;
int image[MAXNUM][MAXNUM]{};
int paper[MAXNUM][MAXNUM]{};

struct point
{
    int x, y;
}seal[MAXNUM];

void Solve()
{
    int m, n, p, q;
    scanf("%d%d%d%d", &m, &n, &p, &q);
    int img_cnt = 0, seal_cnt = 0;
    int tmp;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &image[i][j]);
            if (image[i][j]) ++img_cnt;
        }
    for (int i = 1; i <= p; ++i)
        for (int j = 1; j <= q; ++j)
        {
            scanf("%d", &tmp);
            if (tmp)
            {
                ++seal_cnt;
                seal[seal_cnt].x = i;
                seal[seal_cnt].y = j;
            }
        }


    if (img_cnt % seal_cnt != 0)
    {
        printf("No\n");
        return;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (image[i][j])
            {
                for (int k = 2; k <= seal_cnt; ++k)
                {
                    int x = i + seal[k].x - seal[1].x;
                    int y = j + seal[k].y - seal[1].y;
                    if (x < 1 || x > m || y < 1 || y > n || !image[x][y])
                    {
                        printf("No\n");
                        return;
                    }
                    image[x][y] = 0;
                }
            }
        }
    }
    printf("Yes\n");
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        Solve();
    return 0;
}