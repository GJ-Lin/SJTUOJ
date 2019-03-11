#include <iostream>
using namespace std;
int main(void)
{

	int L = 0;
	bool perfect = true;
	cin >> L;
	int **box = NULL, **box_new = NULL;
	box = new int *[L + 2];
	box_new = new int *[L + 2];
	for (int i = 0; i <= L + 1; ++i)
	{
		box[i] = new int [L + 2]{0};
		box_new[i] = new int [L + 2]{0};
	}
	/*int box[102][102], box_new[102][102];
	for (int i = 0; i <= L + 1; ++i)
        for (int j = 0; j <= L + 1; ++j)
            box[i][j] = box_new[i][j] = 0;*/
	for (int i = 1; i <= L; ++i)
		for (int j = 1; j <= L; ++j)
        {
			cin >> box[i][j];
			if (box[i][j] == 0)
                perfect = false;
        }

	bool flag = true;
	int sum = 0;

	if (!perfect)
	{

        do
        {
            ++sum;
            flag = false;
            for (int i = 1; i <= L; ++i)
                for (int j = 1; j <= L; ++j)
                {
                    if (box[i][j] != 0)
                    {
                        box_new[i][j] = box[i][j];
                    }
                    else if(box[i - 1][j] != 1 && box [i + 1][j] != 1 && box[i][j - 1] != 1 && box[i][j + 1] != 1)
                    {
                        box_new[i][j] = 0;
                        flag = true;

                    }
                    else
                        box_new[i][j] = 1;
                }
            if (!flag)
                break;
            for (int i = 1; i <= L; ++i)
                for (int j = 1; j <= L; ++j)
                    box[i][j] = box_new[i][j];
        }while(flag);
	}


	cout << sum;
	return 0;
}
