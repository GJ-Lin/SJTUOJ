#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex
{
	friend istream& operator>>(istream &is, MyComplex &c)
	{
		is >> c.x >> c.y;
		return is;
	}
	friend ostream& operator<<(ostream &os, const MyComplex &c)
	{
		os << setiosflags(ios::fixed) << setprecision(2) << c.x << " " << c.y;
	}
	private:
		double x, y;
	public:
		MyComplex(double a = 0.0, double b = 0.0): x(a), y(b){}
		MyComplex operator+(const MyComplex &c)
		{
			return MyComplex(x + c.x, y + c.y);
		}
		MyComplex operator-(const MyComplex &c)
		{
			return MyComplex(x - c.x, y - c.y);
		}
		MyComplex operator*(const MyComplex &c)
		{
			return MyComplex(x * c.x - y * c.y, x * c.y + y * c.x);
		}
		MyComplex operator/(const MyComplex &c)
		{
			return MyComplex((x * c.x + y * c.y) / (c.x * c.x + c.y * c.y), (y * c.x - x * c.y) / (c.x * c.x + c.y * c.y));
		}
		MyComplex& operator+=(const MyComplex &c)
		{
			x += c.x;
			y += c.y;
			return *this;
		}
		MyComplex& operator-=(const MyComplex &c)
		{
			x -= c.x;
			y -= c.y;
			return *this;
		}
		MyComplex& operator*=(const MyComplex &c)
		{
			double tem_x = x * c.x - y * c.y, tem_y = x * c.y + y * c.x;
			x = tem_x;
			y = tem_y;
			return *this;
		}
		MyComplex& operator/=(const MyComplex &c)
		{
			double tem_x = (x * c.x + y * c.y) / (c.x * c.x + c.y * c.y), tem_y = (y * c.x - x * c.y) / (c.x * c.x + c.y * c.y);
			x = tem_x;
			y = tem_y;
			return *this;
		}
		~MyComplex(){}
};

int main()
{
	MyComplex z1;
	MyComplex z2;

	cin >> z1 >> z2;

	cout << z1 + z2 << endl;
	cout << z1 - z2 << endl;
	cout << z1 * z2 << endl;
	cout << z1 / z2 << endl;
	cout << (z1 += z2) << endl;
	cout << (z1 -= z2) << endl;
	cout << (z1 *= z2) << endl;
	cout << (z1 /= z2) << endl;

	return 0;
}
