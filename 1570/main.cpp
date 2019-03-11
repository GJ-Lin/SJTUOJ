#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 100005;
int search(int arr[], int N, int target)
{
	int low = 0, high = N - 1, mid = (low + high + 1) / 2;
	while (high > low)
	{
		if (arr[mid] > target) high = mid - 1;
		else low = mid;
		mid = (low + high + 1) / 2;
	}
	return mid;
}
int main()
{
	int N, T;
	int arr1[MAXNUM], arr2[MAXNUM];
	cin >> N >> T;
	for (int i = 0; i < N; ++i) scanf("%d", &arr1[i]);
	for (int i = 0; i < T; ++i) scanf("%d", &arr2[i]);
	for (int i = 0; i < T; ++i)
	{
		if (arr2[i] < arr1[0]) printf("%d\n", N);
		else printf("%d\n", N - search(arr1, N, arr2[i]) - 1);
	}
	return 0;
}
