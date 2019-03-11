#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char arr[55];
    int num[55];
    scanf("%s", &arr);
    int tmp = 1, i, j;
    for (i = strlen(arr) - 1, j = 0; i >= 0; --i, ++j)
    {
        tmp += arr[i] - '0';
        num[j] = tmp % 10;
        tmp /= 10;
    }
    if (tmp) num[j++] = tmp;
    --j;
    for (; j >= 0; --j)
        printf("%d", num[j]);
    return 0;
}
