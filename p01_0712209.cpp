//File Name:P01_0712209.cpp
//Author:¾G¤Èºa
//Email Address:brucecheng.2000@gmail.com
//Assignment Number:01
//Description:Program to output a name with the given form.
//Last Change:3/3
#include <iostream>
#include <string>
using namespace std;

const int I = 20;

void newline();

int main()
{
	string a;
	char d[I][I], ans;
	int i, len[I];
	int i2, j2, k2;

	do
	{
		cout << "Enter a name here to turn it into formal type:";
		getline(cin, a);
		i2 = 0;
		k2 = 0;
		
		for (j2 = 0; j2 < a.length(); j2++)
		{
			if (a[j2] == '.')
				continue;
			else if (a[j2] != ' ')
			{
				d[i2][k2] = a[j2];
				k2++;
			}
			else
			{
				len[i2] = k2;
				i2++;
				k2 = 0;
			}
		}
		len[i2] = k2;
		i2++;
		k2 = 0;

		if (i2 == 2)
		{
			for (i = 0; i < len[1]; i++)
				cout << d[1][i];
			cout << ", ";
			for (i = 0; i < len[0]; i++)
				cout << d[0][i];
		}
		else if (i2 == 3)
		{
			for (i = 0; i < len[2]; i++)
				cout << d[2][i];
			cout << ", ";
			for (i = 0; i < len[0]; i++)
				cout << d[0][i];
			cout << " ";
			for (i = 0; i < len[1]; i++)
				cout << d[1][i];
			cout << ".";
		}
		cout << "\n\nDo you want to do this again?(y for yes, n for no)";
		cin >> ans;
		newline();
	} while (ans == 'Y' || ans == 'y');
	
	system("pause");
	return 0;
}

void newline()
{
	char a;
	cin.get(a);
	while (a != '\n')
		cin.get(a);
}