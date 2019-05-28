#include <iostream>
#include <cstring>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long ll;
const int maxn = 200005;
const int P = 31;
ll tag[maxn << 2];
ll pow[maxn];
int cnt[maxn << 2]{ 0 };
int X, Y;

void init()
{
    memset(tag, 1, sizeof(tag));
    pow[0] = 1;
    for (int i = 1; i < maxn; ++i)
        pow[i] = pow[i - 1] * P;
}

inline void pushdown(int rt)
{
    if (cnt[rt])
    {
        tag[lson] = tag[lson] * pow[cnt[rt]] + tag[rt];
        tag[rson] = tag[rson] * pow[cnt[rt]] + tag[rt];
        cnt[lson] += cnt[rt];
        cnt[rson] += cnt[rt];
        tag[rt] = 1;
        cnt[rt] = 0;
    }
}

void update(int L, int R, int C, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        tag[rt] = tag[rt] * P + C;
        ++cnt[rt];
        return;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, C, l, mid, lson);
    if (R > mid) update(L, R, C, mid + 1, r, rson);
}

ll queryX(int x, int l, int r, int rt)
{
    if (l == r)
    {
        X = rt;
        return tag[rt];
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (x <= mid) return queryX(x, l, mid, lson);
    else return queryX(x, mid + 1, r, rson);
}

ll queryY(int x, int l, int r, int rt)
{
    if (l == r)
    {
        Y = rt;
        return tag[rt];
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
            if (queryX(x, 1, n, 1) == queryY(y, 1, n, 1))
            {
                cout << "YES" << '\n';
                tag[X] = tag[Y] = 1;
                cnt[X] = cnt[Y] = 0;
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}