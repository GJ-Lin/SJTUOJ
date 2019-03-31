#include <iostream>
using namespace std;

int main()
{
    long long x, n, sum = 0;
    cin >> x >> n;
    if (x + n <= 6)
    {
        cout << 250 * n;
    }
    else if (x + n <= 8)
    {
        if (x <= 5)
            cout << 250 * (6 - x);
        else cout << 0;
    }
    else 
    {
        if (x <= 5)
            sum += 250 * (6 - x);
        n -= (8 - x);
        sum += 1250 * (n / 7);
        n %= 7;
        if (n <= 5) sum += 250 * n;
        else sum += 1250;
        cout << sum;
    }

    return 0;
}