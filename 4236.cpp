#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int v[maxn], r[maxn];
ll sum[maxn]{0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i)
        cin >> r[i];
    for (int i = 1; i <= n; ++i)
    {
        int j = i;
        for (int j = i; j <= n; ++j)
        {
            if (v[i] >= r[j])
                sum[j] += r[j];
            else
            {
                sum[j] += v[i];
                break;
            }
            v[i] -= r[j];
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << sum[i] << ' ';
    return 0;
}