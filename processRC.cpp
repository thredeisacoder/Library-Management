#include <iostream>
#include <string.h>
#include "mylib.h"

using namespace std;

string EnterName()
{
	string Name="";
	char c;
	while(true)
	{
		char c=getch();
		if(c==13) break;
		if(c==8)
		{
			if(Name.empty()) continue;
			Name.pop_back();
			putchar('\b');
			putchar(' ');
			putchar('\b');
			continue;
		}
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||c==' ')
		{
			if(Name=="")
			{
				if(c>='a'&&c<='z')
				{
					putchar('\b');
					putchar(' ');
					putchar('\b');
					c=toupper(c);
					putchar(c);
				}
				else if(c==' ') continue;
				else
				{
					putchar(c);
				}
			}
			else if(Name[Name.length()-1]==' ')
			{
				if(c>='a'&&c<='z')
				{
					c=toupper(c);
					putchar(c);
				}
				else if(c==' ') continue;
				else
				{
					putchar(c);
				}
			}
			else
			{
				if(c>='A'&&c<='Z')
				{
					putchar('\b');
					putchar(' ');
					putchar('\b');
					c=tolower(c);
					putchar(c);
				}
				else
				{
					putchar(c);
				}
			}
			Name+=c;
		}
		else
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	return Name;
}

int EnterCardStatus()
{
	char c;
	while(true)
	{
		c=getch();
		if(c=='0'||c=='1')
		{
			putchar(c);
			return c-'0';
		}
		else
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
}

string EnterSex()
{
	char c;
	while(true)
	{
		c=getch();
		if(c=='1'||c=='2')
		{
			putchar(c);
			if(c=='1') return "Nam";
			else return "Nu";
		}
		else
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
}


