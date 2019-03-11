#include <iostream>
#include <cmath>
using namespace std;
bool isPrimeNum(int n)
{
	bool flag = true;
	for (int i = 2; i <= int(sqrt(n)); ++i)
	{
		if (!(n % i))
		{
			flag = false;
			break;
		}
	}
	return flag;
}
int main()
{
	int N, minN, maxN;
	cin >> N;
	for (int i = N; i >= 2; --i)
	{
		if (isPrimeNum(i))
		{
			minN = i;
			break;
		}
	}
	for (int i = N; ; ++i)
	{
		if (isPrimeNum(i))
		{
			maxN = i;
			break;
		}
	}
	cout << maxN - minN;
	return 0;
}
