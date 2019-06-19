//File Name:p03_0712209.cpp
//Author:¾G¤Èºa
//Email Address:brucecheng.2000@gmail.com
//Assignment Number:03
//Description:Program that converts numbers
//Last Change:3/30
#include <iostream>
using namespace std;

void to2(int n);

void to4(int n);

void to8(int n);

void to16(int n);

void index16(int n);

void zeros(double, int);

void to2in4(double, int&);

int main()
{
	int n, m, in;
	double d;
	char ans;
	cout << "This program converts integers or real numbers.\n";

	do
	{
		cout << "Enter a number(1 to convert int, 2 for double):";
		cin >> n;
		if (n == 1)
		{
			cout << "Enter another number(2 for binary, 4 for quaternary, 8 for octal, 16 for Hexadecimal):";
			cin >> m;
			if (m == 2)
			{
				cout << "Enter an integer to convert:";
				cin >> in;
				zeros(2, in);
				to2(in);
			}
			else if (m == 4)
			{
				cout << "Enter an integer to convert:";
				cin >> in;
				zeros(4, in);
				to4(in);
			}
			else if (m == 8)
			{
				cout << "Enter an integer to convert:";
				cin >> in;
				zeros(8, in);
				to8(in);
			}
			else if (m == 16)
			{
				cout << "Enter an integer to convert:";
				cin >> in;
				zeros(16, in);
				to16(in);
			}
			else
			{
				cout << "Wrong input.";
				ans = 'y';
			}
		}
		else if (n == 2)
		{
			int integer, count = 1;
			double point;
			cout << "Enter a float number:";
			cin >> d;
			integer = (int)floor(d);
			point = d - integer;

			zeros(2, integer);
			to2(integer);
			cout << '.';
			to2in4(point, count);
		}
		cout << "\n\nDo you wanna do it again?(y/n)";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	system ("pause");
	return 0;
}

void to2(int n)
{
	if (n < 2)
	{
		cout << n;
	}
	else
	{
		to2(n / 2);
		cout << n % 2;
	}
}

void to4(int n)
{
	if (n < 4)
	{
		cout << n;
	}
	else
	{
		to4(n / 4);
		cout << n % 4;
	}
}

void to8(int n)
{
	if (n < 8)
	{
		cout << n;
	}
	else
	{
		to8(n / 8);
		cout << n % 8;
	}
}

void index16(int n)
{
	if (n < 10)
		cout << n;
	else if (n = 10)
		cout << 'A';
	else if (n = 11)
		cout << 'B';
	else if (n = 12)
		cout << 'C';
	else if (n = 13)
		cout << 'D';
	else if (n = 14)
		cout << 'E';
	else if (n = 15)
		cout << 'F';
}

void to16(int n)
{
	if (n < 16)
		index16(n);
	else
	{
		to16(n / 16);
		index16(n%16);
	}
}

void zeros(double type, int num)
{
	int count = 0;
	for (int i = 0; i < 16; i++)
	{
		if ((num / type) >= 1)
			{
				num = (int) num / type;
				count++;
			}
		else
			break;
	}
	for (int i = 0; i < 16 - count - 1; i++)
		cout << '0';
}

void to2in4(double d, int& count)
{
	if (count > 4)
		return;
	count++;
	if (d * 2 > 1)
	{
		cout << '1';
		double x = d * 2 - 1;
		to2in4(x, count);
	}
	else if (d * 2 < 1)
	{
		cout << '0';
		to2in4(d * 2, count);
	}
	else
	{
		cout << '1';
		for (int i = 0; i < 5 - count; i++)
			cout << '0';
	}
}