#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 105;
int m, n;
int map[maxn][maxn];
bool book[maxn][maxn];
bool mark[maxn][maxn];
long long ans = 0;

struct direction
{
    int x, y;
} dir[]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct point
{
    int x = 0, y = 0;
}queue[maxn * maxn];
int front, rear;

bool check(point tmp)
{
    if (tmp.x < 0 || tmp.x > m + 1 || tmp.y < 0 || tmp.y > n + 1)
        return false;
    return true;
}

bool isFill()
{
    for (int i = 2; i <= m - 1; ++i)
        for (int j = 2; j <= n - 1; ++j)
            if (!book[i][j]) return false;
    return true;
}

void fill(int x, int y)
{
    point st;
    st.x = x;
    st.y = y;
    queue[++rear] = st;
    point now, tmp;
    while (front < rear)
    {
        now = queue[++front];
        for (int k = 0; k < 4; ++k)
        {
            tmp.x = now.x + dir[k].x;
            tmp.y = now.y + dir[k].y;
            if (check(tmp))
            {
                if (!book[tmp.x][tmp.y] && map[now.x][now.y] <= map[tmp.x][tmp.y])
                {
                    book[tmp.x][tmp.y] = true;
                    queue[++rear] = tmp;
                }
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    memset(map, 0, sizeof(map));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> map[i][j];

    memset(book, 0, sizeof(book));
    fill(0, 0);
    for (int height = 1; height <= 10000; ++height)
    {
        for (int i = 2; i <= m - 1; ++i)
            for (int j = 2; j <= n - 1; ++j)
                if (!book[i][j] && height > map[i][j])
                {
                    ++ans;
                    ++map[i][j];
                    for (int k = 0; k < 4; ++k)
                    {
                        int tmpx = i + dir[k].x;
                        int tmpy = j + dir[k].y;
                        if (map[tmpx][tmpy] <= map[i][j] && book[tmpx][tmpy])
                        {
                            fill(tmpx, tmpy);
                            break;
                        }
                    }
                }
        if (isFill())
            break;
    }
    cout << ans << endl;
    return 0;
}
