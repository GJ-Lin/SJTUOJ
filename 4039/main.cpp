#include <iostream>
#include <cmath>
using namespace std;
bool isPrimenumber(int n)
{
	if (n == 2)
		return true;

	bool flag = false;
	for (int i = 2; i <= int(sqrt(n)) + 1; ++i)
	{
		if (n % i == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
		return false;
	else
		return true;
}
int main(void)
{
	int n;
	cin >> n;
	bool isFirst = true;
	int num = 2;
	if (isPrimenumber(n))
	{
		cout << n;
		return 0;
	}
	while(!isPrimenumber(n))
	{
		for(int i = num; i <= int(sqrt(n)) + 1; ++i)
		{
			if (isPrimenumber(i) && n % i == 0 )
			{
				if (!isFirst)
					cout << ' ';
				else
					isFirst = false;
				cout << i;
				n /= i;
				num = i;
				break;
			}
		}
	}
	cout << ' ' << n;
	return 0;
}
