#include <iostream>
using namespace std;

int main(void)
{
	int M, T, U, F, D;
	cin >> M >> T >> U >> F >> D;
	char road[T];
	for(int i = 0; i < T; ++i)
		cin >> road[i];

	int sum = 0, far = 0;
	while(sum <= M && far < T)
	{
		if (road[far] == 'f')
			sum += 2 * F;
		else
			sum += U + D;
		++far;
	}
	cout << far - 1;
	return 0;
}
