#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long ll;
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
const int maxn = 100005;
ll segT[maxn << 2];
ll tag[maxn << 2];
ll arr[maxn];

inline void pushup(int rt)
{
    segT[rt] = segT[lson] + segT[rson];
}

inline void pushdown(int rt, int ln, int rn)
{
    if (tag[rt])
    {
        segT[lson] += tag[rt] * ln;
        segT[rson] += tag[rt] * rn;
        tag[lson] += tag[rt];
        tag[rson] += tag[rt];
        tag[rt] = 0;
    }
}
inline void build(int l, int r, int rt)
{
    if (l == r)
    {
        segT[rt] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    pushup(rt);
}

inline ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        return segT[rt];
    }
    int mid = (l + r) >> 1;
    ll ans = 0;
    pushdown(rt, mid - l + 1, r - mid);
    if (L <= mid) ans += query(L, R, l, mid, lson);
    if (R > mid) ans += query(L, R, mid + 1, r, rson);
    return ans;
}

inline void update(int L, int R, int C, int l, int r, int rt)
{
    if (l == r)
    {
        segT[rt] += C;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(rt, mid - l + 1, r - mid);
    if (L <= mid) update(L, R, C, l, mid, lson);
    if (R > mid) update(L, R, C, mid + 1, r, rson);
    pushup(rt);
}

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(0); 
    std::cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i]; 
    build(1, n, 1);
    char order;
    ll a, b, c;
    while (m--)
    {
        cin >> order;
        if (order == 'Q')
        {
            cin >> a >> b;
            cout << query(a, b, 1, n, 1) << '\n';
        }
        else
        {
            cin >> a >> b >> c;
            update(a, b, c, 1, n, 1);
        }
    }
    return 0;
}