#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 10005;
int n, m;
int pages[MAXNUM];
int tmp[MAXNUM];

void quicksort(int *arr, int low, int high)
{
    if (low >= high) return;

    int k = arr[low], tmp;
    int lf = low, rh = high;
    while (lf < rh)
    {
        while (arr[rh] >= k && lf < rh) --rh;
        while (arr[lf] <= k && lf < rh) ++lf;
        if (lf < rh)
        {
            tmp = arr[rh];
            arr[rh] = arr[lf];
            arr[lf] = tmp;
        }
    }
    arr[low] = arr[lf];
    arr[lf] = k;
    quicksort(arr, low, lf - 1);
    quicksort(arr, rh + 1, high);
}


int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &pages[i]);
        tmp[i] = pages[i];
    }

    int l, r, x;
    int origin;
    while (m--)
    {
        scanf("%d%d%d", &l, &r, &x);
        origin = pages[x];
        quicksort(tmp, l, r);
        if (origin == tmp[x]) printf("Yes\n");
        else printf("No\n");
        for (int i = l; i <= r; ++i)
            tmp[i] = pages[i];
    }
    return 0;
}