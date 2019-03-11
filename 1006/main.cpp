#include <iostream>
#include <climits>
using namespace std;
int MaxSum(int a[], int left, int right);
int Max(int a, int b, int c);
int main(void)
{
	int n, sum = 0;
	cin >> n;
	int *a = NULL;
	a = new int[n];
	//int a[100];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sum = MaxSum(a, 0, n - 1);
	if (sum > 0)
		cout << sum;
	else
		cout << "Game Over";
	return 0;
}
int MaxSum(int a[], int left, int right)
{
	int center, max_left, max_right;
	int sum_left = 0, sum_right = 0;
	int sum_left_max = INT_MIN, sum_right_max = INT_MIN;
	if (left == right)
		return a[left] > 0 ? a[left] : 0;
    center = (left + right) / 2;
	max_left = MaxSum(a, left, center);
	max_right = MaxSum(a, center + 1, right);

	for (int i = center; i >= left; --i)
	{
		sum_left += a[i];
		if (sum_left > sum_left_max)
			sum_left_max = sum_left;
	}
	for (int i = center + 1; i <= right; ++i)
	{
		sum_right += a[i];
		if (sum_right > sum_right_max)
			sum_right_max = sum_right;
	}

	return Max(max_left, max_right, sum_left_max + sum_right_max);
}
int Max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c)
		return b;
	else
		return c;
}
