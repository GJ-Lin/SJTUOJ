#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1005;
int arr[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int order, l, r;
    int sum, max, tmp;
    while (m--)
    {
        cin >> order >> l >> r;
        switch (order)
        {
        case 0:
            sum = 0;
            for (int i = l; i <= r; ++i)
                sum += arr[i];
            printf("%.2f\n", double(sum) / (r - l + 1));
            //printf("%.2f\n", double(query(l, r, 1, n, 1)) / (r - l + 1));
            break;
        case 1:
            max = 0;
            for (int i = l; i <= r; ++i)
                if (arr[i] > max) max = arr[i];
            cout << max << '\n';
            break;
        case 2:
            while (l < r)
            {
                tmp = arr[r];
                arr[r] = arr[l];
                arr[l] = tmp;
                ++l;
                --r;
            }
            break;
        case 3:
            for (int i = l; i <= r; ++i)
                cout << arr[i] << ' ';
            cout << '\n';
            break;
        case 4:
            for (int i = l; i <= r; ++i)
                if (arr[i]) --arr[i];
            break;
        default:
            break;
        }
    }
    return 0;
}