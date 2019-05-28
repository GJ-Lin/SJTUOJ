#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000005;
int arr[maxn];
int pos = 0, len = 0, maxlen = 0;
int main()
{

    int n;
    int sum = 0, count = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        arr[i + n] = arr[i];
    }

    bool combo = false;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (combo)
        {
            if (arr[i] == 0) ++len;
            else
            {
                if (len > maxlen)
                {
                    pos = i % n;
                    maxlen = len;
                }
                len = 0;
                combo = false;
            }
        }
        else
        {
            if (arr[i] == 0)
            {
                len = 1;
                combo = true;
            }
        }
    }
    if (len > maxlen) pos = n - 1;

    for (int j = pos; j < pos + n; ++j)
    {
        sum += arr[j];
        if (!sum) ++count;
    }
    cout << n - count;
    return 0;
}