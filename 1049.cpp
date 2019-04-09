#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 2005;
int order[MAXNUM];
int adjust[MAXNUM];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i)
            scanf("%d", &order[i]);

        int last = 0;
        int top = -1;
        bool flag = true;
        int now = 0;
        while (flag && now < N)
        {
            if (now == order[last])
                ++last;
            else
            {
                adjust[++top] = now;
                if (top + 1 > M)
                {
                    flag = false;
                    break;
                }
            }
            while (top != -1 && adjust[top] == order[last])
            {
                --top;
                ++last;
            }
            ++now;
        }
        while (top != -1 && adjust[top] == order[last])
        {
            --top;
            ++last;
        }
        if (flag && top == -1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}