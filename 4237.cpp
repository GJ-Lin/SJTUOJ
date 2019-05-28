#include <iostream>
#include <cstring>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long ll;
const int maxn = 200005;
char tag[maxn << 2][105];
int cnt[maxn << 2]{ 0 };
int X, Y;

inline void pushdown(int rt)
{
	for (int i = 0; i < cnt[rt]; ++i)
	{
		tag[lson][cnt[lson]++] = tag[rt][i];
		tag[rson][cnt[rson]++] = tag[rt][i];
	}
	cnt[rt] = 0;
}

void update(int L, int R, int C, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		tag[rt][cnt[rt]++] = C;
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) update(L, R, C, l, mid, lson);
	if (R > mid) update(L, R, C, mid + 1, r, rson);
}

void queryX(int x, int l, int r, int rt)
{
	if (l == r)
	{
		X = rt;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (x <= mid) return queryX(x, l, mid, lson);
	else return queryX(x, mid + 1, r, rson);
}

void queryY(int x, int l, int r, int rt)
{
	if (l == r)
	{
		Y = rt;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (x <= mid) return queryY(x, l, mid, lson);
	else return queryY(x, mid + 1, r, rson);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int order, l, r, k, x, y;
	while (m--)
	{
		cin >> order;
		if (order == 0)
		{
			cin >> l >> r >> k;
			update(l, r, k, 1, n, 1);
		}
		else
		{
			cin >> x >> y;
			queryX(x, 1, n, 1);
			queryY(y, 1, n, 1);
			if (cnt[X] != cnt[Y])
				cout << "NO" << '\n';
			else
			{
				bool flag = true;
				for (int i = 0; i < cnt[X]; ++i)
					if (tag[X][i] != tag[Y][i])
					{
						cout << "NO" << '\n';
						flag = false;
						break;
					}
				if (flag)
				{
					cout << "YES" << '\n';
					cnt[X] = cnt[Y] = 0;
				}
			}
		}
	}
	return 0;
}