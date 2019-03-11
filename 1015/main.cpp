#include <iostream>
#include <cstring>
using namespace std;
const int MAXSIZE = 100000;
void Add(char* num_1, char* num_2, char* num_3)
{
	char* head;
	int temp = 0, size_1 = strlen(num_1), size_2 = strlen(num_2), size_3 = 2 + (size_1 > size_2 ? size_1 : size_2);
	head = new char[size_3];
	head[size_3] = '\0';
	--size_1; --size_2; --size_3;
	for(;temp != 0 || size_1 >= 0 || size_2 >= 0; --size_1, --size_2, --size_3)
	{
		int add_1 = size_1 >= 0 ? (num_1[size_1] - '0') : 0;
		int add_2 = size_2 >= 0 ? (num_2[size_2] - '0') : 0;
		head[size_3] = (add_1 + add_2 + temp) % 10 + '0';
		temp = (add_1 + add_2 + temp) / 10;
	}
	head = head + size_3 + 1;
	strcpy(num_3, head);
	delete [] head;
}
void MultiSingle(char* num_1, int num_2, char* num_3)
{
	char* head;
	int temp = 0, size_1 = strlen(num_1);
	head = new char[size_1];
	head[size_1] = '\0';
	--size_1;
	for(;temp != 0 || size_1 >= 0; --size_1)
	{
		int multi = size_1 >= 0 ? (num_1[size_1] - '0') : 0;
		head[size_1] = (multi * num_2 + temp) % 10 + '0';
		temp = (multi * num_2 + temp) / 10;
	}
	head = head + size_1 + 1;
	strcpy(num_3, head);
	delete [] head;
}
void Multi(char* num_1, char* num_2, char* num_3)
{
	char head[MAXSIZE], temp[MAXSIZE];
	int size_2 = strlen(num_2);
	for (int i = 0; i < size_2; ++i)
	{
		MultiSingle(num_1, num_2[i] - '0', temp);
		int j = 0;
		for(j = i; j < size_2 - 1; ++j)
			temp[strlen(temp)] = '0';
		temp[strlen(temp)] = '\0';
		Add(head, temp, head);
	}
	strcpy(num_3, head);
}
int main(void)
{
	char num_1[MAXSIZE], num_2[MAXSIZE], num_3[MAXSIZE];
	cin >> num_1 >> num_2;
	Multi(num_1, num_2, num_3);
	cout << num_3;
	return 0;
}
