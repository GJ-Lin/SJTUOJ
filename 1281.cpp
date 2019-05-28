#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 105;
const int maxsize = maxn * maxn;
int map[maxn][maxn];
int markmap[maxn][maxn];
int m, n;

struct Dir
{
    int x, y;
}dir[8];

struct step
{
    int x, y, size;
}queue[4 * maxsize], st, ed;
int front, rear;

bool check(step tmp)
{
    if (tmp.x < 1 || tmp.x > m || tmp.y < 1 || tmp.y > n || map[tmp.x][tmp.y] == 0 || map[tmp.x][tmp.y] == 2 || markmap[tmp.x][tmp.y] >= tmp.size) return false;
    return true;
}

void bfs()
{
    step now, tmp;
    front = rear = -1;
    queue[++rear] = st;
    while (front < rear)
    {
        now = queue[++front];
        if (now.x == ed.x && now.y == ed.y)
        {
            cout << now.size;
            return;
        }
        for (int i = 0; i < 8; ++i)
        {
            tmp.x = now.x + dir[i].x;
            tmp.y = now.y + dir[i].y;
            tmp.size = now.size + 1;
            if (check(tmp))
            {
                queue[++rear] = tmp;
                markmap[tmp.x][tmp.y] = tmp.size;
            }
        }
    }
}
int main()
{
    memset(markmap, -1, sizeof(markmap));
    int m1, m2;
    cin >> m >> n >> m1 >> m2;
    dir[0].x = m1, dir[0].y = m2;
    dir[1].x = m1, dir[1].y = -m2;
    dir[2].x = -m1, dir[2].y = m2;
    dir[3].x = -m1, dir[3].y = -m2;
    dir[4].x = m2, dir[4].y = m1;
    dir[5].x = m2, dir[5].y = -m1;
    dir[6].x = -m2, dir[6].y = m1;
    dir[7].x = -m2, dir[7].y = -m1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 3)
            {
                st.x = i;
                st.y = j;
                st.size = 0;
            }
            if (map[i][j] == 4)
            {
                ed.x = i;
                ed.y = j;
            }
        }
    bfs();
    return 0;
}