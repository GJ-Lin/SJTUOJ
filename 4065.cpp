#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 305;
const int maxsize = 2 * maxn * maxn;
int map[maxn][maxn];
int marklife[maxn][maxn];
int n, m;

struct dirction
{
    int x, y;
}dir[4]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct node
{
    int x, y, cnt, life;
    void create(int _x, int _y, int _cnt, int _life)
    {
        x = _x; y = _y; cnt = _cnt; life = _life;
    }
}queue[maxsize + 5];
int front = 0, rear = 0;

bool check(node tmp)
{
    if (map[tmp.x][tmp.y] == 0 || tmp.life <= marklife[tmp.x][tmp.y]) return false;
    return true;
}

int main()
{
    node begin, end;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2)
                begin.create(i, j, 0, 6);
            else if (map[i][j] == 3)
                end.create(i, j, 0, 0);
        }

    node now, tmp;
    rear = (rear + 1) % maxsize;
    queue[rear]= begin;
    while (front != rear)
    {
        front = (front + 1) % maxsize;
        now = queue[front];
        if (now.life == 0) continue;
        if (now.x == end.x && now.y == end.y)
        {
            printf("%d", now.cnt);
            return 0;
        }
        for (int i = 0; i < 4; ++i)
        {
            tmp.create(now.x + dir[i].x, now.y + dir[i].y, now.cnt + 1, now.life - 1);
            if (check(tmp))
            {
                if (map[tmp.x][tmp.y] == 4)
                    tmp.life = 6;
                rear = (rear + 1) % maxsize;
                queue[rear] = tmp;
                marklife[tmp.x][tmp.y] = tmp.life;
            }
        }
    }
    printf("-1");
    return 0;
}