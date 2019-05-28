#include <iostream>
using namespace std;
const int maxn = 100005;
int arr[maxn], a[maxn], ans[maxn];

int binarySearch(int l, int r, int k)
{
    if (l >= r) return l;
    int m = (l + r) / 2;
    if (ans[m] < k) return binarySearch(m + 1, r, k);
    else return binarySearch(l, m, k);
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        arr[x] = i;
    }
    int len = 0;
    for (int i = 1, j = 0; i <= n; ++i)
    {
        cin >> x;
        a[i] = arr[x];
        if (a[i] > ans[len]) j = ++len;
        else j = binarySearch(1, len, a[i]);
        ans[j] = a[i];
    }
    cout << len << endl;
    return 0;
}
