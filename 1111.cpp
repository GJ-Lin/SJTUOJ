#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1005;
const int maxsize = 30;
char pre[maxsize], mid[maxsize];
char arr[maxn]{'#'};
int N;

void build(int pl, int pr, int ml, int mr, int now)
{
    if (pl > pr)
    {
        arr[now] = '@';
        return;
    }
    if (pl == pr)
    {
        arr[now] = pre[pl];
        return;
    }
    arr[now] = pre[pl];
    
	int pos;
	for (pos = ml; pos <= mr; ++pos)
		if (mid[pos] == pre[pl]) break;
	int len = pos - ml - 1;
	build(pl + 1, pl + 1 + len, ml, ml + len, now << 1);
	build(pl + 1 + len + 1, pr, ml + len + 2, mr, now << 1 | 1);
}
int main()
{
	cin >> pre >> mid;
    N = strlen(pre);
	build(0, N - 1, 0, N - 1, 0);
    for (int i = 0; i < maxn; ++i)
    {
        if (arr[i] == '#') continue;
        if (arr[i] == '@') 
        {
            printf("NULL ");
            continue;
        }
        printf("%c ", arr[i]);
    }
	return 0;
}