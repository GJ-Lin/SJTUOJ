#include <iostream>
using namespace std;
long N, i, j;
long min_len;
long out = 0, in = 0;
long x, y;
long tmp;
void walk(long a, long b)
{
    while (a != i || b != j)
    {
        while ((a != i || b != j) && a > min_len + 1)
        {
            --a;
            ++in;
        }
        while ((a != i || b != j) && b < N - min_len)
        {
            ++b;
            ++in;
        }
        while ((a != i || b != j) && a < N - min_len)
        {
            ++a;
            ++in;
        }
        while ((a != i || b != j) && b > min_len + 1)
        {
            --b;
            ++in;
        }
    }

}
int main()
{
    cin >> N >> i >> j;
    min_len = N;
    if (i - 1 < min_len) min_len = i - 1;
    if (j - 1 < min_len) min_len = j - 1;
    if (N - i < min_len) min_len = N - i;
    if (N - j < min_len) min_len = N - j;
    out = 4 * min_len * (N - min_len);
    x = N - min_len;
    y = 1 + min_len;

    walk(x, y);
    cout << out + in << ' ';

    i = N - i + 1;
    j = N - j + 1;

    in = 0;
    walk(x, y);
    cout << out + in;

    return 0;
}
