#include <iostream>
using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;
	bool dir = true;
	int mint = L, maxt = 0, pos, time;
	for (int i = 0; i < N; ++i, dir = !dir)
	{
		cin >> pos;
		if (dir)
			time = L - pos;
		else
			time = pos;

		if (time < mint)
			mint = time;
		if (time > maxt)
			maxt = time;
	}
	cout << mint << ' ' << maxt;
	return 0;
}
