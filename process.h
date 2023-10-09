#pragma once
#include "struct.h"
#include "mylib.h"
using namespace std;
//Reader//
string EnterFirstName()
{
	string Name = "";
	while (true)
	{
		char c = _getch();
		if (c == 13)
		{
			if (Name == "")
			{
				continue;
			}
			else break;
		}
		else if (c == 8)
		{
			if (Name.empty()) continue;
			Name.pop_back();
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		else if (Name.length() == 10)
		{
			continue;
		}
		else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')
		{
			if (Name == "")
			{
				if (c >= 'a' && c <= 'z')
				{
					c = toupper(c);
					putchar(c);
				}
				else if (c == ' ') continue;
				else
				{
					putchar(c);
				}
			}
			else if (Name[Name.length() - 1] == ' ')
			{
				if (c >= 'a' && c <= 'z')
				{
					c = toupper(c);
					putchar(c);
				}
				else if (c == ' ') continue;
				else
				{
					putchar(c);
				}
			}
			else
			{
				if (c >= 'A' && c <= 'Z')
				{
					c = tolower(c);
					putchar(c);
				}
				else
				{
					putchar(c);
				}
			}
			Name += c;
		}
		else
		{
			continue;
		}
	}
	return Name;
}

int EnterCardStatus()
{
	char c;
	while (true)
	{
		c = _getch();
		if (c == '0' || c == '1')
		{
			putchar(c);
			return c - '0';
		}
		else
		{
			continue;
		}
	}
}

string EnterLastName()
{
	string s = "";
	char c;
	while (true)
	{
		c = _getch();
		if (c == 13)
		{
			break;
		}
		if (c == 8)
		{
			if (s == "") continue;
			putchar('\b');
			putchar(' ');
			putchar('\b');
			s.pop_back();
		}
		if ((c >= 'a' && c < 'z') || (c >= 'A' && c <= 'Z'))
		{
			if (s == "")
			{
				if (c >= 'a' && c <= 'z')
				{
					c = toupper(c);
					putchar(c);
				}
				else if (c == ' ')
				{
					continue;
				}
				else
				{
					putchar(c);
				}
			}
			else
			{
				if (c >= 'A' && c <= 'Z')
				{
					c = tolower(c);
					putchar(c);
				}
				else putchar(c);
			}
		}
		else continue;
		s += c;
	}
	return s;
}

string EnterGender()
{
	char c;
	while (true)
	{
		c = _getch();
		if (c == '1' || c == '2')
		{
			putchar(c);
			if (c == '1') return "MALE";
			else return "FEMALE";
		}
		else
		{
			continue;
		}
	}
}

string EnterID()
{
	string ID = "";
	char c;
	while (true)
	{
		c = _getch();
		if (c == 13)
		{
			break;
		}
		else if (c == 8)
		{
			if (ID == "") continue;
			putchar('\b');
			putchar(' ');
			putchar('\b');
			ID.pop_back();
		}
		else if (ID.length() == 6)
		{
			continue;
		}
		else
		{
			if (c >= 'a' && c <= 'z')
			{
				c = toupper(c);
				putchar(c);
			}
			else if ((c >= 'A' && c <= 'Z') || c >= '0' && c <= '9')
			{
				putchar(c);
			}
			else
			{
				continue;
			}
			ID += c;
		}
	}
	return ID;
}
//Table of content//
using namespace std;

string enterName()
{
	string Name = "";
	while (true)
	{
		char c = _getch();
		if (c == 13)
		{
			if (Name == "")
			{
				continue;
			}
			else break;
		}
		else if (c == 8)
		{
			if (Name.empty()) continue;
			Name.pop_back();
			putchar('\b');
			putchar(' ');
			putchar('\b');
			continue;
		}

		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')
		{
			if (Name == "")
			{
				if (c >= 'a' && c <= 'z')
				{
					c = toupper(c);
					putchar(c);
				}
				else if (c == ' ') continue;
				else
				{
					putchar(c);
				}
			}
			else if (Name[Name.length() - 1] == ' ')
			{
				if (c >= 'a' && c <= 'z')
				{
					c = toupper(c);
					putchar(c);
				}
				else if (c == ' ') continue;
				else
				{
					putchar(c);
				}
			}
			else
			{
				if (c >= 'A' && c <= 'Z')
				{
					c = tolower(c);
					putchar(c);
				}
				else
				{
					putchar(c);
				}
			}
			Name += c;
		}
		else
		{
			continue;
		}
	}
	if (Name[Name.length() - 1] == ' ') Name.pop_back();

	return Name;
}

string enterNumOfPage()
{
	char c;
	string n = "";
	while (true)
	{
		c = _getch();
		if (c == 13)
		{
			break;
		}
		else if (c == 8)
		{
			if (n == "") continue;
			putchar('\b');
			putchar(' ');
			putchar('\b');
			continue;
		}
		else if (c >= '0' && c <= '9')
		{
			if (n.length() == 4) continue;
			else putchar(c);
			n += c;
		}
		else
		{
			continue;
		}
	}
	return n;
}
