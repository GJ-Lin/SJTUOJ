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
		for (int i = strlen(str) - 1; i >= 0; --i)
			num.push_back(str[i] - '0');
		return is;
	}
	friend ostream &operator<<(ostream &os, const LongLongInt &num)
	{
		node *p = num.head->next;
		while (p != NULL)
		{
			os << p->data;
			p = p->next;
		}
		return os;
	}
	friend LongLongInt operator+(const LongLongInt &num_1, const LongLongInt &num_2)
	{

		int carry = 0, add_1, add_2, result;
		LongLongInt num_3;
		node *p = (num_1.length > num_2.length ? num_1.head->next : num_2.head->next);
		node *q = (num_2.length >= num_1.length ? num_1.head->next : num_2.head->next);
		int len_1 = (num_1.length > num_2.length ? num_1.length : num_2.length);
		int len_2 = (num_2.length >= num_1.length ? num_1.length : num_2.length);
		for (int i = 0; i < len_2; ++i, p = p->next, q = q->next)
		{
			add_1 = p->data;
			add_2 = q->data;
			result = add_1 + add_2 + carry;
			num_3.push_front(result % 10);
			carry = result / 10;
		}
		for (int i = 0; i < len_1 - len_2; ++i, p = p->next)
		{
			result = p->data + carry;
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
		tail = head;
		length = 0;
	}
	void push_front(const int &x)
	{
		node *tmp = new node(x, head->next);
		head->next = tmp;
		++length;
	}
	void push_back(const int &x)
	{
		node *tmp = new node(x);
		tail->next = tmp;
		tail = tmp;
		++length;
	}
private:
	struct node
	{
		int data;
		node *next;

		node(const int &x, node *n = NULL) : data(x), next(n) {}
		node() : next(NULL){}
		~node() {}
	};
	node *head, *tail;
	int length;
};


int main()
{
	LongLongInt num_1, num_2;
	cin >> num_1 >> num_2;
	LongLongInt num_3 = num_1 + num_2;
	cout << num_3;
	return 0;
}
