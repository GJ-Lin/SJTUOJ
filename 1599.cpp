#include <iostream>
#include <cstdio>
using namespace std;

class seqStack
{
public:
    seqStack(int initSize = 100005)
    {
        elem = new char[initSize];
        Balance = new bool[initSize];
        maxSize = initSize;
        top_p = -1;
    }
    ~seqStack() { delete[] elem; }
    bool isEmpty() const { return top_p == -1; }
    void push(const char &x, const bool &state = true)
    {
        if (top_p == maxSize - 1) doubleSpace();
        elem[++top_p] = x;
        Balance[top_p] = state;
    }
    char pop() { return elem[top_p--]; }
    char top() const { return elem[top_p]; }
    void traverse() const
    {
        for (int i = 0; i <= top_p; ++i)
            printf("%c ", elem[i]);
        printf("isBalance: %d", Balance[top_p]);
    }
    bool isBalance() const { return Balance[top_p]; }
private:
    char *elem;
    bool *Balance;
    int top_p;
    int maxSize;
    void doubleSpace()
    {
        char *tmp = elem;
        elem = new char[2 * maxSize];
        for (int i = 0; i < maxSize; ++i) elem[i] = tmp[i];
        maxSize *= 2;
        delete[] tmp;
    }
};

int main()
{
    seqStack st1, st2;
    int n;
    int order;
    char x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &order);
        switch (order)
        {
        case 1:
            scanf(" %c", &x);
            if (st2.isEmpty() || x == '(' || x == '[' || x == '{')
            {
                st2.push(x);
                st1.push(x, false);
            }
            else
            {
                switch (x)
                {
                case ')':
                    if (st2.top() == '(')
                    {
                        st2.pop();
                        st1.push(x, true);
                    }
                    else
                    {
                        st2.push(x);
                        st1.push(x, false);
                    }
                    break;
                case ']':
                    if (st2.top() == '[')
                    {
                        st2.pop();
                        st1.push(x, true);
                    }
                    else
                    {
                        st2.push(x);
                        st1.push(x, false);
                    }
                    break;
                case '}':
                    if (st2.top() == '{')
                    {
                        st2.pop();
                        st1.push(x, true);
                    }
                    else
                    {
                        st2.push(x);
                        st1.push(x, false);
                    }
                    break;
                default:
                    {
                        st2.push(x);
                        st1.push(x, false);
                    }
                    break;
                }
                break;
            }
            break;
        case 2:
            if (!st1.isEmpty())
            {
                bool tbalance = st1.isBalance();
                char tmp = st1.pop();
                if (tbalance)
                {
                    switch (tmp)
                    {
                    case ')':
                        st2.push('(');
                        break;
                    case ']':
                        st2.push('[');
                        break;
                    case '}':
                        st2.push('{');
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    st2.pop();
                }
            }
            break;
        case 3:
            if (!st1.isEmpty()) printf("%c\n", st1.top());
            break;
        case 4:
            if (st2.isEmpty()) printf("YES\n");
            else printf("NO\n");
        default:
            break;
        }
        /*
        cout << "st1: ";
        st1.traverse();
        cout << endl;
        cout << "st2: ";
        st2.traverse();
        cout << endl;
        */
    }
    return 0;
}