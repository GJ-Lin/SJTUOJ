#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double Pi = acos(-1);

int main()
{
    double r, d;
    double max = 0;
    while (cin >> r >> d)
    {
        double s1, s2;
        s1 = acos(d / r) * r * r;
        s2 = sqrt(r * r -  d * d) * d;
        //cout << s1 << ' ' << s2 << endl;
        max = (s1 - s2 > max) ? s1 - s2 : max;
    }
    printf("%.2f\n", max);
    return 0;
}