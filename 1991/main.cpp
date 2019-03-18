#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double eps = 1e-8;
int n, k;
double R, lastR;
double minR, maxR, midR;
double x[100005];
bool AllKill(double tryR)
{
    int lf = 0, count = 1;
    for (int rh = 1; rh < n; ++rh)
    {
        if (rh < n && x[rh] - x[lf] - 2 * tryR < eps) continue;
        else
        {
            ++count;
            lf = rh;
            if (count > k) return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%lf", &x[i]);
    lastR = R = maxR;
    minR = 0, maxR = x[n - 1] - x[0];
    midR = (minR + maxR) / 2;
    while (true)
    {
        if (AllKill(midR))
        {
            lastR = R;
            R = midR;
            maxR = midR;
            if (fabs(lastR - R) < eps) break;
        }
        else minR = midR;
        midR = (minR + maxR) / 2;
    }
    cout << fixed << setprecision(6) << R;
    return 0;
}
