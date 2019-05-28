#pragma warning (disable:4996)
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 105;
const int maxsize = maxn * maxn;
int map[maxn][maxn]{ 0 };
int mark[6];
int n, m;
int firstcnt = 0;
int mindistance = maxsize, colletcnt = 0;
int graph[6][6];

struct direction
{
	int x, y;
}dir[]{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

struct node
{
	int x, y, collet, cnt;
}queue[maxsize], st, colletpos[6];

int front = -1, rear = -1;

bool check(node tmp)
{
	if (tmp.x < 1 || tmp.x > n || tmp.y < 1 || tmp.y > m || map[tmp.x][tmp.y] == -1)
		return false;
	return true;
}
/*
bool check(node tmp)
{
	if (tmp.x < 1 || tmp.x > n || tmp.y < 1 || tmp.y > m || map[tmp.x][tmp.y] == -1 || tmp.collet <= mark[tmp.x][tmp.y])
		return false;
	return true;
}
*/
int bfs(node i, node j)
{
    front = rear = -1;
	node now, tmp;
	rear = (rear + 1) % maxsize;
	queue[rear] = i;
	while (front != rear)
	{
		front = (front + 1) % maxsize;
		now = queue[front];
		if (now.x == j.x && now.y == j.y)
		{
			return now.cnt;
		}

		for (int i = 0; i < 4; ++i)
		{
			tmp.x = now.x + dir[i].x;
			tmp.y = now.y + dir[i].y;
			tmp.collet = now.collet;
			tmp.cnt = now.cnt;
			if (check(tmp))
			{
				rear = (rear + 1) % maxsize;
				queue[rear] = tmp;
			}
		}
	}

    cout << -1;
    exit(0);
}
void dfs(int now, int dis, int cnt)
{
    if (cnt == colletcnt)
    {
        if (dis < mindistance) mindistance = dis;
        return;
    }
    mark[now] = true;
    for (int i = 0; i < colletcnt; ++i)
    {
        if (!mark[i]) dfs(i, dis + graph[now][i], cnt + 1);
    }
    mark[now] = false;
}
int main()
{
	memset(mark, -1, sizeof(mark));
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
            {
                colletpos[colletcnt].x = i;
                colletpos[colletcnt].y = j;
                colletpos[colletcnt].cnt = 0;
                colletpos[colletcnt].collet = 0;
				++colletcnt;
            }
			else if (map[i][j] == 2)
			{
				st.x = i;
				st.y = j;
				st.collet = 0;
				st.cnt = 0;
				//mark[i][j] = 0;
			}
		}
    
    for (int i = 0; i < colletcnt - 1; ++i)
        for (int j = i + 1; j < colletcnt; ++j)
        {
            int distance = bfs(colletpos[i], colletpos[j]);
            graph[i][j] = graph[j][i] = distance;
        }
    for (int i = 0; i < colletcnt; ++i)
    {
        dfs(i, bfs(st, colletpos[i]), 0);
    }
	cout << mindistance;
	return 0;
}