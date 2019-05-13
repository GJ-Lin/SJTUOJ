#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100005;
int pre[maxn], mid[maxn];
int N;
void postOrder(int pl, int pr, int ml, int mr)
{
	if (pl > pr) return;
	if (pl == pr)
	{
		printf("%d ", pre[pl]);
		return;
	}
	int pos;
	for (pos = ml; pos <= mr; ++pos)
		if (mid[pos] == pre[pl]) break;
	int len = pos - ml - 1;
	postOrder(pl + 1, pl + 1 + len, ml, ml + len);
	postOrder(pl + 1 + len + 1, pr, ml + len + 2, mr);

	printf("%d ", pre[pl]);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) scanf("%d", &pre[i]);
	for (int i = 0; i < N; ++i) scanf("%d", &mid[i]);
	postOrder(0, N - 1, 0, N - 1);
	return 0;
}