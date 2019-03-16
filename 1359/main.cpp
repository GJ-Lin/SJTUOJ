#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char arr[1005];
	cin.getline(arr, 1001);
	int sum = 0;
	for (int i = 0; i < strlen(arr); ++i)
	{
		if (arr[i] == ' ') continue;
		else if (arr[i] >= 'A' && arr[i] <= 'Z')
			sum += (i + 1) * (arr[i] - 'A' + 1);
		else
			sum += (i + 1) * (arr[i] - 'a' + 27);
	}
	cout << sum;
    return 0;
}
