//File Name:p02_0712209.cpp
//Author:¾G¤Èºa
//Email Address:brucecheng.2000@gmail.com
//Assignment Number:02
//Description:Program that imitates the system which can know who log in and out of system
//Last Change:3/15
#include <iostream>
#include <string>
using namespace std;

typedef string* strp;

void show(strp *, int , int *);
bool input(string str,char c)
{
	cout << str;
	char in;
	cin >> in;
	return c == in || c == in + 26;
}

int main() 
{
	int lablen, y, z;
	string x;

	cout << "Welcome NCTU computer system. This program imitates the system which can know who log in and out of system.\n";
	cout << "How many labs are there in NCTU?";
	cin >> lablen;
	strp *a = new strp[lablen];
	int *list = new int[lablen];
	char ans;

	
	cout << "Enter a list with " << lablen << " numbers, which means the amount of computers in each lab.";
	for (int i = 0; i < lablen; i++)
		cin >> list[i];

	for (int i = 0; i < lablen; i++)
		a[i] = new string[list[i]];

	for (int i = 0; i < lablen; i++)
		for (int j = 0; j < list[i]; j++)
			a[i][j] = "";

	show(a, lablen, list);

	do
	{
		system("cls");
		cout << "Who the hell are you?(s for system, u for user)";
		cin >> ans;
		//if(input("who the hell are you?(s for system, u for user)", 's') {}
		if (ans == 's' || ans == 'S')
		{
			do
			{
				cout << "\nWho logged in or logged out the computer station?(1 for log in, 2 for log out)";
				cin >> ans;
				cout << endl;
				if (ans == '1')
				{
					do
					{
						cout << "Enter the ID, lab number, and the computer station of the student that just logged in:";
						cin >> x >> y >> z;
						if (a[y - 1][z - 1] == "")
						{
							a[y - 1][z - 1] = x;
							cout << "\nAny other account logged in?(y/n)";
							cin >> ans;
						}
						else
						{
							cout << "Someone is using this computer station. Enter another one.\n";
							ans = 'y';
						}
					} while (ans == 'y' || ans == 'Y');
					show(a, lablen, list);

					cout << "\nGo back to log in or out?(y/n)";
					cin >> ans;
					system("cls");
				}
				else if (ans == '2')
				{
					do
					{
						cout << "Enter the ID, lab number, and the computer station of the student that just logged out:";
						cin >> x >> y >> z;
						if (a[y - 1][z - 1] == x)
						{
							a[y - 1][z - 1] = "";
							cout << "\nAny other account logged out?(y/n)";
							cin >> ans;
						}
						else
						{
							cout << "This ID isn't using this computer station. Enter another one.\n";
							ans = 'y';
						}
					} while (ans == 'y' || ans == 'Y');
					show(a, lablen, list);

					cout << "\nGo back to log in or out?(y/n)";
					cin >> ans;
					system("cls");
				}
				else
				{
					cout << "\nInvalid input.";
					ans = 'y';
				}
			} while (ans == 'y' || ans == 'Y');
		}
		else if (ans == 'u' || ans == 'U')
		{
			do
			{
				cout << "Search for the ID or the computer station?(1 for the former, 2 for the latter)";
				cin >> ans;
				if (ans == '1')
				{
					cout << "\nWhich ID do you wanna search?";
					cin >> x;
					y = -1;
					for (int i = 0; i < lablen; i++)
					{
						for (int j = 0; j < list[i]; j++)
						{
							if (a[i][j] == x)
							{
								y = i;
								z = j;
								break;
							}
						}
					}
					if (y < 0)
					{
						cout << "This ID isn't using any computer.\n";
					}
					else
					{
						cout << "This ID is using lab " << y + 1 << " station " << z + 1 << endl;
					}
					ans = 'n';
				}
				else if (ans == '2')
				{
					cout << "Enter the lab and station number you wanna search?";
					cin >> y >> z;
					if (a[y - 1][z - 1] == "")
						cout << "No one is using this computer.\n";
					else
						cout << "ID " << a[y - 1][z - 1] << " is using this computer.\n";
					ans = 'n';
				}
				else
				{
					cout << "Wrong ans. Type again.\n";
					ans = 'y';
				}
			} while (ans == 'y' || ans == 'Y');
		}
	}while (input("Go back to choose user or system?(y/n):", 'y'));
	
	cin.get();
	return 0;
}

void show(strp *a, int lablen, int *list)
{
	cout << "Lab number\tComputer station\n";
	for (int i = 0; i < lablen; i++)
	{
		cout << i + 1 << "\t\t";
		for (int j = 0; j < list[i]; j++)
		{
			if (a[i][j] == "")
				cout << j + 1 << ": empty   ";
			else
				cout << j + 1 << ": " << a[i][j] << " ";
		}
		cout << endl;
	}
}