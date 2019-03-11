#include <iostream>
#include <cstring>
using namespace std;
const int MAXNUM = 1000000;
class LongLongInt
{
	friend istream &operator>>(istream &is, LongLongInt &num)
	{
		char str[MAXNUM];
		is >> str;
		for (int i = 0; i <= strlen(str) - 1; ++i)
			num.push_back(str[i] - '0');
		return is;
	}
	friend ostream &operator<<(ostream &os, const LongLongInt &num)
	{
		node *p = num.head->next;
		while (p != num.tail)
		{
			os << p->data;
			p = p->next;
		}
		return os;
	}
	friend LongLongInt operator+(const LongLongInt &num_1, const LongLongInt &num_2)
	{
		node *p = num_1.tail->prev, *q = num_2.tail->prev;
		int carry = 0, add_1, add_2, result;
		LongLongInt num_3;
		while (p != num_1.head || q != num_2.head)
		{
			if (p != num_1.head)
			{
				add_1 = p->data;
				p = p->prev;
			}
			else
				add_1 = 0;

			if (q != num_2.head)
			{
				add_2 = q->data;
				q = q->prev;
			}
			else
				add_2 = 0;

			result = add_1 + add_2 + carry;
			num_3.push_front(result % 10);
			carry = result / 10;
		}
		if (carry)
			num_3.push_front(1);
		return num_3;
	}
public:
	LongLongInt()
	{
		head = new node;
		head->next = tail = new node;
		tail->prev = head;
	}
	void push_front(const int &x)
	{
		node *tmp = new node(x, head, head->next);
		head->next = tmp;
		tmp->next->prev = tmp;
	}
	void push_back(const int &x)
	{
		node *tmp = new node(x, tail->prev, tail);
		tmp->prev->next = tmp;
		tail->prev = tmp;
	}
private:
	struct node
	{
		int data;
		node *prev, *next;

		node(const int &x, node *p, node *n) : data(x), prev(p), next(n) {}
		node() {}
		~node() {}
	};
	node *head, *tail;
};


int main()
{
	LongLongInt num_1, num_2;
	cin >> num_1 >> num_2;
	LongLongInt num_3 = num_1 + num_2;
	cout << num_3;
	return 0;
}
