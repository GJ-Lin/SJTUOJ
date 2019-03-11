#include <iostream>
using namespace std;

int main()
{
	char c;
	int n, half;
	cin >> c >> n;
	half = (n + 1) / 2;
	for (int i = 1; i <= half; ++i)
	{
		for (int j = 1; j <= half - i; ++j)
			cout << ' ';
		for (int j = 1; j <= 2 * i - 1; ++j)
			cout << c;
		cout << endl;
	}
	for (int i = half - 1; i >= 1; --i)
	{
		for (int j = 1; j <= half - i; ++j)
			cout << ' ';
		for (int j = 1; j <= 2 * i - 1; ++j)
			cout << c;
		cout << endl;
	}
	return 0;
}
