#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char target[105], plasmid[105];
    cin >> target;
    char head = target[1];
    int count = 0;
    bool flag;
    for (int i = 0; i < n; ++i)
    {
        flag = false;
        cin >> plasmid;
        if (strlen(plasmid) != strlen(target)) continue;

        for (int j = 1; j <= strlen(target) - 2; ++j)
        {
            if (flag) break;

            if (plasmid[j] != head) continue;

            else
            {
                int k = j + 1, l = 2;
                if (k > strlen(target) - 2) k = 1;
                bool isTheSame = true;
                while (k != j)
                {
                    if (plasmid[k] != target[l])
                    {
                        isTheSame = false;
                        break;
                    }
                    ++k;
                    ++l;
                    if (k > strlen(target) - 2) k = 1;
                }
                if (isTheSame)
                {
                    flag = true;
                    break;
                }

                k = j - 1;
                if (k < 1) k = strlen(target) - 2;
                l = 2;
                isTheSame = true;
                while (k != j)
                {
                    if (plasmid[k] != target[l])
                    {
                        isTheSame = false;
                        break;
                    }
                    --k;
                    ++l;
                    if (k < 1) k = strlen(target) - 2;
                }
                if (isTheSame)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) ++count;
    }
    cout << count;
    return 0;
}
