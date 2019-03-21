#include <iostream>

using namespace std;

int main()
{
    long int x, y;
    cin >> x >> y;
    long int sum = 0;
    long int tmp;
    if (x < y)
    {
        tmp = x;
        x = y;
        y = tmp;
    }
    while (y != 0)
    {
        sum += y;
        tmp = x - y;
        x = (y > tmp ? y : tmp);
        y = (y < tmp ? y : tmp);
    }
    cout << 4 * sum;
    return 0;
}
