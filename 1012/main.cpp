#include <iostream>
using namespace std;
int s, t, length = 0, sum = 0;
void find(int n, int num)
{
	for (int i = 1; num + num * i / 100 <= t; ++i)
	{
		if (num * i % 100 == 0)
			find(n + 1, num + num * i / 100);
	}
	if (n > length)
	{
		length = n;
		sum = 1;
	}
	else if (n == length)
		++sum;
	else
		return;
}
int main(void)
{
	cin >> s >> t;
	find(1, s);
	cout << length << endl << sum << endl;
	return 0;
}
