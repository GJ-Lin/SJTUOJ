#include <iostream>
#include <iomanip>
using namespace std;
int MAXSIZE = 200;
int main(void)
{
	int mountain[MAXSIZE][MAXSIZE], n, sum, i = 1, j = 1, count = 0;
	cin >> n;
	sum = n * n;
	for (int k = 1; k <= n; ++k)
		for (int l = 1; l <= n; ++l)
			mountain[k][l] = 0;
	mountain[i][j] = ++count;
	--sum;
	while (sum > 0)
	{
		while(sum > 0 && j < n && !mountain[i][j + 1])
		{
			mountain[i][++j] = ++count;
			--sum;
		}
		while(sum > 0 && i < n && !mountain[i + 1][j])
		{
			mountain[++i][j] = ++count;
			--sum;
		}
		while(sum > 0 && j > 1 && !mountain[i][j - 1])
		{
			mountain[i][--j] = ++count;
			--sum;
		}
		while(sum > 0 && i > 1 && !mountain[i - 1][j])
		{
			mountain[--i][j] = ++count;
			--sum;
		}
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int l = 1; l <= n; ++l)
		{
			cout  << setw(6) << mountain[k][l];
		}
		if (k < n)
			cout << endl;
	}
	return 0;
}
