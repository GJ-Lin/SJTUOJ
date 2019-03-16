#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int w, h, last, max, min;
    cin >> w >> h;
    last = (w > h ? w : h);
    bool flag = true;
    for (int i = 1; i < n; ++i)
    {
    	cin >> w >> h;
    	max = (w > h ? w : h);
    	min = (w < h ? w : h);
    	if (max <= last)
    		last = max;
    	else if (min <= last)
    		last = min;
    	else
    	{
    		flag = false;
    		break;
    	}
    }
    if (flag)
    	cout << "YES";
    else
    	cout << "NO";
    return 0;
}
