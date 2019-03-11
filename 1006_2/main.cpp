#include <iostream>
#include <climits>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int a, *sum, *sum_min, ans = INT_MIN;
	sum = new int [n];
	sum_min = new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		if (i == 0)
			sum[i] = 0;
		else
			sum[i] = sum[i - 1] + a;

		if (i == 0)
		{
			sum_min[i] = sum[i];
		}
		else
		{
			if (sum[i] < sum_min[i - 1])
				sum_min[i] = sum[i];
			else
				sum_min[i] = sum_min[i - 1];
		}

		if (i >= 2)
		{
			if (sum[i] - sum_min[i - 1] > ans)
				ans = sum[i] - sum_min[i - 1];
		}
	}
	if (ans > 0)
		cout << ans;
	else
		cout << "Game over";
	return 0;
}
