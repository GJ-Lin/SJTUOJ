#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 10005;
int n;
int arr[maxn];

void percolateDown(int hole)
{
    int child;
    int tmp = arr[hole];

    for (; hole << 1 <= n; hole = child)
    {
        child = hole << 1;
        if (child != n && arr[child + 1] < arr[child])
            ++child;
        if (arr[child] < tmp)
            arr[hole] = arr[child];
        else break;
    }
    arr[hole] = tmp;
}

void buildHeap()
{
    for (int i = n >> 1; i > 0; --i)
        percolateDown(i);
}

void enQueue(int x)
{
    int hole = ++n;
    for (; hole > 1 && x < arr[hole >> 1]; hole >>= 1)
        arr[hole] = arr[hole >> 1];
    arr[hole] = x;
}

int deQueue()
{
    int tmp;
    tmp = arr[1];
    arr[1] = arr[n--];
    percolateDown(1);
    return tmp;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    buildHeap();
    int t1, t2;
    int sum = 0;
    while (n)
    {
        t1 = deQueue();
        if (!n) break;
        t2 = deQueue();
        sum += t1 + t2;
        if (!n) break;
        enQueue(t1 + t2);
    }
    printf("%d\n", sum);
    return 0;
}