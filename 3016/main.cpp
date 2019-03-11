#include <iostream>
using namespace std;
const int MAXNUM = 200;
int main()
{
	int n, arr[MAXNUM], sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	int ave = sum / n, count = 0;
	for (int i = 0; i < n; ++i)
		arr[i] -= ave;
	sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum == 0) ++count;
	}
	cout << n - count << endl;
	return 0;
}
