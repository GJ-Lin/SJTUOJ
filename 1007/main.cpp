#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char *num_1, *num_2, *num_3, str_1[210], str_2[210];
	cin >> str_1 >> str_2;
	num_1 = new char[strlen(str_1) + 1];
	strcpy(num_1, str_1);
	num_2 = new char[strlen(str_2) + 1];
	strcpy(num_2, str_2);
	int temp = 0, size_1 = strlen(num_1), size_2 = strlen(num_2), size_3 = 2 + (size_1 > size_2 ? size_1 : size_2);
	num_3 = new char[size_3];
	num_3[size_3] = '\0';
	--size_1; --size_2; --size_3;
	for(;temp != 0 || size_1 >= 0 || size_2 >= 0; --size_1, --size_2, --size_3)
	{
		if (num_1[size_1] == '.')
		{
			num_3[size_3] = '.';
		}
		else
		{
			int add_1 = size_1 >= 0 ? (num_1[size_1] - '0') : 0;
			int add_2 = size_2 >= 0 ? (num_2[size_2] - '0') : 0;
			num_3[size_3] = (add_1 + add_2 + temp) % 10 + '0';
			temp = (add_1 + add_2 + temp) / 10;
		}

	}
	num_3 = num_3 + size_3 + 1;
	cout << num_3;
	return 0;
}
