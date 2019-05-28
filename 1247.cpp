#include <iostream>
using namespace std;
const int maxn = 105;
 
struct Range
{
    int l, r;
    bool operator>=(const Range& other) { return this->l >= other.l; }
    bool operator<=(const Range& other) { return this->l <= other.l; }
}arr[maxn];
 
void quicksort(int low, int high)
{
    if (low >= high) return;
    Range k = arr[low], tmp;
    int lf = low, rh = high;
    while (lf < rh)
    {
        while (lf < rh && arr[rh] >= k) --rh;
        while (lf < rh && arr[lf] <= k) ++lf;
        if (lf < rh)
        {
            tmp = arr[rh];
            arr[rh] = arr[lf];
            arr[lf] = tmp;
        }
    }
    arr[low] = arr[lf];
    arr[lf] = k;
    quicksort(low, lf - 1);
    quicksort(rh + 1, high);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> arr[i].l >> arr[i].r;
    quicksort(0, m - 1);
 
    int sum = 0, last = -1;
    for (int i = 0; i < m; ++i)
    {
        if (arr[i].r <= last) continue;
        if (arr[i].l > last)
        {
            ++sum;
            if (arr[i].r <= n)
            {
                sum += arr[i].r - arr[i].l;
                last = arr[i].r;
            }
            else
            {
                sum += n - arr[i].l;
                break;
            }
        }
        else
        {
            if (arr[i].r <= n)
            {
                sum += arr[i].r - last;
                last = arr[i].r;
            }
            else
            {
                sum += n - last;
                break;
            }
        }
    }
    cout << n + 1 - sum;
    return 0;
}