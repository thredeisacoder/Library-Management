#include "TableOfContent.cpp"
#include <conio.h>
#include <string.h>
using namespace std;

string enterISBN()
{
	string ISBN="";
	char c;
	while(true)
	{
		c=getch();
		if(c==13)
		{
			break;
		}
		else if(c==8)
		{
			if(ISBN=="") continue;
			putchar('\b');
			putchar(' ');
			putchar('\b');
			ISBN.pop_back();
		}
		else
		{
			if(c>='a'&&c<='z')
			{
				c=toupper(c);
				putchar(c);
			}
			else if((c>='A'&&c<='Z')||c>='0'&&c<='9')
			{
				putchar(c);
			}
			else
			{
				continue;
			}
			ISBN+=c;
		}
	}
	return ISBN;
}


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
