#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100005;
bool mark[maxn]{false};
int n;
int root;
int queue[maxn];
int front = -1, rear = -1;
struct Node
{
    int lson = 0, rson = 0, value;
}arr[maxn];

void levelOrder()
{
    int now;
    queue[++rear] = root;
    while (front < rear)
    {
        now = queue[++front];
        printf("%d ", arr[now].value);
        if (arr[now].lson) queue[++rear] = arr[now].lson;
        if (arr[now].rson) queue[++rear] = arr[now].rson;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &arr[i].lson, &arr[i].rson, &arr[i].value);
        mark[arr[i].lson] = mark[arr[i].rson] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!mark[i])
        {
            root = i;
            break;
        }
    }
    levelOrder();
    return 0;
}