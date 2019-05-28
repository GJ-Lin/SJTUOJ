#include <iostream>
#include <cstring>
using namespace std;
const int maxnum = 2147483647;
int map[6][6];
int mark[6][6];
int ans = 0;

struct direction
{
    int x, y;
}dir[]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct point
{
    int x, y;
};

bool check(point tmp)
{
    if (tmp.x < 0 || tmp.x > 5 || tmp.y < 0 || tmp.y > 5 || mark[tmp.x][tmp.y])
        return false;
    return true;
}

void dfs(point st, point ed, int cost, int state)
{
    if (st.x == ed.x && st.y == ed.y)
    {
        if (cost < ans) ans = cost;
        return;
    }
    point tmp;
    for (int i = 0; i < 4; ++i)
    {
        tmp.x = st.x + dir[i].x;
        tmp.y = st.y + dir[i].y;
        if (check(tmp))
        {
            int tmpcost = map[tmp.x][tmp.y] * state;
            int tmpstate = tmpcost % 4 + 1;
            mark[tmp.x][tmp.y] = true;
            dfs(tmp, ed, cost + tmpcost, tmpstate);
            mark[tmp.x][tmp.y] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                cin >> map[i][j];
        memset(mark, 0, sizeof(mark));
        point st, ed;
        cin >> st.x >> st.y >> ed.x >> ed.y;
        mark[st.x][st.y] = true;
        ans = maxnum;
        dfs(st, ed, 0, 1);
        cout << ans << endl;
    }
    return 0;
}
