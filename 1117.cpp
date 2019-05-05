#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100005;
int balance = 0;
bool mark[maxn]{ false };
int cnt[maxn]{ 0 };

int stack[maxn];
int top = -1;

int heap[maxn];
int heapSize = 0;

class seqList
{
public:
	int* data;
	int maxSize;
	int currentSize;
	seqList(int initSize = 2)
	{
		data = new int[initSize];
		maxSize = initSize;
		currentSize = 0;
	}
	void doubleSpace()
	{
		int* tmp = data;
		maxSize *= 2;
		data = new int[maxSize];
		for (int i = 0; i < currentSize; ++i)
			data[i] = tmp[i];
		delete[] tmp;
	}
	void push(int value)
	{
		if (currentSize == maxSize)
			doubleSpace();
		data[currentSize++] = value;
	}
}arr[maxn];

void pushHeap(int x)
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

int popHeap()
{
	int tmp = heap[1];
	heap[1] = heap[heapSize--];
	percolateDown(1);
	return tmp;
}

int main()
{
	char ch;
	int now;
	int N = 0;
	int x;

	scanf("%c", &ch);
	++balance;
	++N;
	scanf("%d", &x);
	stack[++top] = x;
	now = stack[top];

	while (balance)
	{
		scanf("%c", &ch);
		if (ch == ' ') continue;
		if (ch == '(')
		{
			scanf("%d", &x);
			arr[x].push(now);
			arr[now].push(x);
			++cnt[x];
			++cnt[now];
			now = stack[++top] = x;
			++balance;
			++N;
		}
		else if (ch == ')')
		{
			--balance;
			if (balance) now = stack[--top];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (cnt[i] == 1)
			pushHeap(i);
	}
	while (--N)
	{
		int x = popHeap();
		mark[x] = true;
		int tmp;
		for (int i = 0; i < arr[x].currentSize; ++i)
		{
			tmp = arr[x].data[i];
			--cnt[tmp];
			if (!mark[tmp])
			{
				printf("%d ", tmp);
				if (cnt[tmp] == 1)
					pushHeap(tmp);
				break;
			}
		}
	}
	return 0;
}