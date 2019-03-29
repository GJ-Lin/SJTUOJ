#include <iostream>
#include <cstring>
using namespace std;
const int MAXNUM = 105;
char cipher[MAXNUM];
char solution[MAXNUM];
int main()
{
    cin >> cipher >> solution;

    int l = strlen(cipher);
    if (l != strlen(solution))
    {
        cout << "No Solution";
        return 0;
    }

    for (int a = 2; a <= l; ++a)
    {
        int cnt = 0;
        bool flag = true;
        if (l % a != 0) continue;
        for (int i = 0; i < a && flag; ++i)
        {
            for (int j = 0; j < l / a; ++j)
            {
                if (cipher[j * a + i] != solution[cnt++])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << a;
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}