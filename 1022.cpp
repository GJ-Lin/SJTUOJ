#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << 1;
        return 0;
    }
    int a = 1, b = 1, tmp;
    n %= 2040;
    for (long long i = 3; i <= n; ++i)
    {
        tmp = (a + b) % 2010;
        a = b;
        b = tmp;
    }
    cout << b;
}