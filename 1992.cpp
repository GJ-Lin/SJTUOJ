#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 10005;
struct range
{
    long long lf, rh;
}bodies[MAXNUM];

void quicksort(int low, int high)
{
    if (low >= high) return;

    int bg = low, ed = high;
    range k = bodies[low], tmp;
    while (bg < ed)
    {
        while (bodies[ed].lf >= k.lf && bg < ed) --ed;
        while (bodies[bg].lf <= k.lf && bg < ed) ++bg;
        if (bg < ed)
        {
            tmp = bodies[ed];
            bodies[ed] = bodies[bg];
            bodies[bg] = tmp;
        }
    }
    bodies[low] = bodies[bg];
    bodies[bg] = k;
    quicksort(low, bg - 1);
    quicksort(ed + 1, high);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld%lld", &bodies[i].lf, &bodies[i].rh);
    }
    quicksort(0, n - 1);

    long long sum = bodies[0].rh - bodies[0].lf, last = bodies[0].rh;
    for (int i = 1; i < n; ++i)
    {
        if (bodies[i].lf >= last)
        {
            sum += bodies[i].rh - bodies[i].lf;
            last = bodies[i].rh;
        }
        else
        {
            if (bodies[i].rh > last)
            {
                sum += bodies[i].rh - last;
                last = bodies[i].rh;
            }
        }
    }
    printf("%lld", sum);
    return 0;
}