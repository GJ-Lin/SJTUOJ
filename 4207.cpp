#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 5005;
int kids[MAXNUM];
int sum[MAXNUM];
int n, k;
int teams;
int min_skl, max_skl, cnt;
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
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &kids[i]);
    quicksort(kids, 0, n - 1);

    min_skl = max_skl = kids[0];
    teams = 0;
    cnt = 1;
    for (int i = 1; i < n; ++i)
    {
        if (kids[i] > max_skl) max_skl = kids[i];
        if (kids[i] < min_skl) min_skl = kids[i];

        if (max_skl - min_skl > 5)
        {
            sum[teams] = cnt;
            min_skl = max_skl = kids[i];
            ++teams;
            cnt = 1;
        }
        else
        {
            ++cnt;
        }
    }
    sum[teams] = cnt;

    quicksort(sum, 0, teams);
    int ans = 0, i = teams + 1;
    while (k-- && i--)
    {
        ans += sum[i];
    }
    printf("%d", ans);
    return 0;
}