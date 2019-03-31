#include <iostream>
#include <cstdio>
using namespace std;
int cnt = 0;
struct fraction
{
    int a, b;
    double num;
}arr[10000];

void quicksort(int low, int high)
{
    if (low >= high) return;
    fraction k = arr[low], tmp;
    int lf = low, rh = high;
    while (lf < rh)
    {
        while (arr[rh].num >= k.num && lf < rh) --rh;
        while (arr[lf].num <= k.num && lf < rh) ++lf;
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

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int N;
    cin >> N;
    arr[0].a = 0;
    arr[0].b = 1;
    arr[0].num = 0.0;
    ++cnt;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (gcd(j, i) == 1)
            {
                arr[cnt].a = j;
                arr[cnt].b = i;
                arr[cnt].num = double(j) / i;
                ++cnt;
            }
        }
    }
    arr[cnt].a = 1;
    arr[cnt].b = 1;
    arr[cnt].num = 1.0;
    quicksort(0, cnt);
    for (int i = 0; i <= cnt; ++i)
        printf("%d/%d\n", arr[i].a, arr[i].b);
    return 0;
}