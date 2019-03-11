#include <iostream>
using namespace std;
int main(void)
{
	int L, W;
	cin >> L >> W;
	//int corn[1001][1001] = {};
	int corn[1001][1001], pre[1001][1001];
	for (int i = 0; i <= 1000; ++i)
    {
        pre[0][i] = pre[i][0] = 0;
    }
	/*int **corn = NULL, **pre = NULL;
	corn = new int *[L + 1];
	pre = new int *[L + 1];
	pre[0] = new int [W + 1]{0};
	for (int i = 1; i <= L; ++i)
	{
		corn[i] = new int[W + 1];
		pre[i] = new int[W + 1];
		pre[i][0] = 0;
	}*/
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
	/*for (int i = 1; i <= L - length + 1; ++i)
		for (int j = 1; j <= W - width + 1; ++j)
		{
			int sum = 0;
			for (int k = i; k <= i + length - 1; ++k)
				for (int l = j; l <= j + width - 1; ++l)
					sum += corn[k][l];
			if (sum > max)
				max = sum;
		}*/
	/*int temp_head = 0, temp = 0;
	for (int i = 1; i <= L - length + 1; ++i)
		for (int j = 1; j <= W - width + 1; ++j)
		{
			int sum = 0;
			if (i == 1 && j == 1)
			{
				for (int k = 1; k <= length; ++k)
					for (int l = 1; l <= width; ++l)
						temp += corn[k][l];
				max = temp_head = temp;
			}
			else if (j == 1)
			{
				for (int l = 1; l <= width; ++l)
				{
					temp_head = temp_head - corn[i - 1][l] + corn[i + length - 1][l];
				}
				temp = temp_head;
				if (temp > max)
					max = temp;
			}
			else
			{
				for (int k = i; k <= i + length - 1; ++k)
					temp = temp - corn[k][j - 1] + corn[k][j + width - 1];
				if (temp > max)
					max = temp;
			}
		}*/
	cout << max;

	for (int i = 1; i <= L; ++i)
		delete [] corn[i];
	delete [] corn;
	return 0;
}
