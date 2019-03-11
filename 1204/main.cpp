#include <iostream>
#include <cstring>
using namespace std;
char text[105][2005];
int lines = 1;
void list(char order[])
{
	int n1 = 0, n2 = 0, i = 0;
	while (order[i] != ' ') ++i;
	++i;
	while (order[i] != ' ')
	{
		n1 *= 10;
		n1 += order[i] - '0';
		++i;
	}
	++i;
	while (order[i] != '\0')
	{
		n2 *= 10;
		n2 += order[i] - '0';
		++i;
	}
	if (n1 < 1 || n2 > lines || n1 > n2)
	{
		cout << "Error!" << endl;
		return;
	}
	else
	{
		for (int j = n1; j <= n2; ++j)
			cout << text[j] << endl;
		return;
	}
}
void ins(char order[])
{
	int i = 0, j = 0, k = 0;
	char str[105] = "";
	while (order[k] != ' ') ++k;
	++k;
	while (order[k] != ' ')
	{
		i *= 10;
		i += order[k] - '0';
		++k;
	}
	++k;
	while (order[k] != ' ')
	{
		j *= 10;
		j += order[k] - '0';
		++k;
	}
	++k;

	while (order[k] != '\0')
		str[strlen(str)] = order[k++];
	if (i < 1 || i > lines || j < 1 || j > strlen(text[i]) + 1)
	{
		cout << "Error!" << endl;
		return;
	}
	int length = strlen(str);
	for (int m = strlen(text[i]) - 1; m >= j - 1; --m)
	{
		text[i][m + length] = text[i][m];
	}
	for (int m = j - 1; m < j - 1 + length; ++m)
	{
		text[i][m] = str[m - j + 1];
	}

}
void del(char order[])
{
	int i = 0, j = 0, num = 0, k = 0;
	char str[105] = "";
	while (order[k] != ' ') ++k;
	++k;
	while (order[k] != ' ')
	{
		i *= 10;
		i += order[k] - '0';
		++k;
	}
	++k;
	while (order[k] != ' ')
	{
		j *= 10;
		j += order[k] - '0';
		++k;
	}
	++k;
	while (order[k] != '\0')
	{
		num *= 10;
		num += order[k] - '0';
		++k;
	}
	if (i < 1 || i > lines || j < 1 || j > strlen(text[i]) || num < 0 || num > strlen(text[i]) - j + 1)
	{
		cout << "Error!" << endl;
		return;
	}
	int m, length = strlen(text[i]);
	for (m = j - 1; m < j - 1 + num; ++m)
	{
		text[i][m] = '\0';
	}
	for (; m < length; ++m)
	{
		text[i][m - num] = text[i][m];
	}
	for (; m < length + num; ++m)
	{
		text[i][m - num] = '\0';
	}
}
int main()
{

	cin.getline(text[lines], 2005, '\n');
	while (strcmp(text[lines], "******"))
		cin.getline(text[++lines], 2005, '\n');
	--lines;
	char order[105][155];
	int orders = 1;
	cin.getline(order[orders], 155, '\n');
	while (strcmp(order[orders], "quit"))
		cin.getline(order[++orders], 155, '\n');
	--orders;

	for (int i = 1; i <= orders; ++i)
	{
		switch (order[i][0])
		{
			case 'l': list(order[i]); break;
			case 'i': ins(order[i]); break;
			case 'd': del(order[i]); break;
		}
	}

	for (int i = 1; i <= lines; ++i)
		cout << text[i] << endl;

	return 0;
}
