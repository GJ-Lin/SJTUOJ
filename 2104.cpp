#include <iostream>
using namespace std;
const int MAXNUM = 605;
bool map[2 * MAXNUM][2 * MAXNUM]{};
int X, Y, N;
int front, rear;

struct Direction
{
    int x, y;
}dir[4]{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

struct Node
{
    int x, y, step;
}trail[MAXNUM * MAXNUM];

bool check(const Node &tmp)
{
    if (tmp.x < 0 || tmp.x > 2 * MAXNUM - 1 || tmp.y < 0 || tmp.y > 2 * MAXNUM - 1 || map[tmp.x][tmp.y]) return false;
    return true;
}

int main()
{
    cin >> X >> Y >> N;
    X += MAXNUM;
    Y += MAXNUM;
    int x, y;
    while (N--)
    {
        cin >> x >> y;
        map[MAXNUM + x][MAXNUM + y] = true;
    }
    int step = 0;
    front = 0;
    rear = 0;
    trail[front].x = MAXNUM;
    trail[front].y = MAXNUM;
    trail[front].step = step;
    while (true)
    {
        Node now = trail[front], tmp;
        ++front;
        if (now.x == X && now.y == Y)
        {
            cout << now.step << endl;
            return 0;
        }
        for (int i = 0; i < 4; ++i)
        {
            tmp.x = now.x + dir[i].x;
            tmp.y = now.y + dir[i].y;
            tmp.step = now.step + 1;
            if (check(tmp))
            {
                trail[++rear] = tmp;
                map[tmp.x][tmp.y] = true;
            }
        }
    }
    return 0;
}