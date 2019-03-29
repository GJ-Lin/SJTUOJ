#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 100005;
int pos[MAXNUM];
int N, C;

void quicksort(int low, int high)
{
    if (low >= high) return;
    int k = pos[low], tmp, lf = low, rh = high;
    while (lf < rh)
    {
        while (pos[rh] >= k && lf < rh) --rh;
        while (pos[lf] <= k && lf < rh) ++lf;
        if (lf < rh)
        {
            tmp = pos[rh];
            pos[rh] = pos[lf];
            pos[lf] = tmp;
        }
    }
    pos[low] = pos[lf];
    pos[lf] = k;
    quicksort(low, lf - 1);
    quicksort(rh + 1, high);
}

bool check(int length)
{
    int cnt = 1;
    for (int lf = 0, rh = 1; rh < N; ++rh)
    {
        if (pos[rh] - pos[lf] >= length)
        {
            lf = rh;
            ++cnt;
            if (cnt >= C) return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &N, &C);
    for (int i = 0; i < N; ++i)
        scanf("%d", &pos[i]);
    quicksort(0, N - 1);

    int min = 0, max = pos[N - 1] - pos[0], mid;
    int ans = max;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (check(mid))
        {
            if (ans == mid) break;
            ans = mid;
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }

    printf("%d", ans);
}