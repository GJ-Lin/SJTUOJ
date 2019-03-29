#include <iostream>
#include <cstdio>
using namespace std;
const int max_numNUM = 400005;
int N, K;
int chain[max_numNUM];
int max_num = 0, min_max_num = 1e9, max_num_idx = 0;

void findmax_num(int low, int high)
{
    max_num = 0;
    for (int i = low; i <= high; ++i)
    {
        if (chain[i] > max_num)
        {
            max_num = chain[i];
            max_num_idx = i;
        }
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; ++i)
    {
        scanf("%d", &chain[i]);
        if (chain[i] > max_num)
        {
            max_num = chain[i];
            max_num_idx = i;
        }
    }
    min_max_num = max_num;

    for (int i = K; i < N + K; ++i)
    {
        if (i < N)
            scanf("%d", &chain[i]);
        else
            chain[i] = chain[i - N];

        if (chain[i] > max_num)
        {
            max_num = chain[i];
            max_num_idx = i;
        }
        else
        {
            if (i - K == max_num_idx) findmax_num(i - K + 1, i);
            if (max_num < min_max_num) min_max_num = max_num;
        }
    }
    printf("%d", min_max_num);
    return 0;
}