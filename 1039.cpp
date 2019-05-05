#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 30005;
int N;
int idx[1 << 15 + 5];

struct node
{
    int lson, rson;
    node() : lson(0), rson(0) {}
}arr[maxn];

void preOrder(int now)
{
    if (now == -1) return;
    idx[arr[now].lson] = idx[now] << 1;
    idx[arr[now].rson] = idx[now] << 1 | 1;
    preOrder(arr[now].lson);
    preOrder(arr[now].rson);
}

void postOrder(int now)
{
    if (now == -1) return;
    postOrder(arr[now].lson);
    postOrder(arr[now].rson);
    printf("%d ", now);
}

int main()
{
    return 0;
    scanf("%d", &N);
    int now, ls, rs;
    int root = -1;
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d%d%d", &now, &ls, &rs);
        if (root == -1) root = now;
        arr[now].lson = ls;
        arr[now].rson = rs;
    }

    idx[root] = 1;
    preOrder(root);
    for (int i = 1; i <= N; ++i)
        printf("%d ", idx[i]);
    putchar('\n');

    postOrder(root);

    return 0;
}