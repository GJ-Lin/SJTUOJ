#include <iostream>
#include <cstdio>
using namespace std;
const double eps = 1e-6;

int field[250005];
int M, N;
long long V;
int area;
double alti, pct; 

void quicksort(int low, int high)
{
    if (low >= high) return;

    int k = field[low], tmp, lf = low, rh = high;
    while (lf < rh)
    {
        while (field[rh] >= k && lf < rh) --rh;
        while (field[lf] <= k && lf < rh) ++lf;
        if (lf < rh)
        {
            tmp = field[rh];
            field[rh] = field[lf];
            field[lf] = tmp;
        }
    }
    field[low] = field[lf];
    field[lf] = k;
    quicksort(low, lf - 1);
    quicksort(rh + 1, high);
}

int main()
{
    scanf("%d%d", &M, &N);
    area = M * N;
    for (int i = 0; i < area; ++i)
        scanf("%d", &field[i]);

    scanf("%lld", &V);
    quicksort(0, area - 1);

    long long sum = 0;

    int i = 0;
    while (sum < V && i < area - 1)
    {
        ++i;
        sum += (field[i] - field[i - 1]) * i;
    }

    if (sum == V)
    {
        alti = field[i];
        while (i > 0 && field[i] == field[i - 1]) --i;
        pct = 100.0 * i / area;
    }
    else if (sum < V)
    {
        alti = field[area - 1] + double(V - sum) / area;
        pct = 100.0;
    }
    else
    {
        alti = field[i] - double(sum - V) / i;
        pct = 100.0 * i / area;
    }
    printf("%.2f\n%.2f", alti, pct);
    return 0;
}