#include <iostream>
#include <cstdio>
using namespace std;
const long long P = 1e9 + 7;
const int MAX = 3e5 + 5;
int n;
int pc[MAX];
long long pow_2[MAX];

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

void initial()
{
    pow_2[0] = 1;
    for (int i = 1; i < n; ++i)
        pow_2[i] = (pow_2[i - 1] << 1) % P;
}

long long quickpow(long long a, long long k, int p)
{
    long long result = 1;
    long long tmp = a % p;
    while (k)
    {
        if (k & 1) result = result * tmp % p;
        tmp = tmp * tmp % p;
        k >>= 1;
    }
    return result;
}

int main()
{
    scanf("%d", &n);
    initial();
    for (int i = 0; i < n; ++i)
        scanf("%d", &pc[i]);
    quicksort(pc, 0, n - 1);

    long long sum = 0, t_sum = 0;
    /*
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            sum = (sum + ((pc[j] - pc[i]) % P * pow_2[j - i - 1]) % P) % P;
    */
    /*
    for (int gap = 0; gap <= n - 2; ++gap)
    {
         long long sum_g = 0;
         for (int i = 0; i < n - 1 - gap; ++i)
             sum_g = (sum_g + pc[i + gap + 1] - pc[i]) % P;
         sum = (sum + sum_g * quickpow(2, gap, P) % P) % P;
    }
    */
    for (int i = 1; i < n; ++i)
    {
        t_sum = ((t_sum << 1) % P + pc[i - 1]) % P;
        sum = (sum + (pow_2[i] - 1) * pc[i] - t_sum) % P;
    }
    printf("%lld", sum);
    return 0;
}