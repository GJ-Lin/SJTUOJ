#include <iostream>
#include <cstring>
using namespace std;
const int MAXNUM = 10010;
template <class elemType>
class seqList
{
	friend seqList<elemType> operator+(const seqList<elemType> &list_1, const seqList<elemType> list_2)
	{
		seqList<elemType> list_3;
		for (int i = 0; i < list_1.length(); ++i)
			list_3.insert(list_3.length(), list_1.visit(i));
		for (int i = 0; i < list_2.length(); ++i)
			list_3.insert(list_3.length(), list_2.visit(i));
		return list_3;
	}
public:
	seqList();
	int length() const;
	void insert(int i, const elemType &x);
	void get_input(int n);
	elemType visit(int i) const;
	void traverse() const;
	~seqList();
private:
	elemType data[MAXNUM];
	int currentLength;
};

template <class elemType>
seqList<elemType>::seqList()
{
	currentLength = 0;
}

template <class elemType>
int seqList<elemType>::length() const
{
	return currentLength;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
	for (int j = currentLength; j > i; --j)
		data[j] = data[j - 1];
	data[i] = x;
	++currentLength;
}

template <class elemType>
void seqList<elemType>::get_input(int n)
{
	elemType x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		insert(currentLength, x);
	}
}

template <class elemType>
elemType seqList<elemType>::visit(int i) const
{
	return data[i];
}

template <class elemType>
void seqList<elemType>::traverse() const
{
	for (int i = 0; i < currentLength; ++i)
		cout << data[i] << ' ';
	cout << endl;
}

template <class elemType>
seqList<elemType>::~seqList(){}

int main()
{
	string type;
	int n1, n2;
	cin >> type >> n1 >> n2;
	if (!strcmp(type.c_str(), "int"))
	{
		seqList<int> list_1, list_2;
		list_1.get_input(n1);
		list_2.get_input(n2);
		seqList<int> list_3 = list_1 + list_2;
		list_3.traverse();
	}
	else if (!strcmp(type.c_str(), "char"))
	{
		seqList<char> list_1, list_2;
		list_1.get_input(n1);
		list_2.get_input(n2);
		seqList<char> list_3 = list_1 + list_2;
		list_3.traverse();
	}
	else if (!strcmp(type.c_str(), "double"))
	{
		seqList<double> list_1, list_2;
		list_1.get_input(n1);
		list_2.get_input(n2);
		seqList<double> list_3 = list_1 + list_2;
		list_3.traverse();
	}

	return 0;
}
