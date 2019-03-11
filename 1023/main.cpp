#include <iostream>
using namespace std;
const int MAXSIZE = 700;
struct matrix
{
	int size;
	int** square;

};
int main(void)
{
	int n;
	cin >> n;
	matrix* arr;
	arr = new matrix[n];
	for (int i = 0; i < n; ++i)
	{
		int method;
		cin >> arr[i].size >> method;
		arr[i].square = new int*[arr[i].size];
		for (int j = 0; j < arr[i].size; ++j)
			arr[i].square[j] = new int[arr[i].size];
		if (method == 0)
			for (int j = 0; j < arr[i].size; ++j)
				for (int k = arr[i].size - 1; k >= 0; --k)
					cin >> arr[i].square[j][k];
		else if (method == 1)
			for (int j = arr[i].size - 1; j >= 0; --j)
				for (int k = 0; k < arr[i].size; ++k)
					cin >> arr[i].square[j][k];
		else if (method == 2)
			for (int j = 0; j < arr[i].size; ++j)
				for (int k = 0; k < arr[i].size; ++k)
					cin >> arr[i].square[k][j];
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < arr[i].size; ++j)
		{
			for (int k = 0; k < arr[i].size; ++k)
			{
				cout << arr[i].square[j][k];
				if (k < arr[i].size - 1)
					cout << " ";
			}
			if (i < n - 1 || j < arr[i].size - 1)
				cout << endl;
		}
	return 0;
}
