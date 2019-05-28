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
	char data;
	node* next;
	node(char _data_, node* _next_ = NULL) : data(_data_), next(_next_) {}
};

struct vector
{
	node* head;
	node* tail;
	vector() { tail = head = new node(0, NULL); }
	void makeEmpty()
	{
		node* p = head->next, * t;
		while (p != NULL)
		{
			t = p;
			p = p->next;
			delete t;
		}
		tail = head = new node(0, NULL);
	}
}tag[maxn << 2];

inline void pushdown(int rt)
{
	node* p = tag[lson].tail, * q = tag[rson].tail, * t = tag[rt].head->next;
	while (t)
	{
		p = p->next = new node(t->data, NULL);
		q = q->next = new node(t->data, NULL);
		t = t->next;
	}
	tag[lson].tail = p;
	tag[rson].tail = q;
	tag[rt].makeEmpty();
}

void update(int L, int R, int C, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		tag[rt].tail = tag[rt].tail->next = new node(C, NULL);
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
		node* t = tag[rt].head->next;
		cout << l << ": ";
		while (t)
		{
			cout << int(t->data) << ' ';
			t = t->next;
		}
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
			node* p = tag[X].head->next, * q = tag[Y].head->next;
			while (p && q)
			{
				if (p->data != q->data)
				{
					flag = false;
					break;
				}
				p = p->next;
				q = q->next;
			}
			if (p || q) flag = false;
			if (flag)
			{
				cout << "YES\n";
				//print(1, n, 1);
				//cout << '\n';
				tag[X].makeEmpty();
				tag[Y].makeEmpty();
			}
			else
			{
				cout << "NO\n";
				//print(1, n, 1);
				//cout << '\n';
			}
		}
	}
	return 0;
}