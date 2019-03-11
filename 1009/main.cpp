#include <iostream>
#include <iomanip>
using namespace std;

struct Trade
{
	int time;
	int num;
	int way;
	int price;
};
int main(void)
{
	Trade arr[50];
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> arr[i].time >> arr[i].num >> arr[i].way;
	}
	int n;
	cin >> n;
	int price_former = 0, price_last = 0, time_former = 0, time_last = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> time_last >> price_last;
		for (int j = 0; j < m; ++j)
		{
			if (arr[j].time >= time_former && arr[j].time < time_last)
				arr[j].price = price_former;
			else if (j == m - 1 && arr[j].time >= time_last)
				arr[j].price = price_last;
		}
		time_former = time_last;
		price_former = price_last;
	}
	double sum = 0.0;
	int trsc = 0;
	double cmss = 0.0;
	for (int i = 0; i < m; ++i)
	{
		if (arr[i].way == 1)
		{
			trsc = arr[i].num * arr[i].price * 100;
			sum -= (double)trsc;
			cmss = (double)trsc * 0.002;
			if (cmss < 5)
				cmss = 5;
			sum -= cmss;
			sum -= (double)arr[i].num / 10;
			sum -= 1.0;
		}
		else
		{
			trsc = arr[i].num * arr[i].price * 100;
			sum += (double)trsc;
			cmss = (double)trsc * 0.002;
			if (cmss < 5)
				cmss = 5;
			sum -= cmss;
			sum -= (double)arr[i].num / 10;
			sum -= 1.0;
			sum -= (double)trsc * 0.001;
		}
	}
	/*sum *= 100.0;
	if (sum >= 0.0)
		sum += 0.5;
	else
		sum -= 0.5;
	sum = (int)sum;
	sum /= 100;*/
	cout << setiosflags(ios::fixed) << setprecision(2) << sum;
	return 0;
}
