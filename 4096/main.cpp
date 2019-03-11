#include <iostream>
#include <cstring>
using namespace std;
const int MAXNUM = 30;
int box[MAXNUM][MAXNUM], N;
struct order
{
	string o1, o2;
	int a, b;
};
struct pos
{
	int x, y;
}idx[MAXNUM];
bool isLegal(int a, int b)
{
	if (a == b || idx[a].x == idx[b].x)
		return false;
	return true;
}
void reset(int x, int y)
{
	int tmp = box[x][y];
	box[tmp][0] = tmp;
	box[x][y] = -1;
	idx[tmp].x = tmp;
	idx[tmp].y = 0;
}
void move(int n, int x, int y)
{
	box[x][y] = n;
	box[idx[n].x][idx[n].y] = -1;
	idx[n].x = x;
	idx[n].y = y;
}
void printall()
{
	for (int i = 0; i < N; ++i)
	{
		cout << i << ':';
		for (int j = 0; box[i][j] != -1; ++j)
			cout << ' ' << box[i][j];
		if (i < N - 1)
			cout << endl;
	}
}
void move_over(int a, int b)
{
	//cout << "move_over called." << endl;
	for (int j = idx[a].y + 1; box[idx[a].x][j] != -1; ++j)
		reset(idx[a].x, j);

	int top = idx[b].y + 1;
	while (box[idx[b].x][top] != -1) ++top;
	move(a, idx[b].x, top);
}
void move_onto(int a, int b)
{
	//cout << "move_onto called." << endl;
	for (int j = idx[a].y + 1; box[idx[a].x][j] != -1; ++j)
		reset(idx[a].x, j);
	for (int j = idx[b].y + 1; box[idx[b].x][j] != -1; ++j)
		reset(idx[b].x, j);

	move(a, idx[b].x, idx[b].y + 1);
}
void pile_over(int a, int b)
{
	//cout << "pile_over called." << endl;
	int top = idx[b].y + 1;
	while (box[idx[b].x][top] != -1) ++top;
	int tmpx = idx[a].x;
	for (int j = idx[a].y; box[tmpx][j] != -1; ++j)
	{
		int tmp = box[tmpx][j];
		move(tmp, idx[b].x, top);
		++top;
	}
}
void pile_onto(int a, int b)
{
	//cout << "pile_onto called." << endl;
	for (int j = idx[b].y + 1; box[idx[b].x][j] != -1; ++j)
		reset(idx[b].x, j);
	pile_over(a, b);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		box[i][0] = i;
		idx[i].x = i;
		idx[i].y = 0;
		for (int j = 1; j < N; ++j)
			box[i][j] = -1;
	}
	order arr[200];
	int orders = 0;
	string tmp;
	cin >> tmp;
	while (strcmp(tmp.c_str(), "quit"))
	{
		arr[orders].o1 = tmp;
		cin >> arr[orders].a >> arr[orders].o2 >> arr[orders].b;
		++orders;
		cin >> tmp;
	}
	for (int i = 0; i < orders; ++i)
	{
		if (!isLegal(arr[i].a, arr[i].b)) continue;

		if (arr[i].o1 == "move")
		{
			if (arr[i].o2 == "over")
				move_over(arr[i].a, arr[i].b);
			else
				move_onto(arr[i].a, arr[i].b);
		}
		else
		{
			if (arr[i].o2 == "over")
				pile_over(arr[i].a, arr[i].b);
			else
				pile_onto(arr[i].a, arr[i].b);
		}
		//printall();
	}

	printall();
	
	return 0;
}
