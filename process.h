#include "struct.h"
#include "mylib.h"

using namespace std;

//Reader//

string EnterID(string s)
{
	cout << s;
	char c;
	while (true)
	{
		char c = _getch();
		if (c == 13)
		{
			if (s == "")
			{
				continue;
			}
			else break;
		}
		else if (c == 8)
		{
			if (s.empty()) continue;
			s.pop_back();
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		else if (s.length() == 10)
		{
			continue;
		}
		else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || (c >= '0' && c <= '9'))
		{
			if (s == "")
			{
				if (c >= 'a' && c <= 'z')
				{
					c = toupper(c);
					putchar(c);
				}
				else if (c == '_') continue;
				else
				{
					putchar(c);
				}
			}
			else if (s[s.length() - 1] == '_')
			{
				if (c >= 'a' && c <= 'z')
				{
					c = toupper(c);
					putchar(c);
				}
				else if (c == '_') continue;
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
			s += c;
		}
		else
		{
			continue;
		}
	}
	return s;

}

string EnterFirstName(string Name)// dung cho ca author, ten sach, the loai o dau sach
{
	cout << Name;
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
		else if (Name.length() == 35)
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

string EnterAuthor(string Name)
{
	cout << Name;
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
		else if (Name.length() == 32)
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

string EnterGenre(string s) {
	cout << s;
	while (true)
	{
		char c = _getch();
		if (c == 13)
		{
			if (s == "")
			{
				continue;
			}
			else break;
		}
		else if (c == 8)
		{
			if (s.empty()) continue;
			s.pop_back();
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		else if (s.length() == 15)
		{
			continue;
		}
		else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')
		{
			if (s == "")
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
			else if (s[s.length() - 1] == ' ')
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
			s += c;
		}
		else
		{
			continue;
		}
	}
	return s;
}

string EnterLastName(string  s)
{
	cout << s;
	char c;
	while (true)
	{
		c = _getch();
		if (c == 13)
		{
			if (s == "") continue;
			else break;
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

string EnterGender(string s)
{
	cout << s;
	char c;
	while (true)
	{
		c = _getch();
		if (c == '1' || c == '2')
		{
			if (c == '1')
			{
				cout << "MALE";
				return "MALE";
			}
			else
			{
				cout << "FEMALE";
				return "FEMALE";
			}
		}
		else
		{
			continue;
		}
	}
}

//Table of content//

string enterName(string Name)
{
	cout << Name;
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

string enterYear(string n)
{
	cout << n;
	char c;
	while (true)
	{
		c = _getch();
		if (c == 13)
		{
			if (n == "") continue;
			else break;
		}
		else if (c == 8)
		{
			if (n == "") continue;
			putchar('\b');
			putchar(' ');
			putchar('\b');
			n.pop_back();
		}
		else if (c >= '0' && c <= '9')
		{
			if (n.length() >= 4)  continue;
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

string enterNumPage(string n)
{
	cout << n;
	char c;
	while (true)
	{
		c = _getch();
		if (c == 13)
		{
			if (n == "") continue;
			else break;
		}
		else if (c == 8)
		{
			if (n == "") continue;
			putchar('\b');
			putchar(' ');
			putchar('\b');
			n.pop_back();
		}
		else if (c >= '0' && c <= '9')
		{
			if (n.length() >= 5)  continue;
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
