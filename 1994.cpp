#include <iostream>
using namespace std;
const int MAXNUM = 505;
int N, M;
int map[MAXNUM][MAXNUM];
int cnt = 0;

struct direction
{
    int x, y;
}dir[4]{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool isBlankLand(int x, int y)
{
    if (x < 0 || x > N - 1 || y < 0 || y > M - 1 || map[x][y]) return false;
    return true;
}

void fill(int x, int y)
{
    int tx, ty;
    map[x][y] = -1;
    for (int i = 0; i < 4; ++i)
    {
        tx = x + dir[i].x;
        ty = y + dir[i].y;
        if (isBlankLand(tx, ty)) fill(tx, ty);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j]) continue;
            ++cnt;
            fill(i, j);
        }
    cout << cnt;
    return 0;
}