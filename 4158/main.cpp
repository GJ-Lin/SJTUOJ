#include <iostream>
#include <cstdio>
using namespace std;
int T;
int n, m;
int arr[100005];
int x;
int sum = 1;
int cnt = 0;
void quicksort(int low, int high)
{
    if (low >= high) return;
 
    int k = arr[low], tmp, lf = low, rh = high;
    while (lf < rh)
    {
        while (lf < rh && arr[rh] >= k) --rh;
        if (lf < rh)
        {
            tmp = arr[lf];
            arr[lf] = arr[rh];
            arr[rh] = tmp;
        }
        while (lf < rh && arr[lf] <= k) ++lf;
        if (lf < rh)
        {
            tmp = arr[lf];
            arr[lf] = arr[rh];
            arr[rh] = tmp;
        }
    }
    quicksort(low, lf - 1);
    quicksort(rh + 1, high);
}
int C(int N, int M)
{
    int ans = 1;
    for (int i = N, j = 1; j <= M; --i, ++j)
        ans = ans * i / j;
    return ans;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
 
        arr[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &x);
            arr[i] = (arr[i - 1] + x) % m;
        }
 
        quicksort(0, n);
        sum = 1;
        cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (arr[i] == arr[i - 1]) ++sum;
            else
            {
                cnt += C(sum, 2);
                sum = 1;
            }
        }
        cnt += C(sum, 2);
        printf("%d\n", cnt);
    }
    return 0;
}