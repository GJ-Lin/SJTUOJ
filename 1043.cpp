#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000005;
int N;
int queue[maxn];
int front = -1, rear = 0;

struct node
{
	int lson, rson;
	node() : lson(-1), rson(-1) {}
}arr[maxn];

bool levelOrder()
{
	int now;
	queue[0] = 0;
	while (front != rear && front < N - 1)
	{
		now = queue[++front];
		if (now == -1) return false;
		queue[++rear] = arr[now].lson;
		queue[++rear] = arr[now].rson;
	}
	return true;
}

int main()
{
	scanf("%d", &N);
	int x;
	for (int i = 1; i < N; ++i)
	{
		scanf("%d", &x);
		if (arr[x].lson == -1) arr[x].lson = i;
		else arr[x].rson = i;
	}
	if (levelOrder()) printf("true");
	else printf("false");
	return 0;
}