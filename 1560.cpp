#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 10005;
bool trail[maxn];
int cnt;
struct Node
{
	int value;
	Node* lson, * rson;
	//Node() : value(-1), lson(NULL), rson(NULL) {}
	Node(int _value, Node* _lson = NULL, Node* _rson = NULL) : value(_value), lson(_lson), rson(_rson) {}
	//bool empty() { return value == -1; }
};

class binaryTree
{
public:
	binaryTree()
	{
		root = NULL;
	}
	void insert(int data, Node*& t)
	{
		if (t == NULL)
			t = new Node(data);
		else if (data < t->value)
			insert(data, t->lson);
		else if (data > t->value)
			insert(data, t->rson);
		/*
		if (root->empty())
		{
			root->value = data;
			return;
		}

		Node* tmp = root;
		while (true)
		{
			if (tmp->value == data) return;
			if (data < tmp->value)
			{
				if (tmp->lson == NULL || tmp->lson->empty())
				{
					tmp->lson = new Node(data);
					return;
				}
				tmp = tmp->lson;
			}
			else
			{
				if (tmp->rson == NULL || tmp->rson->empty())
				{
					tmp->rson = new Node(data);
					return;
				}
				tmp = tmp->rson;
			}
		}
		*/
	}
	void remove(int data, Node*& t)
	{
		if (t == NULL) return;
		if (data < t->value) remove(data, t->lson);
		else if (data > t->value) remove(data, t->right);
		/*
		if (root->empty()) return;
		Node* tmp = root;
		while (true)
		{
			if (tmp->value == data)
			{
				if (tmp->rson == NULL || tmp->rson->empty())
				{
					if (tmp->lson && !tmp->lson->empty())
					{
						Node* delp = tmp->lson;
						*tmp = *(tmp->lson);
						delete delp;
					}
					else
						tmp->value = -1;
				}
				else
				{
					Node* pmin = tmp->rson;
					while (pmin->lson && !pmin->lson->empty()) pmin = pmin->lson;
					tmp->value = pmin->value;
					if (pmin->rson && !pmin->rson->empty())
					{
						Node* delp = tmp->rson;
						*pmin = *(pmin->rson);
						delete delp;
					}
					else
						pmin->value = -1;
				}
				return;
			}
			else
			{
				if (data < tmp->value)
				{
					if (tmp->lson && !tmp->lson->empty())
						tmp = tmp->lson;
					else
						return;
				}
				else
				{
					if (tmp->rson && !tmp->rson->empty())
						tmp = tmp->rson;
					else
						return;
				}
			}
		}
		*/
	}
	void search(int data)
	{
		if (root->empty()) return;
		Node* tmp = root;
		cnt = 0;
		while (true)
		{
			if (tmp->value == data)
			{
				break;
			}
			if (data < tmp->value)
			{
				if (!tmp->lson || tmp->lson->empty())
				{
					printf("Nothing.\n");
					//cout << "Nothing." << endl;
					return;
				}
				else
				{
					trail[cnt++] = false;
					tmp = tmp->lson;
				}
			}
			else
			{
				if (!tmp->rson || tmp->rson->empty())
				{
					printf("Nothing.\n");
					//cout << "Nothing." << endl;
					return;
				}
				else
				{
					trail[cnt++] = true;
					tmp = tmp->rson;
				}
			}
		}
		putchar('*');
		//cout << '*';
		for (int i = 0; i < cnt; ++i)
		{
			putchar(trail[i] ? 'r' : 'l');
			//cout << (trail[i] ? 'r' : 'l');
		}
		putchar('\n');
		//cout << endl;
	}
private:
	Node* root;
};

binaryTree bt;

int main()
{
	int q;
	cin >> q;
	char order;
	int data;
	while (q--)
	{
		getchar();
		scanf("%c%d", &order, &data);
		//cin >> order >> data;
		switch (order)
		{
		case '+':
			bt.insert(data);
			break;
		case '-':
			bt.remove(data);
			break;
		case '*':
			bt.search(data);
			break;
		default:
			break;
		}
	}
	return 0;
}