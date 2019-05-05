#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000005;
int N;
bool mark[maxn];
int queue[maxn];
int front = -1, rear = 0;

struct node
{
    int lson, rson;
    node() : lson(0), rson(0) {}
}arr[maxn];

bool levelOrder()
{
    int now;
    int root = 1;
    while (mark[root]) ++root;
    queue[0] = root;
    while (front != rear && front < N - 1)
    {
        now = queue[++front];
        if (now == 0) return false;
        queue[++rear] = arr[now].lson;
        queue[++rear] = arr[now].rson;
    }
    return true;
}

int main()
{
    memset(mark, 0, sizeof(mark));
    scanf("%d", &N);
    int ls, rs;
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d%d", &ls, &rs);
        mark[ls] = mark[rs] = true;
        arr[i].lson = ls;
        arr[i].rson = rs;
    }
    if (levelOrder()) printf("Y");
    else printf("N");
    return 0;
}