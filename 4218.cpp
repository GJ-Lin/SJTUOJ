#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 5000005;
int n, d;
int arr[MAXNUM];
struct beds
{
    int pos, noise;
}queue[MAXNUM];

inline int read() {
    int X = 0, w = 0;
    char ch = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return X;
}

inline void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        putchar(x / y + 48);
        x %= y;
    }
}
int main()
{
    int cnt = 0;
    n = read();
    d = read();
    for (int i = 1; i <= n; ++i)
        arr[i] = read();
    int front = 1, rear = 1;
    queue[front].noise = arr[1];
    queue[front].pos = 1;
    int i, a;
    for (i = 2; i <= d + 1; ++i)
    {
        if (arr[i] <= queue[rear].noise)
        {
            ++rear;
            queue[rear].noise = arr[i];
            queue[rear].pos = i;
        }
        else
        {
            while (front <= rear && arr[i] > queue[rear].noise)
                --rear;
            ++rear;
            queue[rear].noise = arr[i];
            queue[rear].pos = i;
        }
    }
    for (i = d + 2, a = 1; i <= n; ++i, ++a)
    {
        while (front <= rear && queue[front].pos + d < a)
            ++front;

        if (queue[front].noise > arr[a] * 2)
            ++cnt;
        if (arr[i] <= queue[rear].noise)
        {
            ++rear;
            queue[rear].noise = arr[i];
            queue[rear].pos = i;
        }
        else
        {
            while (front <= rear && arr[i] > queue[rear].noise)
                --rear;
            ++rear;
            queue[rear].noise = arr[i];
            queue[rear].pos = i;
        }
    }
    for (; a <= n; ++a)
    {
        while (front <= rear && queue[front].pos + d < a)
            ++front;

        if (queue[front].noise > arr[a] * 2)
            ++cnt;
    }


    cout << cnt;
    return 0;
}