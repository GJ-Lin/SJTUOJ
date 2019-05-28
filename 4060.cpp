#include <iostream>
using namespace std;
const int maxn = 105;
int n;
int a, b, y, z;
int arr[maxn];
int main()
{
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    a = arr[1];
    b = arr[2];
    while (n >= 4)
    {
        y = arr[n - 1];
        z = arr[n];
        if (2 * b < a + y)
            sum += a + 2 * b + z;
        else
            sum += 2 * a + y + z;
        n -= 2;
    }
    if (n == 3)
        sum += a + b + arr[3];
    else if (n == 2)
        sum += b;
    else
        sum += a;

    cout << sum;
}