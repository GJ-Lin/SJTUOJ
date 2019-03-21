#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    int n, m;
    int arr[1000005];
    arr[0] = 0;
    int count = 0;
    for (int t = 0; t < T; ++t)
    {
        count = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
            arr[i] += arr[i - 1];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if ((arr[j] - arr[i]) % m == 0)
                    ++count;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
