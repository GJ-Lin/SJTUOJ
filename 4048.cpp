#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100005;
int n;
int pos[maxn];
int sum[maxn];
int tmparr[maxn];
struct leg
{
    int l, d;
    bool operator>=(const leg& other)
    {
        if (this->l > other.l) return true;
        else if (this->l == other.l && this->d >= other.d) return true;
        return false;
    }
    bool operator<=(const leg & other)
    {
        if (this->l < other.l) return true;
        else if (this->l == other.l && this->d <= other.d) return true;
        return false;
    }
}arr[maxn];

void quicksort(int low, int high)
{
    if (low >= high) return;
    leg k = arr[low], tmp;
    int l = low, r = high;
    while (l < r)
    {
        while (l < r && arr[r] >= k) --r;
        while (l < r && arr[l] <= k) ++l;
        if (l < r)
        {
            tmp = arr[r];
            arr[r] = arr[l];
            arr[l] = tmp;
        }
    }
    arr[low] = arr[l];
    arr[l] = k;
    quicksort(low, l - 1);
    quicksort(r + 1, high);
}

void quicksortint(int low, int high)
{
    if (low >= high) return;
    int k = tmparr[low], tmp;
    int l = low, r = high;
    while (l < r)
    {
        while (l < r && tmparr[r] >= k) --r;
        while (l < r && tmparr[l] <= k) ++l;
        if (l < r)
        {
            tmp = tmparr[r];
            tmparr[r] = tmparr[l];
            tmparr[l] = tmp;
        }
    }
    tmparr[low] = tmparr[l];
    tmparr[l] = k;
    quicksortint(low, l - 1);
    quicksortint(r + 1, high);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i].l);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i].d);
    quicksort(1, n);
    int cnt = 0;
    sum[0] = 0;
    arr[0].l = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + arr[i].d;
        if (arr[i].l == arr[i - 1].l) continue;
        pos[++cnt] = i;
    }
    pos[cnt + 1] = n + 1;

    int min = 2 * 1e8, len, offset, tmp;
    for (int i = 1; i <= cnt; ++i)
    {
        len = pos[i + 1] - pos[i];
        offset = n + 1 - 2 * len;
        tmp = sum[n] - sum[pos[i + 1] - 1];
        offset -= (pos[cnt + 1] - pos[i + 1]);
        if (offset > 0)
        {
            int top = 0;
            for (int j = 1; j < pos[i]; ++j)
                tmparr[++top] = arr[j].d;
            quicksortint(1, top);
            for (int j = 1; j <= offset; ++j)
                tmp += tmparr[j];
        }
        if (tmp < min) min = tmp;
    }
    printf("%d", min);
    return 0;
}