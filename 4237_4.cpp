#include <iostream>
#include <cstring>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long ll;
const int maxn = 200005;
int cnt[maxn << 2]{ 0 };
int X, Y;

struct node
{
	short data;
	node* next;
	node(short _data_, node* _next_ = NULL) : data(_data_), next(_next_) {}
};

struct vector
{
    short* data;
    int currentsize;
    int maxsize = 10;
	vector()
    {
        data = new short[maxsize];
        currentsize = 0;
    }
    ~vector()
    {
        delete [] data;
    }
    void push(short x)
    {
        if (currentsize == maxsize)
        doubleSpace();
        data[currentsize++] = x;
    }
    void doubleSpace()
    {
        short* tmp = data;
        maxsize <<= 1;
        data = new short[maxsize];
        for (int i = 0; i < currentsize; ++i)
            data[i] = tmp[i];
        delete tmp;
    }
	void makeEmpty()
	{
        delete [] data;
        data = new short[maxsize];
        currentsize = 0;
	}
}tag[maxn << 2];

inline void pushdown(int rt)
{
   for (int i = 0; i < tag[rt].currentsize; ++i)
   {
       tag[lson].push(tag[rt].data[i]);
       tag[rson].push(tag[rt].data[i]);
   }
   tag[rt].makeEmpty();
}

void update(int L, int R, int C, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
        tag[rt].push(C);
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid) update(L, R, C, l, mid, lson);
	if (R > mid) update(L, R, C, mid + 1, r, rson);
}

void queryX(int x, int l, int r, int rt)
{
	if (l == r)
	{
		X = rt;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (x <= mid) return queryX(x, l, mid, lson);
	else return queryX(x, mid + 1, r, rson);
}

void queryY(int x, int l, int r, int rt)
{
	if (l == r)
	{
		Y = rt;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (x <= mid) return queryY(x, l, mid, lson);
	else return queryY(x, mid + 1, r, rson);
}

void print(int l, int r, int rt)
{
	if (l == r)
	{
        cout << l << ": ";
        for (int i = 0; i < tag[rt].currentsize; ++i)
            cout << tag[rt].data[i] << ' ';
		cout << '\n';
		return;
	}
	int mid = (l + r) >> 1;
	print(l, mid, lson);
	print(mid + 1, r, rson);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int order, l, r, k, x, y;
	while (m--)
	{
		cin >> order;
		if (order == 0)
		{
			cin >> l >> r >> k;
			update(l, r, k, 1, n, 1);
		}
		else
		{
			cin >> x >> y;
			queryX(x, 1, n, 1);
			queryY(y, 1, n, 1);
			bool flag = true;
            if (tag[X].currentsize != tag[Y].currentsize)
                flag = false;
            else
            {
                for (int i = 0; i < tag[X].currentsize; ++i)
                    if (tag[X].data[i] != tag[Y].data[i])
                    {
                        flag = false;
                        break;
                    }
            }
            if (flag)
            {
                cout << "YES\n";
                tag[X].makeEmpty();
                tag[Y].makeEmpty();
            }
            else
            {
                cout << "NO\n";
            }
		}
	}
	return 0;
}