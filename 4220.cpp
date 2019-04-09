#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXNUM = 300005;
int n, q;
int arr[MAXNUM], dpmax[MAXNUM][21];

inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return X;
}

inline void write(int x) {
  int y = 10, len = 1;
  while (y <= x) {
    y *= 10;
    len++;
  }
  while (len--) {
    y /= 10;
    putchar(x / y + 48);
    x %= y;
  }
}

inline int Max(int a, int b)
{
	return a > b ? a : b;
}

int searchMax(int i, int j)
{
	int k = int(log(double(j - i + 1)) / log(2.0));
	return Max(dpmax[i][k], dpmax[j - (1 << k) + 1][k]);
}

void RMQ(int N)
{
	for (int j = 1; j <= 20; ++j)
		for (int i = 1; i <= N; ++i)
			if (i + (1 << j) - 1 <= N)
			{
				dpmax[i][j] = Max(dpmax[i][j - 1], dpmax[i + (1 << (j - 1))][j - 1]);
			}
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
	{
		arr[i] = read();
		dpmax[i][0] = arr[i];
	}
	RMQ(n);
	int l, r, x;
	while (q--)
	{
		l = read();
		r = read();
		write(searchMax(l, r));
		putchar('\n');
	}
	return 0;
}
