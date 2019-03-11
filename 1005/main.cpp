#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	bool status[21];
	for(int i = 1; i <= n; ++i)
	{
		int sudoku[10][10];
		bool flag = true;
		bool row[10][10] = {false}, col[10][10] = {false}, squ[4][4][10] = {false};
		/*for(int j = 1; j <= 9; ++j)
		{
			//if (!flag)
				//break;
			for(int k = 1; k <= 9; ++k)
			{
			    cin >> sudoku[j][k];
				if (row[j][sudoku[j][k]] == false)
					row[j][sudoku[j][k]] = true;
				else
				{
					flag= false;
					//break;
				}

				if (col[k][sudoku[j][k]] == false)
					col[k][sudoku[j][k]] = true;
				else
				{
					flag = false;
					//break;
				}

				if (squ[(j - 1) / 3 + 1][(k - 1) / 3 + 1][sudoku[j][k]] == false)
					squ[(j - 1) / 3 + 1][(k - 1) / 3 + 1][sudoku[j][k]] = true;
				else
				{
					flag = false;
					//break;
				}
			}
		}*/
		for(int j = 1; j <= 9; ++j)
		{
			//if (!flag)
			//	break;
			for(int k = 1; k <= 9; ++k)
			{
				cin >> sudoku[j][k];
				if (row[j][sudoku[j][k]] == false)
					row[j][sudoku[j][k]] = true;
				else
				{
					flag = false;
			//		break;
				}
			}
		}
		for (int k = 1; k <= 9; ++k)
		{
			//if (!flag)
			//	break;
			for (int j = 1; j <= 9; ++j)
			{
				if (col[k][sudoku[j][k]] == false)
					col[k][sudoku[j][k]] = true;
				else
				{
					flag = false;
			//		break;
				}
			}
		}
		for (int m = 1; m <= 3; ++m)
		{
			//if (!flag)
			//	break;
			for (int n = 1; n <= 3; ++n)
			{
			//	if (!flag)
			//		break;
				for (int j = 1; j <= 3; ++j)
				{
			//		if (!flag)
			//			break;
					for (int k = 1; k <= 3; ++k)
					{
						if (squ[m][n][sudoku[3 * (m - 1) + j][3 * (n - 1) + k]] == false)
							squ[m][n][sudoku[3 * (m - 1) + j][3 * (n - 1) + k]] = true;
						else
						{
							flag = false;
			//				break;
						}
					}
				}
			}
		}
		if (flag)
			status[i] = true;
		else
			status[i] = false;

		if (i != n)
			cin.get();
	}

	for (int i = 1; i <= n; ++i)
	{
		if (status[i])
			cout << "Right" << endl;
		else
			cout << "Wrong" << endl;
	}
	return 0;
}
