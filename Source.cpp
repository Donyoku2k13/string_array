#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace std;

string alpha = "aeiouAEIOU";
ofstream tt;
ifstream ft;

char gener(int s) {
	srand(time(NULL));
	int j = 0;
	string t;
	for (size_t i = 0; i < s; i++)
	{
		int j = rand() % 10 + 1;

		if (j > s - i)
		{
			j = s - i;
			i += j;
		}
		for (size_t k = 0; k < j; k++)
		{
			t += (char)(rand() % 122 + 42);
			
		}
		t += ' ';
	}
	t[t.size() - 1] = '.';

	cout << t << endl;
	tt.open("text.txt");
	tt << t;
	tt.close();
	return 0;
}



void search()
{
	int count = 0;
	 string str="",a;
	ft.open("text.txt");
	while (!ft.eof())
	{
		ft >> a; str += a;
	}
	
	ft.close();
	tt.open("text.txt");
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '*' || str[i] == '@' || str[i] == '+')
			{
				str.erase(i, 1); count++;
			}
			
		}
		tt << str;
		cout <<count<<"Count\n";
	tt.close();
}

bool isglas(char a)
{
	for (int i = 0; i < alpha.length(); i++)
	{
		if (a == alpha[i]) return true;
	}
	return false;
}
void glsearch()
{
	ft.open("text.txt");
	string str="", a, savedstr;
	long double len,kvgl;
	int countStr = 0;
	len=kvgl = 0;
	while (!ft.eof())
	{
		ft >> a; str += a;
	}
	ft.close();
	
	tt.open("stroki.txt");
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] <= 'z' && str[i] >= 'a') ||( str[i] <= 'Z' && str[i] >= 'A')) //there can be placed isAlpha()
		{
			if (isglas(str[i])) { kvgl++; }
			len++;
			savedstr += str[i];
			if (kvgl / len * 100 >= 30 && len >= 3) { tt << savedstr << '\n'; countStr++; }
		}
		else {
			kvgl = len= 0;
			savedstr = "";
		}
	}
	cout << countStr<<"	 countStr\n";
	tt.close();
}

int main() {
	
	gener(20000);
	cout << "-----------\n";
	search();
	glsearch();
	system("pause");
}
