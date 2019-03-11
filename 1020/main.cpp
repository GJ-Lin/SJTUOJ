#include <iostream>
#include <cmath>
using namespace std;
const int MAXSIZE = 10000;
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
	int Pnums[MAXSIZE][2], count = 0;
	cin >> n;
	cout << n << "=";
	int num = 2;

	while(!isPrimenumber(n))
	{
		for(int i = num; i <= int(sqrt(n)) + 1; ++i)
		{
			if (isPrimenumber(i) && n % i == 0 )
			{
				if (!count)
				{
					++count;
					Pnums[count][0] = i;
					Pnums[count][1] = 1;
				}
				else
				{
					if (i == Pnums[count][0])
						++Pnums[count][1];
					else
					{
						++count;
						Pnums[count][0] = i;
						Pnums[count][1] = 1;
					}
				}
				n /= i;
				num = i;
				break;
			}
		}
	}
	if (n == Pnums[count][0])
		++Pnums[count][1];
	else
	{
		++count;
		Pnums[count][0] = n;
		Pnums[count][1] = 1;
	}
	for (int i = 1; i <= count; ++i)
		cout << Pnums[i][0] << "(" << Pnums[i][1] << ")";
	return 0;
}
