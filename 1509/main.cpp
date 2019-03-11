#include <iostream>

using namespace std;

struct date
{
	int year;
	int month;
	int day;
};
//const date origin = {1900, 1, 1};
//const date origin = {2009, 12, 28};
const date origin = {1849, 12, 31};
int GetWeekday(const date &today);
inline bool isLeapYear(int year);
bool isLegal(const date &today);

int main(void)
{

	int a, b, c, y1, y2;
	cin >> a >> b >> c >> y1 >> y2;
	for (int i = y1; i <= y2; ++i)
	{
		date festival = {i, a, 1};
		int weekday_now = GetWeekday(festival);
		festival.day += (7 + c - weekday_now) % 7 + 7 * (b - 1);
		if (isLegal(festival))
			cout << festival.year << '/' << (festival.month < 10 ? "0" : "") << festival.month << '/' << (festival.day < 10 ? "0" : "") << festival.day;
		else
			cout << "none";
		if (i < y2)
			cout << endl;
	}
}

int GetWeekday(const date &today)
{
	int sum = 0;
	for (int i = origin.year; i < today.year; ++i)
		sum += isLeapYear(i) ? 366 : 365;
	for (int i = 1; i < today.month; ++i)
	{
		switch (i)
		{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				sum += 31; break;
			case 4: case 6: case 9: case 11:
				sum += 30; break;
			case 2:
				sum += isLeapYear(today.year) ? 29 : 28; break;
			default:
				break;
		}
	}
	sum += today.day;
	--sum;
	return 1 + sum % 7;
}
inline bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool isLegal(const date &today)
{
	switch (today.month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		{
			if (today.day <= 31) return true;
			break;
		}
		case 4: case 6: case 9: case 11:
		{
			if (today.day <= 30) return true;
			break;
		}
		case 2:
		{
			if (isLeapYear(today.year))
			{
				if (today.day <= 29) return true;
			}
			else
			{
				if (today.day <= 28) return true;
			}
			break;
		}
		default:
			break;
	}
	return false;
}
