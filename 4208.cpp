#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXNUM = 1005;

inline int Max(const int &a, const int &b)
{
    return a > b ? a : b;
}
inline int Min(const int &a, const int &b)
{
    return a < b ? a : b;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b, x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &x1, &y1, &x2, &y2);
        long long ans_a, ans_b, ta1, ta2, tb1, tb2;        
        ta1 = floor(1.0 * (y1 + x1) / (2 * a));
        ta2 = floor(1.0 * (y2 + x2) / (2 * a));
        tb1 = floor(1.0 * (y1 - x1) / (2 * b));
        tb2 = floor(1.0 * (y2 - x2) / (2 * b));
        ans_a = ta1 > ta2 ? (ta1 - ta2) : (ta2 - ta1);
        ans_b = tb1 > tb2 ? (tb1 - tb2) : (tb2 - tb1);
 
        printf("%d\n", (ans_a > ans_b ? ans_a : ans_b));
    }
}