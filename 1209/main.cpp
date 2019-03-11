#include <iostream>
using namespace std;

int find_one(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += x % 2;
		x /= 2;
	}
	return sum;
}

int main()
{
	int n, x, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		sum += find_one(x);
	}
	cout << sum;
	return 0;
}
