#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 300005;
const int P = 1e9 + 7;
int T, n;
int arr[MAXNUM]{0};

void quicksort(int *arr, int low, int high)
{
	if (low >= high) return;
	int k = arr[low], tmp;
	int lf = low, rh = high;
	while (lf < rh)
	{
		while (arr[rh] <= k && lf < rh) --rh;
		while (arr[lf] >= k && lf < rh) ++lf;
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
	arr[0] = 0;
    scanf("%d%d", &T, &n);
    for (int i = 1; i <= n; ++i)
    	scanf("%d", &arr[i]);
    quicksort(arr, 1, n);
    for (int i = 1; i <= n; ++i)
    {
    	arr[i] = (arr[i] + arr[i - 1]) % P;
    }
    int k;
    for (int i = 1; i <= T; ++i)
    {
    	scanf("%d", &k);
    	printf("%d\n", arr[k]);
    }
    return 0;
}
