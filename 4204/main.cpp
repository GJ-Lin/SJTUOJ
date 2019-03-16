#include <iostream>
using namespace std;

int main()
{
    long int n;
    cin >> n;
    long int v, a, b;
    for (long int i = 0; i < n; ++i)
    {
    	cin >> v >> a >> b;
    	if (a <= int(b / 2.0))
    	{
    		cout << v * a << endl;
    	}
    	else
    	{
    		cout << v / 2 * b + v % 2 * a << endl;
    	}
    }
    return 0;
}
