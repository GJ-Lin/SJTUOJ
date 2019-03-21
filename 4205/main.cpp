#include <iostream>
#include <cstring>
using namespace std;
char text[105][2005];
int lines = 1;
 
class sLinkList
{
public:
    sLinkList()
    {
        head = new node;
        currentLength = 0;
    }
 
    void clear()
    {
        node *p = head->next, *q;
        head->next = NULL;
        while (p != NULL)
        {
            q = p->next;
            delete p;
            p = q;
        }
        currentLength = 0;
    }
 
    void ins()
    {
        int year;
        string name;
        cin >> year;
        getline(cin, name);
        name.erase(name.begin());
        //cout << year << name << endl;
        node *pos = head, *tmp = new node(year, name, NULL);
        while (pos->next != NULL && compare(tmp, pos->next) > 0)
            pos = pos->next;
        pos->next = new node(year, name, pos->next);
        ++currentLength;
        delete tmp;
    }
 
    void del()
    {
        int i;
        cin >> i;
        --i;
        node *pos, *delp;
        pos = move(i - 1);
        delp = pos->next;
        pos->next = delp->next;
        delete delp;
        --currentLength;
    }
 
    void list() const
    {
        int i;
        cin >> i;
        --i;
        node *p = move(i);
        cout << p->year << ' ' << p->name << endl;
    }
 
    ~sLinkList()
    {
        clear();
        delete head;
    }
 
private:
    struct node
    {
        int year;
        string name;
        node *next;
 
        node(const int &y, const string &m, node *n = NULL) : year(y), name(m), next(n) {}
        node() : next(NULL) {}
        ~node() {}
    };
 
    node *head;
    int currentLength;
    node *move(int i) const
    {
        node *p = head;
        while (i-- >= 0) p = p->next;
        return p;
    }
 
    int compare(node *a, node *b)
    {
        if (a->year < b->year)
            return -1;
        else if (a->year > b->year)
            return 1;
        else
        {
            if (strcmp(a->name.c_str(), b->name.c_str()) < 0)
                return -1;
            else if (strcmp(a->name.c_str(), b->name.c_str()) > 0)
                return 1;
            else return 0;
        }
    }
};
 
int main()
{
    int N;
    cin >> N;
    char order[10];
    sLinkList winner;
    for (int i = 0; i < N; ++i)
    {
        cin >> order;
        switch (order[0])
        {
        case 'i': winner.ins(); break;
        case 'd': winner.del(); break;
        case 'l': winner.list(); break;
        }
    }
 
    return 0;
}