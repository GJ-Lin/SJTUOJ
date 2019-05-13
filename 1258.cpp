#include <iostream>
#include <cstdio>
using namespace std;
#define LSON rt << 1
#define RSON rt << 1 | 1
typedef unsigned int ll;
const int maxn = 100005;
int arr[maxn];
int segT[maxn << 2];
int n;

inline int read()
{
    char ch = getchar();
    int sum = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        sum = (sum << 1) + (sum << 3) + ch - '0';
        ch = getchar();
    }
    return sum;
}

inline void pushup(int rt)
{
    segT[rt] = segT[LSON] + segT[RSON];
}

inline void update(int L, int l, int r, int rt)
{
    if (l == r)
    {
        ++segT[rt];
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, l, mid, LSON);
    else update(L, mid + 1, r, RSON);
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
    if (L <= mid) ans += query(L, R, l, mid, LSON);
    if (R > mid) ans += query(L, R, mid + 1, r, RSON);
    return ans;
}

int main()
{
    scanf("%d", &n);
    int max = 0;
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = read();
        if (arr[i] > max) max = arr[i];
    }
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        update(arr[i], 1, max, 1);
        sum += query(arr[i] + 1, max, 1, max, 1);
    }
    printf("%lld", sum);
    return 0;
}