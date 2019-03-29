#include <iostream>
using namespace std;
long long L, R;

int GetFirst(long long X)
{
    while (X >= 10) X /= 10;
    return X;
}
int GetLast(long long X)
{
    return X % 10;
}
long long calc(long long X)
{
    long long ans = 0;
    if (X < 10) ans = X + 1;
    else
    {
        ans = X / 10;
        if (GetLast(X) >= GetFirst(X)) ++ans;
        ans += 9;
    }
    return ans;
}

int main()
{
    cin >> L >> R;
    cout << calc(R) - calc(L - 1);
    return 0;
}