#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

struct Matrix
{
    ll a11, a12, a21, a22;
    Matrix(ll _a11, ll _a12, ll _a21, ll _a22) : a11(_a11), a12(_a12), a21(_a21), a22(_a22) {}
    Matrix(const Matrix &other) : a11(other.a11), a12(other.a12), a21(other.a21), a22(other.a22) {}
};

Matrix operator*(const Matrix &m1, const Matrix &m2)
{
    Matrix ret(0, 0, 0, 0);
    ret.a11 = (m1.a11 * m2.a11 % MOD + m1.a12 * m2.a21 % MOD) % MOD;
    ret.a12 = (m1.a11 * m2.a12 % MOD + m1.a12 * m2.a22 % MOD) % MOD;
    ret.a21 = (m1.a21 * m2.a11 % MOD + m1.a22 * m2.a21 % MOD) % MOD;
    ret.a22 = (m1.a21 * m2.a12 % MOD + m1.a22 * m2.a22 % MOD) % MOD;
    return ret;
}

Matrix pow(Matrix x, ll n)
{
    Matrix ret(1, 0, 0, 1), tmp(x);
    while (n != 0)
    {
        if (n & 1)
            ret = ret * tmp;
        tmp = tmp * tmp;
        n >>= 1;
    }
    return ret;
}

int main()
{
    ll n;
    cin >> n;
    Matrix mtx(1, 1, 1, 0);
    mtx = pow(mtx, n + 1);
    cout << mtx.a21 << endl;
}
