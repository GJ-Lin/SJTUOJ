#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 105;
const int maxsize = maxn * maxn;
int n, m;
int map[maxn][maxn];
int mark[maxn][maxn];
int markpoint[6];
int minsum = maxsize;
 
struct direction
{
	int x, y;
}dir[]{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
 
struct node
{
    int num, distance;
    node *next;
    node(int _num = 0, int _distance = 0, node *_next = NULL) : num(_num), distance(_distance), next(_next) {}
};
node *head;
 
struct point
{
    int x, y;
    int step, type;
    bool operator==(point &other)
    {
        if (x == other.x && y == other.y)
            return true;
        return false;
    }
    point(int _x = 0, int _y = 0, int _step = 0) : x(_x), y(_y), step(_step), type(0) {}
}collect[6];
 
bool check(point tmp)
{
    if (tmp.x < 1 || tmp.x > n || tmp.y < 1 || tmp.y > m) return false;
    return true;
}
int bfs(point &begin, point &end)
{
    point queue[maxsize];
    int front = -1, rear = -1;
    memset(mark, false, sizeof(mark));
    begin.step = 0;
    queue[++rear] = begin;
    point now, next;
    while (front < rear)
    {
        now = queue[++front];
        mark[now.x][now.y] = true;
        for (int i = 0; i < 4; ++i)
        {
            next.x = now.x + dir[i].x;
            next.y = now.y + dir[i].y;
            if (check(next))
            {
                if (mark[next.x][next.y])
                    continue;
                next.type = map[next.x][next.y];
                mark[next.x][next.y] = true;
                if (next.type != -1)
                {
                    next.step = now.step + 1;
                    if (next.x == end.x && next.y == end.y)
                        return next.step;
                    queue[++rear] = next;
                }
            }
        }
    }
    return -1;
}
 
void dfs(int start, int count, int dis, int cnt)
{
    if (markpoint[start] == 1)
        return;
    markpoint[start] = 1;
    if (count == cnt)
    {
        if (dis < minsum)
            minsum = dis;
    }
    else
    {
        for (node *tmp = head[start].next; tmp; tmp = tmp->next)
            dfs(tmp->num, count + 1, dis + tmp->distance, cnt);
    }
    markpoint[start] = 0;
}
 
int main()
{
    int size = 0;
    cin >> n >> m;
    int x;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> x;
            map[i][j] = x;
            if (x == 1)
            {
                ++size;
                collect[size].x = i;
                collect[size].y = j;
            }
            else if (x == 2)
            {
                collect[0].x = i;
                collect[0].y = j;
            }
        }
    }
 
    memset(markpoint, 0, sizeof(markpoint));
    memset(mark, 0, sizeof(mark));
    head = new node[size + 2];
    node *tmp;
    for (int i = 1; i <= size; ++i)
    {
        if (bfs(collect[0], collect[i]) == -1)
        {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i <= size; ++i)
    {
        memset(mark, 0, sizeof(mark));
        for (int j = 0; j <= size; ++j)
        {
            if (j == i)
                continue;
            int noe = bfs(collect[i], collect[j]);
            tmp = new node(j, noe, head[i].next);
            head[i].next = tmp;
        }
    }
    dfs(0, 0, 0, size);
    cout << minsum;
}