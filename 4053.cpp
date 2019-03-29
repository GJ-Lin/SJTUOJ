#include <iostream>
#include <cstdio>
using namespace std;
bool flag = false;
int N;
int ring[20] = { 0, 1 };
bool isPrime[33] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0 };
bool isUsed[20] = { 0, 1 };

void findRing(int n)
{
    for (int i = 2; i <= N; ++i)
    {
        if (isUsed[i]) continue;
        if (n == N - 1)
        {
            if (isPrime[i + ring[n]] && isPrime[i + ring[1]])
            {
                flag = true;
                ring[n + 1] = i;
                for (int j = 1; j <= N; ++j)
                    printf("%d ", ring[j]);
                printf("\n");
            }
            return;
        }
        else
        {
            if (isPrime[i + ring[n]])
            {
                ring[n + 1] = i;
                isUsed[i] = true;
                findRing(n + 1);
                isUsed[i] = false;
            }
        }
    }
    return;
}

int main()
{
    scanf("%d", &N);

    if (N & 1)
    {
        printf("None");
        return 0;
    }

    findRing(1);

    if (!flag) printf("None");

    return 0;
}