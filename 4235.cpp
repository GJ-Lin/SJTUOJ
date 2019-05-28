#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100005;
bool mark[maxn];
int arr[maxn];
int n;
int main()
{
    memset(mark, 0, sizeof(mark));
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int cnt = -1;
    int p = 0;
    while (p < n)
    {
        if (mark[p])
        {
            ++p;
            continue;
        }
        while (!mark[p])
        {
            mark[p] = true;
            p = arr[p];
        }
        ++cnt;
    }
    cout << cnt;
    return 0;
}