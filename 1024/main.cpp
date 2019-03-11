#include <iostream>
using namespace std;
int divide(int arr[], int low, int high)
{
	int k = arr[low];
	do
	{
		while (low < high && arr[high] > k) --high;
		if (low < high)
		{
			arr[low] = arr[high];
			++low;
		}
		while (low < high && arr[low] < k) ++low;
		if (low < high)
		{
			arr[high] = arr[low];
			--high;
		}
	}while (low < high);
	arr[low] = k;

	return low;
}
void quicksort(int arr[], int low, int high)
{
	int mid;
	if (low >= high) return;
	mid = divide(arr, low, high);
	quicksort(arr, low, mid - 1);
	quicksort(arr, mid + 1, high);
}
int main(void)
{
	int n;
	cin >> n;
	int* arr;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
		if (i < n - 1)
			cout << " ";
	}
	return 0;
}
