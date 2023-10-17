#include "struct.h"
#include "mylib.h"
#include <fstream>

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


//loading file//

int loadFileReader(ReaderList& rl)
{
	fstream f;
	f.open("Reader.txt");
	if (!f.is_open()) return 0;
	string l="";
	while (!f.eof())
	{
		Reader* p = new Reader;

		getline(f, l);
		p->ID = l;
		getline(f, l);
		p->FirstName = l;
		getline(f, l);
		p->LastName = l;
		getline(f, l);
		p->Gender = l;
		getline(f, l);
		if (l == "") break;
		p->CardStatus;

		addNodeReader(rl, *p);
	}
	f.close();
	return 1;
}

void printReader(fstream &f, nodeRC* p)
{
	f << p->data.ID << endl;
	f << p->data.FirstName << endl;
	f << p->data.LastName << endl;
	f << p->data.Gender << endl;
	f << p->data.CardStatus << endl;
}

void loadlist(nodeRC* head, fstream &f)
{
	if (head == nullptr) return ;

	printReader(f, head);
	loadlist(head->left, f);
	loadlist(head->right, f);
}

int saveFileReader(ReaderList &rl)
{
	fstream f;
	f.open("Reader.txt", ios::out);
	if (!f.is_open()) return 0;

	loadlist(rl.head, f);
	f.close();
	return 1;
}

//_loading file TOC//
int loadFileTOC(TableOfContentList& tl)
{
	fstream f;
	f.open("TableOfContent.txt", ios::in);
	if (!f.is_open()) return 0;
	string l = "";
	while (!f.eof())
	{
		TableOfContent* p = new TableOfContent;
		getline(f, l);
		p->ISBN = l;
		getline(f, l);
		p->BookName = l;
		getline(f, l);
		if (l == "") break;
		p->Author = l;
		getline(f, l);
		if (l == "") break;
		p->Genre = l;
		getline(f, l);
		if (l == "") break;
		p->NumOfPage=l;
		getline(f, l);
		p->PublicYear = l;
		themTheoThuTuTheLoai(tl, *p);
	}
	f.close();
	return 1;
}

int saveTOC(TableOfContentList &tl)
{
	fstream f;
	f.open("TableOfContent.txt", ios::out);
	if (!f.is_open()) return 0;
	for (int i = 0; i < tl.size; i++)
	{
		f << tl.ds[i]->ISBN << endl;
		f << tl.ds[i]->BookName << endl;
		f << tl.ds[i]->Author << endl;
		f << tl.ds[i]->Genre<< endl;
		f << tl.ds[i]->NumOfPage << endl;
		f << tl.ds[i]->PublicYear << endl;
	}
	return 1;
}

void printlogo()
{
	fstream f;
	f.open("logo.txt",ios::in);
	if(!f.is_open()) cout<<"can not open file";
	string l="";
	while(!f.eof())
	{
		SetColor(20);
		getline(f,l);
		for (int i = 0; i < l.length(); i++)
		{
			if (l[i] == '@') cout << " ";
			else cout << '*';
		}
		cout << endl;
	}
	f.close();
}

