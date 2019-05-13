#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1005;
bool mark[maxn]{false};

int main()
{
    int n, max = 0, x, cnt = 0;
    cin >> n;
    while (n--)
    {
        scanf("%d", &x);
        if (mark[x]) continue;
        if (x > max) max = x;
        mark[x] = true;
        ++cnt;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= max; ++i)
    {
        if (mark[i])
            printf("%d ", i);
    }
    return 0;
}