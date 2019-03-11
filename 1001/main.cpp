#include <iostream>
using namespace std;
int main(void)
{
	int height, height_1, height_2, n, sum = 0;
	int temp = 0;
	cin >> height_1 >> height_2 >> n;
	height = height_1 + height_2;
	for(int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (temp <= height)
			++sum;
	}
	cout << sum;
	return 0;
}
