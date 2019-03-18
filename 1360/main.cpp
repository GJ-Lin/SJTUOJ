#include <iostream>
using namespace std;
struct activity
{
    int t1, t2;
}arr[100005];
int n;
int count = 1;
int last;
void quicksort(int low, int high)
{
    if (low >= high) return;
    int k = arr[low].t2;
    int lf = low, rh = high;
    activity tmp;
    while (lf < rh)
    {
        while (lf < rh && arr[rh].t2 >= k) --rh;
        if (lf < rh)
        {
            tmp = arr[rh];
            arr[rh] = arr[lf];
            arr[lf] = tmp;
        }
        while (lf < rh && arr[lf].t2 <= k) ++lf;
        if (lf < rh)
        {
            tmp = arr[rh];
            arr[rh] = arr[lf];
            arr[lf] = tmp;
        }
    }
    quicksort(low, lf - 1);
    quicksort(rh + 1, high);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &arr[i].t1, &arr[i].t2);
    quicksort(0, n - 1);
    last = arr[0].t2;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i].t1 >= last)
        {
            last = arr[i].t2;
            ++count;
        }
    }
    printf("%d", count);
    return 0;
}
