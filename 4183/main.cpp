#include <iostream>
#include <cstdio>
using namespace std;
int arr[1005];

void rves(int lf, int rh)
{
    int tmp;
    while (lf < rh)
    {
        tmp = arr[rh];
        arr[rh] = arr[lf];
        arr[lf] = tmp;
        ++lf;
        --rh;
    }
    return;
}

void permutation(int n, int k)
{
    if (!k) return;
    int i = n - 2, j = n - 1;
    while (i >= 0 && arr[i] > arr[j])
    {
        --i;
        --j;
    }
    if (i == -1)
        rves(0, n - 1);
    else
    {
        int l = n - 1;
        while (arr[i] > arr[l]) --l;
        int tmp;
        tmp = arr[l];
        arr[l] = arr[i];
        arr[i] = tmp;
        rves(j, n - 1);
    }
    permutation(n, --k);
    return;
}

int main()
{
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        permutation(n, k);
        for (int i = 0; i < n; ++i)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
