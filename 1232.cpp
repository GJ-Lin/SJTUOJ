#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1005;
int djset[maxn * maxn / 2];
int n, a, b;
int stack[maxn * maxn / 2];
int top = -1;
int mark[maxn * maxn / 2];

int Find(int x)
{
	if (djset[x] < 0) return x;
	return djset[x] = Find(djset[x]);
}

void Union(int i, int j)
{
	int root1 = Find(i), root2 = Find(j);
	if (root1 == root2) return;
	if (djset[root1] > djset[root2])
	{
		djset[root2] += djset[root1];
		djset[root1] = root2;
	}
	else
	{
		djset[root1] += djset[root2];
		djset[root2] = root1;
	}
}

void trail(int st, int ed)
{
	stack[++top] = st;
	mark[st] = true;
	if (st == ed)
	{
		for (int i = 0; i <= top; ++i)
			printf("%d ", stack[i]);
		exit(0);
	}
	int rt = Find(st);
	int line, first, last;
	line = ceil((1 + sqrt(1 + 8 * st)) / 2) - 1;
	first = line * (line - 1) / 2 + 1;
	last = line * (line + 1) / 2;

	if (st != first && rt == Find(st - line) && !mark[st - line])
		trail(st - line, ed);
	if (st != last && rt == Find(st - line + 1) && !mark[st - line + 1])
		trail(st - line + 1, ed);
	if (line != n)
	{
		if (rt == Find(st + line) && !mark[st + line])
			trail(st + line, ed);
		if (rt == Find(st + line + 1) && !mark[st + line + 1])
			trail(st + line + 1, ed);
	}
	mark[st] = false;
	--top;
}

int main()
{
	memset(djset, -1, sizeof(djset));
	memset(mark, false, sizeof(mark));
	cin >> n >> a >> b;
	int num, dir;
	int line, first, last;
	while (cin >> num >> dir)
	{
		line = ceil((1 + sqrt(1 + 8 * num)) / 2) - 1;
		first = line * (line - 1) / 2 + 1;
		last = line * (line + 1) / 2;
		//cout << line << ' ' << first << ' ' << last << endl;
		switch (dir)
		{
		case 0:
			if (num == first) break;
			Union(num, num - line);
			break;
		case 1:
			if (num == last) break;
			Union(num, num - line + 1);
			break;
		case 2:
			if (line == n) break;
			Union(num, num + line);
			break;
		case 3:
			if (line == n) break;
			Union(num, num + line + 1);
			break;
		default:
			break;
		}
		if (Find(a) == Find(b))
		{
			trail(a, b);
			return 0;
		}
	}
}