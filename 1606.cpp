#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 55;
int n, m;
char map[maxn][maxn];
bool mark[maxn][maxn];
bool isIsolated = true;

struct direction
{
    int x, y;
}dir[]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void isFill(int x, int y)
{
    if (map[x][y] == '.')
    {
        isIsolated = false;
        return;
    }
    mark[x][y] = true;
    for (int k = 0; k < 4; ++k)
    {
        int tmpx = x + dir[k].x;
        int tmpy = y + dir[k].y;
        if (tmpx >= 1 && tmpx <= n && tmpy >= 1 && tmpy <= m && map[tmpx][tmpy] != '#' && !mark[tmpx][tmpy])
            isFill(tmpx, tmpy);
        if (!isIsolated) return;
    }
}

void FillMap(int x, int y)
{
    mark[x][y] = true;
    map[x][y] = '#';
    for (int k = 0; k < 4; ++k)
    {
        int tmpx = x + dir[k].x;
        int tmpy = y + dir[k].y;
        if (tmpx >= 1 && tmpx <= n && tmpy >= 1 && tmpy <= m && map[tmpx][tmpy] == '?' && !mark[tmpx][tmpy])
            FillMap(tmpx, tmpy);
    }
}

void Fill(int x, int y)
{
    mark[x][y] = true;
    for (int k = 0; k < 4; ++k)
    {
        int tmpx = x + dir[k].x;
        int tmpy = y + dir[k].y;
        if (tmpx >= 1 && tmpx <= n && tmpy >= 1 && tmpy <= m && map[tmpx][tmpy] != '#' && !mark[tmpx][tmpy])
            Fill(tmpx, tmpy);
    }
}

bool check()
{
    bool flag = true;
    memset(mark, 0, sizeof(mark));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (map[i][j] == '.')
            {
                Fill(i, j);
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (map[i][j] == '.' && !mark[i][j])
                return false;
        }
    }
    return true;
}

void isIso(int i, int j)
{
    isIsolated = true;
    memset(mark, 0, sizeof(mark));
    isFill(i, j);
    if (isIsolated)
    {
        memset(mark, 0, sizeof(mark));
        FillMap(i, j);
    }
}

int main()
{
    bool flag = false;
    int cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == '.') flag = true;
            if (map[i][j] == '?') ++cnt;
        }
    }

    if (!flag)
    {
        if (cnt >= 2)
        {
            cout << "Ambiguous" << endl;
            return 0;
        }
        else if (cnt == 0)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        else
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= m; ++j)
                {
                    if (map[i][j] == '?') cout << '.';
                    else cout << map[i][j];
                }
                cout << endl;
            }
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (map[i][j] == '?')
            {
                isIso(i, j);
                if (map[i][j] != '?') continue;

                bool flag1 = false, flag2 = false;
                map[i][j] = '.';
                flag1 = check();
                map[i][j] = '#';
                flag2 = check();

                if (flag1 && flag2)
                {
                    cout << "Ambiguous" << endl;
                    return 0;
                }
                if (!flag1 && !flag2)
                {
                    cout << "Impossible" << endl;
                    return 0;
                }
                map[i][j] = '.';
            }
        }
    }

    bool isImpossible = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (map[i][j] == '.')
            {
                isImpossible = false;
                break;
            }
    if (isImpossible)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << map[i][j];
        cout << endl;
    }

    return 0;
}
