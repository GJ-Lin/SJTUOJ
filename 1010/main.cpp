#include <iostream>
using namespace std;

int main(void)
{
	int arr[13];
	for (int i = 1; i <= 12; ++i)
		cin >> arr[i];
	int sum = 0, bank = 0;
	bool flag = false;
	for (int i = 1; i <= 12; ++i)
	{

		sum += 300;
		sum -= arr[i];
		if (sum < 0)
		{
			cout << "-" << i;
			flag = true;
			break;
		}
		else
		{
			bank += (sum / 100) * 100;
			sum -= (sum / 100) * 100;
		}
	}
	if (!flag)
		cout << sum + bank * 1.2;
	return 0;
}
