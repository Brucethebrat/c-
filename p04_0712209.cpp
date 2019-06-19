//File Name:p04_0712209.cpp
//Author:¾G¤Èºa
//Email Address:brucecheng.2000@gmail.com
//Assignment Number:04
//Description:Program that converts messages into readable ones
//Last Change:4/18
#include <iostream>
#include <string>
//#include <cstdlib>
//#include <stdlib.h>
using namespace std;



void seperatestr(string& a, string b, int);
//copy 5 char from b to a

void splitstring(string& str1, string& str2);
//take only 0 & 1 from str1 to str2

class zcode
{
public:
	zcode(int); 
	zcode(string a);
	zcode();
	void seperateint(int& a, string b, int);
	//copy 5 int from b to a
	string outcode();
	int outdecode();
private:
	string codes;
	int decode;
};

int main()
{
	char ans;
	cout << "This program converts integers or string bar code into zip code, or the upset way.\n";
	do
	{
		cout << "What kind of input are you going to type?\n"
			<< "A for string bar code\nB for int zcode\n"
			<< "--------------------\n";
		cin >> ans;

		if (ans == 'A')
		{
			string str;
			//char a[28];
			int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
			cout << "Input int with length 27:\n";
			cin >> str;
			/*for (int i = 0; i < 27; i++)
			{
				cin.get(a[26 - i]);
			}*/

			zcode a(str);

			/*seperateint(a1, a, 1);
			seperateint(a2, a, 6);
			seperateint(a3, a, 11);
			seperateint(a4, a, 16);
			seperateint(a5, a, 21);*/

			//zcode a1int(a1, -1), a2int(a2, -1), a3int(a3, -1), a4int(a4, -1), a5int(a5, -1);
			/*for (int i = 0; i < 5; i++)
				cout << a1int.outcode(i);
			cout << endl;
			for (int i = 0; i < 5; i++)
				cout << a2int.outcode(i);
			cout << endl;
			for (int i = 0; i < 5; i++)
				cout << a3int.outcode(i);
			cout << endl;
			for (int i = 0; i < 5; i++)
				cout << a4int.outcode(i);
			cout << endl;
			for (int i = 0; i < 5; i++)
				cout << a5int.outcode(i);
			cout << endl;*/
			cout << "\nZcode is: " << a.outdecode();
		}
		else if (ans == 'B')
		{
			int a, intarr[5];
			cout << "Input integer with length 5:";
			cin >> a;

			zcode a1(a);

			cout << "\nBar code is: " << a1.outcode();
		}
		else
		{
			cout << "Wrong input idiot!\n";
			system("pause>nul");
			exit(1);
		}
		cout << "\n\nDo you wanna do it again?(y/n)";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	system ("pause");
	return 0;
}

void zcode::seperateint(int& a, string b, int start)
{
	/*int upb = 100000, downb = 1;
	for (int i = 0; i < start; i++)
	{
		upb *= 10;
		downb *= 10;
	}
	a = (b % upb) / downb;
	cout << a << endl;*/
	int times = 1;
	for (int i = start + 4; i > start - 1; i--)
	{
		//string x(1, b[i]);
		
		//cout << b[i];
		if (b[i] == '1')
			a += times;
		times *= 10;
	}
	//cout << a << " ";
}

void seperatestr(string& a, string b, int start)
{
	for (int i = start; i < start + 5; i++)
		a += b[i];
}

void splitstring(string& str1, string& str2)
{
	//int count = 0;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == '1' || str1[i] == '0')
		{
			str2 += str1[i];
			//str2[count] = str1[i];//¿ùªº
			//count++;//¿ùªº
		}
	}
}

zcode::zcode(int b)
{
	if (b >= 100000) {
		cout << "Bigger than 99,999.";
		system("pause>nul");
		exit(1);
	}
	decode = b;
}

zcode::zcode(string a)
{
	int count1 = 0, count0 = 0;
	for (int i = 0; i < 5; i++)
	{
		if (a[i] == '1')
			count1++;
		else if (a[i] == '0')
			count0++;
		else
		{
			cout << "Wrong code format.";
			exit(1);
		}
	}
	codes = a;
}

zcode::zcode() :codes(0), decode('0')
{}

string zcode::outcode()
{
	int intarr[5];
	string temp = "1";
	for (int i = 0; i < 5; i++)
	{
		intarr[i] = decode % 10;
		decode /= 10;
	}

	for (int i = 0; i < 5; i++)
	{	
		if (intarr[4 - i] == 1)
			//codes = "00011";
			temp += "00011";
		else if (intarr[4 - i] == 2)
			//codes = "00101";
			temp += "00101";
		else if (intarr[4 - i] == 3)
			//codes = "00110";
			temp += "00110";
		else if (intarr[4 - i] == 4)
			//codes = "01001";
			temp += "01001";
		else if (intarr[4 - i] == 5)
			//codes = "01010";
			temp += "01010";
		else if (intarr[4 - i] == 6)
			//codes = "01100";
			temp += "01100";
		else if (intarr[4 - i] == 7)
			//codes = "10001";
			temp += "10001";
		else if (intarr[4 - i] == 8)
			//codes = "10010";
			temp += "10010";
		else if (intarr[4 - i] == 9)
			//codes = "10100";
			temp += "10100";
		else if (intarr[4 - i] == 0)
			//codes = "11000";
			temp += "11000";
		else
		{
			cout << "Wrong zip code input.";
			system("pause>nul");
		}
	}
	temp += '1';

	return temp;
}

int zcode::outdecode()
{
	int count, a[5], temp = 0, times = 1;
	for (int i = 4; i > -1; i--)
		a[i] = 0;

	seperateint(a[0], codes, 1);
	seperateint(a[1], codes, 6);
	seperateint(a[2], codes, 11);
	seperateint(a[3], codes, 16);
	seperateint(a[4], codes, 21);
	
	for (int i = 4; i > -1; i--)
	{
		count = 0;
		if ((a[i] / 10) % 10 == 1)
			count++;
		if ((a[i] / 100) % 10 == 1)
			count += 2;
		if ((a[i] / 1000) % 10 == 1)
			count += 4;
		if ((a[i] / 10000) % 10 == 1)
			count += 7; 
		if (count == 11)
			temp += 0;
		else
			temp += count * times;
		times *= 10;
	}
	return temp;
}

//100101010011100001001101001