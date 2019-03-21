#include <iostream>
#include <cstdio>
using namespace std;
const int MAXNUM = 100005;
int N, R;
struct Attribute
{
    int number, force, score;
}mice[MAXNUM * 2], winner[MAXNUM], loser[MAXNUM];

int cmp(const Attribute &a, const Attribute &b)
{
    if (a.score > b.score) return -1;
    else if (a.score < b.score) return 1;
    else if (a.number < b.number) return -1;
    else return 1;
}

void Quicksort(int low, int high)
{
    if (low >= high) return;

    int lf = low, rh = high;
    Attribute k = mice[low], tmp;
    while (lf < rh)
    {
        while (lf < rh && cmp(mice[rh], k) > 0) --rh;
        if (lf < rh)
        {
            tmp = mice[rh];
            mice[rh] = mice[lf];
            mice[lf] = tmp;
        }
        while (lf < rh && cmp(mice[lf], k) < 0) ++lf;
        if (lf < rh)
        {
            tmp = mice[rh];
            mice[rh] = mice[lf];
            mice[lf] = tmp;
        }
    }
    Quicksort(low, lf - 1);
    Quicksort(rh + 1, high);
}

void Mergesort()
{
    int i = 0, j = 0, k = 0;
    for (; i < N && j < N; ++k)
    {
        if (cmp(winner[i], loser[j]) < 0)
            mice[k] = winner[i++];
        else
            mice[k] = loser[j++];
    }
    while (i < N) mice[k++] = winner[i++];
    while (j < N) mice[k++] = loser[j++];
}

void Compete()
{
    Attribute tmp;
    int k;
    for (int i = 0, j = 0; i < 2 * N; i += 2, ++j)
    {
        if (mice[i].force > mice[i + 1].force)
        {
            mice[i].score += 2;
            winner[j] = mice[i];
            loser[j] = mice[i + 1];
        }
        else if (mice[i].force < mice[i + 1].force)
        {
            mice[i + 1].score += 2;
            winner[j] = mice[i + 1];
            loser[j] = mice[i];
        }
        else
        {
            mice[i].score++;
            mice[i + 1].score++;
            winner[j] = mice[i];
            loser[j] = mice[i + 1];
        }

        k = j - 1;
        while (k > 0 && cmp(winner[k], winner[j]) > 0) --k;
        if (k < j - 1)
        {
            ++k;
            tmp = winner[j];
            winner[j] = winner[k];
            winner[k] = tmp;
        }

        k = j - 1;
        while (k > 0 && cmp(loser[k], loser[j]) > 0) --k;
        if (k < j - 1)
        {
            ++k;
            tmp = loser[j];
            loser[j] = loser[k];
            loser[k] = tmp;
        }
    }
}

int main()
{
    scanf("%d%d", &N, &R);
    for (int i = 0; i < 2 * N; ++i)
    {
        scanf("%d", &mice[i].score);
        mice[i].number = i;
    }
    
    for (int i = 0; i < 2 * N; ++i)
        scanf("%d", &mice[i].force);

    Quicksort(0, 2 * N - 1);

    while (R--)
    {
        Compete();
        Mergesort();
    }

    for (int i = 0; i < 2 * N; ++i)
        printf("%d ", mice[i].number + 1);
    return 0;
}