#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 100005;
int N;
bool mark[maxn];
int queue[maxn];
int front = -1, rear = 0;

struct node
{
	int child, bro;
    int value;
	node() : child(0), bro(0) {}
}arr[maxn];

void preOrder(int now)
{
    if (now == 0) return;
    printf("%d ", arr[now].value);
    preOrder(arr[now].child);
    preOrder(arr[now].bro);
}

void midOrder(int now)
{
    if (now == 0) return;
    midOrder(arr[now].child);
    printf("%d ", arr[now].value);
    midOrder(arr[now].bro);
}

void levelOrder(int root)
{
    int now;
    queue[0] = root;
    while (front != rear)
    {
        now = queue[++front];
        printf("%d ", arr[now].value);
        if (arr[now].child) queue[++rear] = arr[now].child;
        while (arr[now].bro)
        {
            now = arr[now].bro;
            printf("%d ", arr[now].value);
            if (arr[now].child) queue[++rear] = arr[now].child;
        }
    }
}
int main()
{
    memset(mark, 0, sizeof(mark));
    scanf("%d", &N);

    int _child_, _bro_, _value_;
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d%d%d", &_child_, &_bro_, &_value_);
        mark[_child_] = mark[_bro_] = true;
        arr[i].child = _child_;
        arr[i].bro = _bro_;
        arr[i].value = _value_;
    }

    int root = 1;
    while (mark[root]) ++root;

    preOrder(root);
    putchar('\n');

    midOrder(root);
    putchar('\n');

    levelOrder(root);

    return 0;
}