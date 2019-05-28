#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    if (n < k)
    {
        cout << k - n;
        return 0;
    }
    int cnt = 0;
    for (int i = n; i > 0; i >>= 1)
        if (i & 1) ++cnt;
    if (k >= cnt)
    {
        cout << 0;
        return 0;
    }
    int ans = 0;
    for (int i = 1, j = 0; j <= cnt - k; n >>= 1, i <<= 1)
    {
        if (n & 1) j += 1;
        else ans += i;
    }
    cout << ans + 1;
    return 0;
}