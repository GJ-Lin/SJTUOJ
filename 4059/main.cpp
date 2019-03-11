#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, tmp, max = 0, pos;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        if (tmp > max)
        {
            max = tmp;
            pos = i;
        }
    }
    printf("%d %d", max, pos + 1);
    return 0;
}
