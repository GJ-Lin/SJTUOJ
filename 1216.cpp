#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 20005;
int M;
int arr[maxn];
int currentSize = 0;

void insert()
{
    int x, hole = ++currentSize;
    scanf("%d", &x);
    for (; hole > 1 && x < arr[hole >> 1]; hole >>= 1)
        arr[hole] = arr[hole >> 1];
    arr[hole] = x;
}

void find()
{
    int x;
    scanf("%d", &x);
    int min = 2147483647, idx = 0;
    for (int i = 1; i <= currentSize; ++i)
    {
        if (arr[i] <= x) continue;
        if (arr[i] < min)
        {
            idx = i;
            min = arr[i];
        }
    }
    printf("%d\n", idx);
}

void decrease()
{
    int hole, v;
    scanf("%d%d", &hole, &v);
    int x = arr[hole] - v;
    for (; hole > 1 && x < arr[hole >> 1]; hole >>= 1)
        arr[hole] = arr[hole >> 1];
    arr[hole] = x;
}

int main()
{
    scanf("%d", &M);
    char order[10];
    while (M--)
    {
        scanf("%s", &order);
        switch (order[0])
        {
        case 'i':
            insert();
            break;
        case 'f':
            find();
            break;
        case 'd':
            decrease();
            break;
        default:
            break;
        }
    }
    return 0;
}