#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int search(double *arr, int N, double target)
{
    int low = 0, high = N - 1, mid = (low + high) / 2;
    while (high > low)
    {
        if (arr[mid] > target) high = mid;
        else low = mid + 1;
        mid = (low + high) / 2;
    }
    return mid;
}
int main()
{
    int N;
    cin >> N;
    double arr[100005];
    for (int i = 0; i < N; ++i)
        scanf("%lf", &arr[i]);

    int k;
    cin >> k;
    double b, c;
    for (int i = 0; i < k; ++i)
    {
        scanf("%lf%lf", &b, &c);
        double target = b * b / (4.0 * c);
        if (target > arr[N - 1]) printf("%d\n", N);
        else printf("%d\n", search(arr, N, target));
    }
    return 0;
}
