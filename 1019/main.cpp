#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 50;
const int LENGTH = 101;
int main(void)
{
	int n;
	cin >> n;
	bool result[MAX];
	char str[LENGTH];
	int brackets[LENGTH];
	cin.ignore();
	for (int i = 0; i < n; ++i)
	{
		int sumleft = 0, sumright = 0, length = 0;
		bool flag = true;
		cin.getline(str, LENGTH);
		length = strlen(str);
		for (int j = 0; j < length; ++j)
		{
			if (str[j] == '(')
			{
				brackets[j] = -1;
				++sumleft;
			}
			else if (str[j] == ')')
			{
				brackets[j] = 1;
				++sumright;
			}
			else
				brackets[j] = 0;
		}
		if (sumleft != sumright)
		{
			result[i] = false;
			continue;
		}
		while(sumleft != 0 && flag)
		{
			int brackets_last = 0, brackets_next = 0, k = 0, k_last = 0;
			while(!brackets[k]) ++k;
			brackets_next = brackets[k];
			while (sumleft != 0 && flag)
			{
				brackets_last = brackets_next;
				k_last = k;
				++k;
				while(!brackets[k] && k < length) ++k;
				if (k >= length)
				{
					flag = false;
					break;
				}
				brackets_next = brackets[k];
				if (brackets_last == -1 && brackets_next == 1)
				{
					brackets[k_last] = brackets[k] = 0;
					--sumleft;
					break;
				}
			}
		}
		if (flag)
			result[i] = true;
		else
			result[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << (result[i] ? "YES" : "NO");
		if (i < n - 1)
			cout << endl;
	}
	return 0;
}
