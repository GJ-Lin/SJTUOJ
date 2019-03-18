#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[1005];
    int max = 0, sum = 0;
    char ch;
    for (int i = 0; i < n; ++i)
    {
        cin >> ch >> arr[i];
        if (arr[i] > max) max = arr[i];
    }
    for (int i = 1; i <= max; ++i)
    {
        int j = 0;
        while (arr[j] < i) ++j;
        int k = n - 1;
        while (arr[k] < i) --k;
        for (int l = j + 1; l <= k - 1; ++l)
        {
            if (arr[l] < i) ++sum;
        }
    }
    cout << sum;
    //for (int i = 0; i < n; ++i) cout << arr[i];
    return 0;
}
