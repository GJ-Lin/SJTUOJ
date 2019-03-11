#include <iostream>
using namespace std;
const int MAXNUM = 100005;
void quicksort(unsigned long int arr[], int low, int high)
{
	if (low >= high) return;

	int k = arr[low], lf = low, rh = high, tmp;
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
	quicksort(arr, low, lf - 1);
	quicksort(arr, rh + 1, high);
}

int main()
{
	unsigned long int n, sum, arr1[MAXNUM], arr2[MAXNUM];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr1[i];
	for (int i = 0; i < n; ++i)
		cin >> arr2[i];
	quicksort(arr1, 0, n - 1);
	quicksort(arr2, 0, n - 1);
	sum = 0;
	for (int i = 0; i < n; ++i)
		sum += arr1[i] * arr2[i];
	cout << sum << endl;
	sum = 0;
	for (int i = 0; i < n; ++i)
		sum += arr1[i] * arr2[n - i - 1];
	cout << sum << endl;
	return 0;
}
