#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    int sum = 0, max_sum = 0;
    cin >> sum;
    int i, j;
    for (i = 0, j = 1; j < n - 1; ++j)
    {
        cin >> x;
        sum += x;
        if (sum < 0)
        {
            sum = 0;
            i = j + 1;
            continue;
        }
        if (sum > max_sum && i != j)
            max_sum = sum;
    }
    cin >> x;
    sum += x;
    if (sum > max_sum)
            max_sum = sum;
    if (max_sum > 0)
        cout << max_sum;
    else
        cout << "Game Over";
    return 0;
}
