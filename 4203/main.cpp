#include <iostream>
#include <cstdio>
using namespace std;
const int P = 1000000007;
const int MAXNUM = 100002;
long long fac[MAXNUM];

long long quickpow(long long a, long long k, int p)
{
    long long result = 1;
    long long tmp = a % p;
    while (k)
    {
        if (k & 1) result = result * tmp % p;
        tmp = tmp * tmp % p;
        k >>= 1;
    }
    return result;
}

long long C(long long n, long long m, int p)
{
    if (m > n) return 0;
    return fac[n] * quickpow(fac[m], p - 2, p) % p * quickpow(fac[n - m], p - 2, p) % p;
}

long long Lucas(long long n, long long m, int p)
{
    long long result = 1;
    while (n && m)
    {
        result = result * C(n % p, m % p, p) % p;
        n /= p;
        m /= p;
    }
    return result;
}

void init(int p)
{
    fac[0] = 1;
    for (int i = 1; i <= MAXNUM; ++i)
        fac[i] = fac[i - 1] * i % p;
}

int main()
{
    init(P);
    long long n, m;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", C(n, m, P));
    }
    return 0;
}
