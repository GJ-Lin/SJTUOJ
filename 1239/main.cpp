#include <iostream>
using namespace std;

int main()
{
	double n, sum;
	double tax[] = {0, 45, 345, 1245, 7745, 13745, 22495};
	cin >> n;
	if (n <= 3500)
		sum = 0.0;
	else
	{
		n -= 3500;
		if (n <= 1500) sum = n * 0.03;
		else if (n <= 4500) sum = tax[1] + (n - 1500) * 0.1;
		else if (n <= 9000) sum = tax[2] + (n - 4500) * 0.2;
		else if (n <= 35000) sum = tax[3] + (n - 9000) * 0.25;
		else if (n <= 55000) sum = tax[4] + (n - 35000) * 0.3;
		else if (n <= 80000) sum = tax[5] + (n - 55000) * 0.35;
		else sum = tax[6] + (n - 80000) * 0.45;
	}
	cout << int(sum);
	return 0;
}
