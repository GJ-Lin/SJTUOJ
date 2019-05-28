#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000005;
int arr[maxn];

void quicksort(int low, int high)
{
    if (low >= high) return;
    int k = arr[low], tmp;
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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    quicksort(0, n - 1);
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    return 0;
}