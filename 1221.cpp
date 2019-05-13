#pragma warning (disable:4996)
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Node
{
    int data, size;
    Node* left, * right;
    Node(int _data_, int _size_ = 1, Node* _left_ = NULL, Node* _right_ = NULL) : data(_data_), size(_size_), left(_left_), right(_right_) {}
};

class binarySearchTree
{
public:
    binarySearchTree() :root(NULL) {}
    void insert(int x) { Insert(root, x); }
    void Insert(Node*& t, int x)
    {
        if (t == NULL)
        {
            t = new Node(x);
            return;
        }
        if (x < t->data) Insert(t->left, x);
        else Insert(t->right, x);
    }
    void clear(Node*& t)
    {
        if (t == NULL) return;
        if (t->left != NULL) clear(t->left);
        if (t->right != NULL) clear(t->right);
        delete t;
    }
    bool find(int x)
    {
        if (Find(root, x))
        {
            sort(root, x);
            return true;
        }
        else return false;
    }
    void del(int x)
    {
        if (find(x))
        {
            Delete(root);
        }
    }
    void Delete(Node*& t)
    {
        if (t->left == NULL)
        {
            Node* tmp = t;
            t = t->right;
            delete tmp;
        }
        else if (t->right == NULL)
        {
            Node* tmp = t;
            t = t->left;
            delete tmp;
        }
        else
        {
            Node* p = t->right, * q = NULL;
            while (p->left != NULL)
            {
                q = p;
                p = p->left;
            }
            if (q == NULL)
            {
                t->data = p->data;
                t->right = p->right;
                delete p;
            }
            else
            {
                t->data = p->data;
                q->left = p->right;
                delete p;
            }
        }
    }
    void delete_less_than(int x)
    {
        Delete_less_than(root, x);
    }
    void Delete_less_than(Node*& t, int x)
    {
        if (t == NULL) return;
        if (t->data < x)
        {
            clear(t->left);
            Delete_less_than(t->right, x);
            Node* tmp = t;
            t = t->right;
            delete tmp;
        }
        else Delete_less_than(t->left, x);
    }
    void delete_greater_than(int x)
    {
        Delete_greater_than(root, x);
    }
    void Delete_greater_than(Node*& t, int x)
    {
        if (t == NULL) return;
        if (t->data > x)
        {
            clear(t->right);
            Delete_greater_than(t->left, x);
            Node* tmp = t;
            t = t->left;
            delete tmp;
        }
        else Delete_greater_than(t->right, x);
    }
    void delete_interval(int a, int b)
    {
        Delete_interval(root, a, b);
    }
    void Delete_interval(Node*& t, int a, int b)
    {
        while (t != NULL && t->data > a && t->data < b) Delete(t);
        if (t != NULL && t->left != NULL) Delete_interval(t->left, a, b);
        if (t != NULL && t->right != NULL) Delete_interval(t->right, a, b);
    }
    bool find_ith(int num)
    {
        update(root);
        return Find_ith(root, num);
    }
    bool Find_ith(const Node* t, int num)
    {
        if (num > t->size) return false;
        int Left = (t->left != NULL) ? (t->left->size) : 0;
        if (num <= Left) return Find_ith(t->left, num);
        if (num == Left + 1)
        {
            printf("%d\n", t->data);
            return true;
        }
        return Find_ith(t->right, num - Left - 1);
    }bool Find(const Node* t, int x)
    {
        if (t == NULL) return false;
        if (x == t->data) return true;
        else if (x < t->data) return Find(t->left, x);
        else return Find(t->right, x);
    }
    void sort(Node*& t, int x)
    {
        if (t->data == x) return;
        Node * tmp;
        if (t->data > x)
        {
            sort(t->left, x);
            tmp = t->left;
            t->left = tmp->right;
            tmp->right = t;
            t = tmp;
        }
        else
        {
            sort(t->right, x);
            tmp = t->right;
            t->right = tmp->left;
            tmp->left = t;
            t = tmp;
        }
    }
    void preOrder(Node* t)
    {
        if (t == NULL) return;
        printf("%d ", t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
    void midOrder(Node * t)
    {
        if (t == NULL) return;
        midOrder(t->left);
        printf("%d ", t->data);
        midOrder(t->right);
    }
    void update(Node*& t)
    {
        if (t == NULL) return;
        t->size = 1;
        if (t->left != NULL)
        {
            update(t->left);
            t->size += t->left->size;
        }
        if (t->right != NULL)
        {
            update(t->right);
            t->size += t->right->size;
        }
    }
private:
    Node* root;
};

binarySearchTree bst;

int main()
{
    int n;
    cin >> n;
    char order[20];
    int x, y;

    while (n--)
    {
        scanf("%s", order);
        if (strcmp(order, "insert") == 0)
        {
            scanf("%d", &x);
            bst.insert(x);
        }
        else if (strcmp(order, "delete") == 0)
        {
            scanf("%d", &x);
            bst.del(x);
        }
        else if (strcmp(order, "delete_less_than") == 0)
        {
            scanf("%d", &x);
            bst.delete_less_than(x);
        }
        else if (strcmp(order, "delete_greater_than") == 0)
        {
            scanf("%d", &x);
            bst.delete_greater_than(x);
        }
        else if (strcmp(order, "delete_interval") == 0)
        {
            scanf("%d %d", &x, &y);
            bst.delete_interval(x, y);
        }
        else if (strcmp(order, "find") == 0)
        {
            scanf("%d", &x);
            if (bst.find(x)) printf("Y\n");
            else printf("N\n");
        }
        else if (strcmp(order, "find_ith") == 0)
        {
            scanf("%d", &x);
            if (!bst.find_ith(x)) printf("N\n");
        }
    }
}