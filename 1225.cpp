#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000005;
bool arr[2 * maxn];

int main()
{
    memset(arr, false, sizeof(arr));
    int n, x;
    cin >> n;
    while (n--)
    {
        scanf("%d", &x);
        arr[maxn + x] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 2 * maxn; ++i)
        if (arr[i]) ++cnt;
    cout << cnt;
}
