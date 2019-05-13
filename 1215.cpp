#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 20005;

int heap[maxn];
int heapSize = 0;

void insert(int x)
{
	int hole = ++heapSize;
	for (; hole > 1 && x < heap[hole >> 1]; hole >>= 1)
		heap[hole] = heap[hole >> 1];
	heap[hole] = x;
}

void percolateDown(int hole)
{
	int child;
	int tmp = heap[hole];

	for (; hole << 1 <= heapSize; hole = child)
	{
		child = hole << 1;
		if (child != heapSize && heap[child + 1] < heap[child])
			++child;
		if (heap[child] < tmp)
			heap[hole] = heap[child];
		else break;
	}
	heap[hole] = tmp;
}

void del()
{
	heap[1] = heap[heapSize--];
	percolateDown(1);
}

int min()
{
    return heap[1];
}

int main()
{
    int M;
    cin >> M;
    char order[10];
    int x;
    while (M--)
    {
        cin >> order;
        switch (order[0])
        {
        case 'i':
            scanf("%d", &x);
            insert(x);
            break;
        case 'd':
            del();
            break;
        case 'm':
            printf("%d\n", min());
            break;
        default:
            break;
        }
    }
	return 0;
}