#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double sum = 0;
    for (int i = 0; i < N; ++i)
    {
        int x;
        scanf("%d", &x);
        if (x >= 95) sum += 4.3;
        else if (x >= 90) sum += 4.0;
        else if (x >= 85) sum += 3.7;
        else if (x >= 80) sum += 3.3;
        else if (x >= 75) sum += 3.0;
        else if (x >= 70) sum += 2.7;
        else if (x >= 67) sum += 2.3;
        else if (x >= 65) sum += 2.0;
        else if (x >= 62) sum += 1.7;
        else if (x >= 60) sum += 1.0;
    }
    printf("%.2f", sum / N);
}