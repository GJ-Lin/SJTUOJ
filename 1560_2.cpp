#include <iostream>
#include <cstdio>
#include <queue>
const int maxn = 100005;
char arr[maxn];
int n;
using namespace std;

struct Node
{
    int data;
    Node* lson, * rson;
};

void insert(Node*& t, int data)
{
    if (t == NULL)
    {
        t = new Node;
        t->lson = t->rson = NULL;
        t->data = data;
    }
    else if (t->data == data) return;
    else if (t->data > data) insert(t->lson, data);
    else insert(t->rson, data);
}

void find(Node * h, int data)
{
    int cnt = 1;
    arr[0] = '*';
    while (h != NULL)
    {
        if (h->data == data) break;
        else if (h->data < data)
        {
            arr[cnt++] = 'r';
            h = h->rson;
        }
        else
        {
            arr[cnt++] = 'l';
            h = h->lson;
        }
    }
    if (h == NULL) printf("Nothing.\n");
    else
    {
        for (int i = 0; i < cnt; ++i)
            printf("%c", arr[i]);
        putchar('\n');
    }
}

void remove(Node*& t, int data)
{
    if (t == NULL) return;
    else if (t->data == data)
    {
        Node* tmp;
        if (t->rson == NULL)
        {
            tmp = t;
            t = t->lson;
            delete tmp;
        }
        else if (t->rson->lson == NULL)
        {
            tmp = t->rson;
            t->data = t->rson->data;
            t->rson = t->rson->rson;
            delete tmp;
        }
        else
        {
            tmp = t->rson;
            while (tmp->lson->lson != NULL) tmp = tmp->lson;
            t->data = tmp->lson->data;
            Node * del = tmp->lson;
            tmp->lson = tmp->lson->rson;
            delete del;
        }
    }
    else if (t->data > data) remove(t->lson, data);
    else remove(t->rson, data);
}

int main()
{
    cin >> n;
    int x;
    char order;
    Node* t = NULL;
    while (n--)
    {
        getchar();
        scanf("%c %d", &order, &x);
        switch (order)
        {
        case '+':
            insert(t, x);
            break;
        case '-':
            remove(t, x);
            break;
        case '*':
            find(t, x);
            break;
        default:
            break;
        }
    }
}