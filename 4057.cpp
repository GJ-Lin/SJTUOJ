#include <iostream>
#include <cstring>
using namespace std;
char str[10000];
int length = 0;
int L = 0, R = 0;
void update(int i, int mode)
{
    int lf, rh;
    if (mode & 1)
    {
        lf = i;
        rh = i;
    }
    else
    {
        if (i + 1 >= length || str[i] != str[i + 1]) return;
        lf = i;
        rh = i + 1;
    }
    while (lf - 1 >=0 && rh + 1 <= length - 1 && str[lf - 1] == str[rh + 1])
    {
        --lf;
        ++rh;
    }
    if (rh - lf > 0 && rh - lf > R - L)
    {
        L = lf;
        R = rh;
    }
}

int main()
{
    cin >> str;
    length = strlen(str);
    for (int i = 0; i < length; ++i)
    {
        update(i, 1);
        update(i, 2);
    }
    if (R - L)
    {
        cout << R - L + 1 << endl;
        for (int i = L; i <= R; ++i)
            cout << str[i];
    }
    else cout << 0;
    return 0;
}