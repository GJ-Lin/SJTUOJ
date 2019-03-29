#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 1e7 + 10;
long long cities[MAXNUM] = {};
int main()
{
    int N, M, Q;
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j) 
        {
            scanf("%lld", &cities[i * (M + 1) + j]);
            cities[i * (M + 1) + j] += cities[(i - 1) * (M + 1) + j] + cities[i * (M + 1) + j - 1] - cities[(i - 1) * (M + 1) + j - 1];
        }
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < Q; ++i)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%lld\n", cities[x2 * (M + 1) + y2] - cities[(x1 - 1) * (M + 1) + y2] - cities[x2 * (M + 1) + y1 - 1] + cities[(x1 - 1) * (M + 1) + y1 - 1]);
    }

    return 0;
}