#include <iostream>
using namespace std;
int main(void)
{
	int L, W;
	cin >> L >> W;
	int **corn = NULL, **pre = NULL;
	corn = new int *[L + 1];
	pre = new int *[L + 1];
	pre[0] = new int [W + 1]{0};
	for (int i = 1; i <= L; ++i)
	{
		corn[i] = new int[W + 1];
		pre[i] = new int[W + 1];
		pre[i][0] = 0;
	}
	for (int i = 1; i <= L; ++i)
		for (int j = 1; j <= W; ++j)
		{
			cin >> corn[i][j];
			pre[i][j] = corn[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
		}
	int length, width;
	cin >> length >> width;
	int max = 0;
	int sum = 0;
	for (int i = length; i <= L; ++i)
		for (int j = width; j <= W; ++j)
		{
			sum = pre[i][j] - pre[i - length][j] - pre[i][j - width] + pre[i - length][j - width];
			if (sum > max)
				max = sum;
		}
	cout << max;
	for (int i = 1; i <= L; ++i)
		delete [] corn[i];
	delete [] corn;
	return 0;
}

