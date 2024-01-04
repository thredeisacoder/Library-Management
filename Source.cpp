#include "mylib.h"
#include "struct.h"
#include "process.h"
using namespace std;

void title(int x, int y)
{
	string s[19];
	string a[13];
	a[1] = " __       __   ______    ______         ___       ______   ____    ____ ";
	a[2] = "|  |     |  | |   _  |  |   _  |       /   |     |   _  |  |   |  /   / ";
	a[3] = "|  |     |  | |  |_)  | |  |_)  |     /  ^  |    |  |_)  |  |   |/   /  ";
	a[4] = "|  |     |  | |   _  <  |      /     /  /_|  |   |      /    |_    _/   ";
	a[5] = "|  `----.|  | |  |_)  | |  ||  |-.  /  _____  |  |  ||  |-.    |  |     ";
	a[6] = "|_______||__| |______/  | _| `.__| /__/     |__| | _| `.__|    |__|     ";
	a[7] = " 				                                                             _  ";
	a[8] = "				 _ __ ___   __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_";
	a[9] = "				| '_ ` _ | / _` | '_ | / _` |/ _` |/ _ | '_ ` _  |/ _ | '_ || __|";
	a[10] = "				| | | | | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_";
	a[11] = "				|_| |_| |_||__,_|_| |_||__,_||__, ||___|_| |_| |_||___|_| |_||__|";
	a[12] = "		    		                               |__/                              ";
	s[1] = "               __...--~~~~~-._     _.-~~~~~--...__               ";
	s[2] = "              //               `V'               ||              ";
	s[3] = "             //                 |                 ||             ";
	s[4] = "            //                  |                  ||            ";
	s[5] = "           //                   |                   ||           ";
	s[6] = "          //                    |                    ||          ";
	s[7] = "         //                     |                     ||         ";
	s[8] = "        //                      |                      ||        ";
	s[9] = "       //                       |                       ||       ";
	s[10] = "      //                        |                        ||      ";
	s[11] = "     //                         |                         ||     ";
	s[12] = "    //                          |                          ||    ";
	s[13] = "   // __......-----~~~~~~~~~-._ | _.-~~~~~~~~~-----......__ ||   ";
	s[14] = "  //__........-----~~~~~~~~~-._ | _.-~~~~~~~~~-----........__||  ";
	s[15] = " //__....... ..-------~~~~~~~._|||_.~~~~~~~-------..........__|| ";
	s[16] = "==============================|||||==============================";
	s[17] = "                               ---                               ";
	s[18] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	// draw logo
	for (int i = 1; i <= 12; i++)
	{
		SetColor(i);
		gotoxy(x, y + 1 + i);
		cout << a[i];
	}
	// draw book
	for (int i = 1; i <= 18; i++)
	{
		SetColor(i);
		gotoxy(x + 35, 19 + i);
		cout << s[i];
	}
}
// man hinh loading
void loading()
{
	Sleep(1000);

	string s = "          POSTS AND TELECOMMUNICATIONS INSTITUTE OF TECHNOLOGY! ";

	printlogo();
	for (unsigned int i = 0; i < s.length() - 1; i++)
	{
		SetColor(15);
		gotoxy(80 + i, 30);
		cout << s[i];
		Sleep(60);
	}

	for (int i = 0; i < 70; i++)
	{
		SetBGColor(15);
		gotoxy(80 + 3 / 2 * i, 31);
		cout << " ";
		gotoxy(80 + 3 / 2 * i, 32);
		cout << " ";
		SetBGColor(15);
		Sleep(60);
	}

	Sleep(1500);
	system("cls");
}
// Khung tieu de
void Tittle(int x, int y, int width, int height)
{
	for (int i = x; i <= x + width - 8; i++) // so cot
	{
		for (int j = y - 4; j <= y + height / 3; j++) // to tung o cua tung cot
		{
			SetBGColor(15); // mau nen trang
			gotoxy(i, j);
			cout << " "; // to mau trang cho khung tieu de
		}
	}
	SetColor(20); // chu mau xanh
	title(x + 30, y - 4);
}
// in lua chon
void Option(int x, int y, int width, int height, string option)
{
	for (int i = x - 6; i <= x + width; i++) // vong lap chay tu dau den het chieu dai option
	{
		SetBGColor(11);
		SetColor(16);
		gotoxy(i, y - 1);
		cout << " ";
		gotoxy(i, y);
		cout << " ";
		gotoxy(i, y + 1);
		cout << " ";
	}
	gotoxy(x, y);
	cout << option;
}
// tao menu
void boxMenu()
{
	int x = 8;
	int y = 13;
	int width = 150;
	int height = 30;
	if (width <= 1 || height <= 1)
		return;
	Tittle(x, y - 9, width, height);
	Option(x + 10, y + height / 5 + 2, width / 3 - 6, height, "READER CARD!");			 // the doc gia
	Option(x + 10, y + height / 5 + 4 + 2, width / 3 - 6, height, "TABLE OF CONTENT");	 // dau sach
	Option(x + 10, y + height / 5 + 8 + 2, width / 3 - 6, height, "BORROW AND RETURN!"); // muon tra sach
	Option(x + 10, y + height / 5 + 12 + 2, width / 3 - 6, height, "STATISTIC");		 // thong ke
	Option(x + 10, y + height / 5 + 16 + 2, width / 3 - 6, height, "QUIT!");			 // thoat

	gotoxy(x + width / 6 + 48, y + height * 5 / 6);
	cout << "Press Up and Down to move and Enter to choose!!! ";
}

void HighLight(int x, int y, int width) // bat thanh sang
{
	for (int i = x; i <= x + width; i++)
	{
		for (int j = y; j <= y + 2; j += 2)
		{
			SetBGColor(10);
			gotoxy(i, j);
			cout << " ";
			if (i == x || i == x + width - 1)
			{
				gotoxy(i, y + 1);
				cout << "  ";
			}
		}
	}
	SetBGColor(15);
	gotoxy(x, y);
}
void UnHighLight(int x, int y, int width) // tat thanh sang
{
	for (int i = x; i <= x + width; i++)
	{
		for (int j = y; j <= y + 2; j += 2)
		{
			SetBGColor(11);
			gotoxy(i, j);
			cout << " ";
			if (i == x || i == x + width - 1)
			{
				gotoxy(i, y + 1);
				cout << "  ";
			}
		}
	}
	SetBGColor(15);
	gotoxy(x, y);
}



void Tick(int x, int y) // danh dau
{
	SetBGColor(20);
	gotoxy(x,y);
	cout << "  ";
	gotoxy(x, y);
	SetBGColor(15);
}
void UnTick(int x, int y) // huy danh dau
{
	SetBGColor(15);
	gotoxy(x,y);
	cout << "  ";
	gotoxy(x, y);
}

int confirm(int x,int y)
{
	gotoxy(x,y);
	SetBGColor(9);
	for(int i=-1;i<=16;i++)
	{
		for(int j=-1;j<=6;j++)
		{
			if((i>-1&&i<16)&&(j>-1&&j<6)) continue;
			gotoxy(x+i,y+j);
			cout<<" ";
		}
	}
	SetBGColor(20);
	for(int i=0;i<=15;i++ )
	{
		for(int j=0;j<=5;j++)
		{
			gotoxy(x+i,y+j);
			cout<<" ";
		}		
	}
	SetColor(15);
	gotoxy(x+2,y+1);
	cout<<"ARE YOU SURE?";
	gotoxy(x+2,y+3); cout<<"YES";
	gotoxy(x+10,y+3); cout<<"NO";
	SetColor(0);
	SetBGColor(15);
	gotoxy(x+2,y+3); cout<<"YES";
	while(true)
	{
		char c=_getch();
		if(c==13)//enter
		{
			if(wherex()<=x+5) 
			{
				for(int i=-1;i<=16;i++ )
				{
					for(int j=-1;j<=6;j++)
					{
						gotoxy(x+i,y+j);
						cout<<" ";
					}		
				}
				return 1;
			}
			else
			{
				for(int i=-1;i<=16;i++ )
				{
					for(int j=-1;j<=6;j++)
					{
						gotoxy(x+i,y+j);
						cout<<" ";
					}		
				}
				return 0;
			}
		}
		else if(c==75||c==77)//left or right
		{
			if(wherex()<=x+5)
			{
				SetBGColor(20);
				gotoxy(x+2,y+3); cout<<"YES";
				SetBGColor(15);
				gotoxy(x+10,y+3);cout<<"NO";
			}
			else 
			{
				SetBGColor(20);
				gotoxy(x+10,y+3); cout<<"NO";
				SetBGColor(15);
				gotoxy(x+2,y+3);cout<<"YES";		
			}
			continue;
		}
		else continue;
	}
}

void clearReaderLine(int i)//xoa dong khi xoa
{
	gotoxy(6, i);
	cout << "   ";
	gotoxy(14, i);
	for (int j = 14; j < 30; j++)
		cout << " ";
	gotoxy(35, i);
	for (int j = 35; j < 65; j++)
		cout << " ";
	gotoxy(70, i);
	for (int j = 70; j < 85; j++)
		cout << " ";
	gotoxy(90, i);
	for (int j = 90; j < 100; j++)
		cout << " ";
	gotoxy(105, i);
	for (int j = 105; j < 120; j++)
		cout << " ";
}

void clearReaderTable()//xoa noi dung giu khung
{
	for (int i = 3; i < 3 + 2 * 20; i += 2)
	{
		clearReaderLine(i);
	}
}

// in 1 doc gia
void displayReader(nodeRC *p, int y) // in doc gia tren do cao y
{
	while (y >= 20)
	{
		y -= 20;
	}
	gotoxy(14, 3 + 2 * y);
	cout << p->data.ID;
	gotoxy(35, 3 + 2 * y);
	cout << p->data.FirstName;
	gotoxy(70, 3 + 2 * y);
	cout << p->data.LastName;
	gotoxy(90, 3 + 2 * y);
	cout << p->data.Gender;
	gotoxy(105, 3 + 2 * y);
	int s = p->data.CardStatus;
	if (s == 1)
		cout << "1 (activated)";
	else if (s == 0)
		cout << "0 (locked)";
}
void sortbyID(nodeRC *tmp[], int n)//sap xep theo ID
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tmp[i]->data.ID > tmp[j]->data.ID)
			{
				swap(tmp[i], tmp[j]);
			}
		}
	}
}
// nhap doc gia moi
string tableEnterRC(ReaderList &rl)
{
	ShowCur(true);
	Reader *p = new Reader;
	SetColor(16);
	int x = 10, y = 2, width = 120, height = 80;
	SetBGColor(10);
	gotoxy(x+width/4, y + height / 4);
	cout << "GENDER: 1 FOR MALE OR 2 FOR FEMALE !";
	gotoxy(x+width/4, y + height / 4 + 1);
	cout << "STATUS: 0(LOCKED) OR 1(UNLOCKED)";
	SetBGColor(10);
	for (int i = x + width / 6; i < x + width * 4/5-5; i++)
	{
		SetBGColor(14);
		gotoxy(i, y + 8);
		cout << " ";
		gotoxy(i, y + 10);
		cout << " ";
		gotoxy(i, y + 12);
		cout << " ";
	}
	for(int i=0;i<=2;i+=2)
	{
		gotoxy(30,11+i); cout<<" ";
		gotoxy(56,11+i); cout<<" ";
		gotoxy(70,11+i); cout<<" ";
		gotoxy(85,11+i); cout<<" ";
		gotoxy(100,11+i); cout<<" ";
	}
	SetBGColor(15);
	gotoxy(x + width / 6 + 8, y + 9);
	cout << "LAST NAME";
	gotoxy(x + width / 6 + 28, y + 9);
	cout << "FIRST NAME";
	gotoxy(x + width / 6 + 45, y + 9);
	cout << "GENDER";
	gotoxy(x + width / 6 + 60, y + 9);
	cout << "STATUS";

	gotoxy(x + width / 6 + 57, y + 11);
	cout << p->CardStatus<<"(activated)";
	gotoxy(x + width / 6 + 1, y + 11);
	p->FirstName = EnterFirstName(p->FirstName);
	if (p->FirstName == "")
	{
		delete p;
		return "";
	}
	gotoxy(x + width / 6 + 28, y + 11);
	p->LastName = EnterLastName(p->LastName);
	if (p->LastName == "")
	{
		delete p;
		return "";
	}
	gotoxy(x + width / 6 + 44, y + 11);
	p->Gender = EnterGender(p->Gender);
	if (p->Gender == "")
	{
		delete p;
		return "";
	}
	ShowCur(false);
	gotoxy(x, y + 15);
	string s= "";
	int n = addNodeReader(rl, *p);
	if (n == 1)
	{
		cout << "~ADD Successfully~";
		s=p->ID;
	}
	else cout << "Can not add";
	rl.head = updateTreeAvl(rl.head);
	delete p;
	Sleep(1000);
	return s;
}

void tableSettingRC(nodeRC *p, int y) // chinh sua thong tin doc gia
{
	ShowCur(true);
	SetColor(16);
	Reader *data = new Reader(p->data);
	gotoxy(6, wherey());
	SetColor(20);
	cout << "->>";
	SetColor(16);

	gotoxy(35, y);
	data->FirstName = EnterFirstName(p->data.FirstName);
	if (data->FirstName == "")
	{
		delete data;
		clearReaderLine(y);
		displayReader(p, (y - 3) / 2);
		ShowCur(false);
		return;
	}
	gotoxy(70, y);
	data->LastName = EnterLastName(p->data.LastName);
	if (data->LastName == "")
	{
		delete data;
		clearReaderLine(y);
		displayReader(p, (y - 3) / 2);
		ShowCur(false);
		return;
	}
	gotoxy(90, y);
	data->Gender = EnterGender(p->data.Gender);
	if (data->Gender == "")
	{
		delete data;
		clearReaderLine(y);
		displayReader(p, (y - 3) / 2);
		ShowCur(false);
		return;
	}
	gotoxy(105, y);
/*	data->CardStatus = EnterStatus(p->data.CardStatus);
	if (data->CardStatus == -1)
	{
		delete data;
		clearReaderLine(y);
		displayReader(p, (y - 3) / 2);
		return;
	}*/
	p->data = *data;

	clearReaderLine(y);
	displayReader(p, (y - 3) / 2);
	ShowCur(false);
	Sleep(1000);
}
// sap xep theo ten
void sortbyname(nodeRC *tmp[], int n)//sap xep theo ten (bubble sort)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (tmp[j]->data.LastName + tmp[j]->data.FirstName < tmp[minIndex]->data.LastName + tmp[minIndex]->data.FirstName)
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			std::swap(tmp[i], tmp[minIndex]);
		}
	}
}
// duyet danh sach doc gia
void displaytree(nodeRC *tmp[], int n, int count) // duyet mang de in ra
{
	gotoxy(2, 1);
	cout << "       ";
	int y = 0;
	for (int i = count - 20; i < count; i++)
	{
		if (i == n)
			break;
		displayReader(tmp[i], y);
		y++;
	}

	gotoxy(2, 1);
	cout << count / 20 << "/" << n / 20 + 1;
}

void resetpointerarray(nodeRC *tmp[], int n)
{
	for (int i = 0; i < n + 1; i++)
	{
		tmp[i] = nullptr;
	}
}

void tranvertree(nodeRC *head, nodeRC *tmp[], int &n) // duyet cay dua vao mang con tro tmp
{
	if (head == nullptr)
		return;
	else
	{
		tmp[n] = head;
		n++;
		tranvertree(head->left, tmp, n);
		tranvertree(head->right, tmp, n);
	}
}

// danh sach doc gia
void ReaderTable(nodeRC *tmp[], int n, int count)
{
	for (int i = 10; i <= 120; i++)
	{
		SetBGColor(6);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetColor(16);
		for (int j = 4; j < 3 + 2 * 20; j += 2)
		{
			gotoxy(i, j);
			cout << char(95);
		}
		gotoxy(i, 3 + 2 * 20);
		cout << " ";
	}
	for (int i = 1; i < 3 + 2 * 20; i++)
	{
		gotoxy(10, i);
		cout << " ";
		gotoxy(30, i);
		cout << " ";
		gotoxy(65, i);
		cout << " ";
		gotoxy(85, i);
		cout << " ";
		gotoxy(100, i);
		cout << " ";
		gotoxy(120, i);
		cout << " ";
	}
	SetBGColor(15);
	gotoxy(17, 1);
	cout << "ID";
	gotoxy(45, 1);
	cout << "LAST NAME";
	gotoxy(72, 1);
	cout << "FIRST NAME";
	gotoxy(90, 1);
	cout << "GENDER";
	gotoxy(108, 1);
	cout << "STATUS";
	if (n == 0)
	{
		gotoxy(130, 20);
		cout << "EMPTY";
	}
	gotoxy(125, 40);
	cout << "Press SPACE to sort by Name/ID";
	displaytree(tmp, n, count);
}

void displayDate(Date data)//In ngay thang
{
	cout << data.day << "/" << data.month << "/" << data.year;
}

void displayBAR(nodeBAR *head, int y, string name)//In danh sach muon tra
{
	gotoxy(10, y);
	cout << name;
	gotoxy(30, y);
	cout << head->data.bookID;
	gotoxy(40, y);
	displayDate(head->data.BorrowDate);
	gotoxy(55, y);
	displayDate(head->data.ReturnDate);
}

void watchingReaderMode(nodeRC *tmp[], int n)//hien bang reader va cac chuc nang
{
	int count = 20;
	bool sid = true;
	sortbyID(tmp, n);
	ReaderTable(tmp, n, count);
	gotoxy(130, 10);
	cout << "ESC: Cancel";
	while (true)
	{
		char c = _getch();
		if (c == 27) // esc
		{
			system("cls");
			return;
		}
		else if (c == 75) /// left
		{
			if (count == 20)
				continue;
			count -= 20;
			clearReaderTable();
			displaytree(tmp, n, count);
		}
		else if (c == 77) // right
		{
			if (count >= n)
				continue;
			count += 20;
			clearReaderTable();
			displaytree(tmp, n, count);
		}
		else if (c == 32)//space
		{
			clearReaderTable();
			if (sid == true)
			{
				sid = false;
				sortbyname(tmp, n);
				displaytree(tmp, n, count);
			}
			else
			{
				sid = true;
				sortbyID(tmp, n);
				displaytree(tmp, n, count);
			}
		}
		else if(c==9)//tab
		{
			gotoxy(130, 20);
			SetBGColor(10);
			cout << "ENTER NAME TO FIND : ";
			SetBGColor(15);
			string s = "";
			gotoxy(130, 21);
			ShowCur(true);
			s = EnterFirstName(s);
			ShowCur(false);
			if (s == "")
			{
				gotoxy(130, 20);
				cout << "                                ";
				continue;
			}
			else//Khi khong tim thay reader
			{
				nodeRC *t[MAX];
				int size = findReaderByName(tmp, t, n, s);
				if (size == 0)
				{
					gotoxy(130, 20);
					cout << "                                ";
					gotoxy(130, 21);
					cout << "Reader can not be found";
					Sleep(1500);
					gotoxy(130, 21);
					cout << "                        ";
					continue;
				}
				system("cls");
				watchingReaderMode(t, size);
				size = n;
				system("cls");
				return;
			}
			watchingReaderMode(tmp, n);
		}
		else
			continue;
	}
}

void deleteReaderMode(ReaderList &rl, nodeRC *tmp[], int &count) // che do xoa
{   
	char c;
	gotoxy(11, 3);
	Tick(wherex(), wherey());
	while (true)
	{
		c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		if (c == 27) // esc
		{
			UnTick(wherex(), wherey());
			break;
		}
		else if (c == 13) // enter
		{	
			UnTick(wherex(), wherey());
			int x=wherex(); int y=wherey();
			int pos = count - 20 + (wherey() - 3) / 2;
			if(tmp[pos]->data.dsmt.size!=0)
			{
				SetBGColor(7);
				SetColor(20);
				gotoxy(130,20);
				cout<<"BORROWING, CAN'T DELETE";
				Sleep(1500);
				SetBGColor(15);
				SetColor(0);
				gotoxy(130,20);
				cout<<"                        ";
				break;
			}
			else 
			{
				int a=confirm(130,20);
				if(a==0) 
				{
					Tick(x,y);
					continue;
				}
			}
			string s=tmp[pos]->data.ID;
			nodeRC *p = findprenode(rl.head, tmp[pos]);
			if (p == nullptr)
				rl.head = deletenode(tmp[pos]);
			else if (p->left == tmp[pos])
				p->left = deletenode(tmp[pos]);
			else
				p->right = deletenode(tmp[pos]);
			gotoxy(130, 30);
			cout << "DELETE SUCCESSFULLY!!!!";
			Sleep(2000);
			gotoxy(130,30);
			cout << "                           ";
			releaseID(rl.notusedid, MAX - rl.size, s);
			rl.size--;
			break;
		}
		else if (c == 80) // down
		{
			if (count > rl.size && wherey() == 3 + 2 * (rl.size - 1 - (count - 20)))
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3);
				Tick(wherex(), wherey());
			}
			else if (wherey() != 3 + 2 * 19)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() + 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 72) // up
		{
			if (count > rl.size && wherey() == 3)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3 + 2 * (rl.size - 1 - (count - 20)));
				Tick(wherex(), wherey());
			}
			else if (wherey() != 3)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() - 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3 + 2 * 19);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 75) /// left
		{
			int y = 0;
			if (count == 20)
				continue;
			UnTick(wherex(), wherey());
			count -= 20;
			clearReaderTable();
			displaytree(tmp, rl.size, count);
			gotoxy(11, 3);
			Tick(wherex(), wherey());
		}
		else if (c == 77) // right
		{
			int y = 0;
			if (count >= rl.size)
				continue;
			UnTick(wherex(), wherey());
			count += 20;
			clearReaderTable();
			displaytree(tmp, rl.size, count);
			gotoxy(11, 3);
			Tick(wherex(), wherey());
		}
		else
		{
			continue;
		}
	}
}

void SettingReaderMode(ReaderList &rl, nodeRC *tmp[], int &count) // che do chinh sua
{
	char c;
	gotoxy(11, 3);
	Tick(wherex(), wherey());
	while (true)
	{
		c = _getch();
		if (c == 13) // enter
		{
			UnTick(wherex(), wherey());
			int pos = count - 20 + (wherey() - 3) / 2;
			tableSettingRC(tmp[pos], wherey());
			break;
		}
		else if (c == 27) // esc
		{
			UnTick(wherex(), wherey());
			break;
		}
		else if (c == 80) // down
		{
			if (count > rl.size && wherey() == 3 + 2 * (rl.size - 1 - (count - 20)))
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3);
				Tick(wherex(), wherey());
			}
			else if (wherey() != 3 + 2 * 19)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() + 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 72) // up
		{
			if (count > rl.size && wherey() == 3)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3 + 2 * (rl.size - 1 - (count - 20)));
				Tick(wherex(), wherey());
			}
			else if (wherey() != 3)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() - 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3 + 2 * 19);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 75) /// left
		{
			int y = 0;
			if (count == 20)
				continue;
			UnTick(wherex(), wherey());
			count -= 20;
			clearReaderTable();
			displaytree(tmp, rl.size, count);
			gotoxy(11, 3);
			Tick(wherex(), wherey());
		}
		else if (c == 77) // right
		{
			int y = 0;
			if (count >= rl.size)
				continue;
			UnTick(wherex(), wherey());
			count += 20;
			clearReaderTable();
			displaytree(tmp, rl.size, count);
			gotoxy(11, 3);
			Tick(wherex(), wherey());
		}
		else
		{
			continue;
		}
	}
}

void controlReaderTable(ReaderList &rl, nodeRC *tmp[], int count)//cac nut chuc nang cho reader mode
{
	SetBGColor(11);
	SetColor(0);
	gotoxy(125, 40);
	cout << "Press SPACE to sort by Name/ID";
	for (int i = 130; i <= 139; i++)
	{
		gotoxy(i, 3);
		cout << " ";
		gotoxy(i, 4);
		cout << " ";
		gotoxy(i, 5);
		cout << " ";

		gotoxy(i, 7);
		cout << " ";
		gotoxy(i, 8);
		cout << " ";
		gotoxy(i, 9);
		cout << " ";

		gotoxy(i, 11);
		cout << " ";
		gotoxy(i, 12);
		cout << " ";
		gotoxy(i, 13);
		cout << " ";
	}
	gotoxy(133, 4);
	cout << "ADD";
	gotoxy(132, 8);
	cout << "DELETE";
	gotoxy(133, 12);
	cout << "EDIT";

	SetBGColor(15);
	HighLight(130, 3, 9);
	bool x = true;
	while (true)
	{
		// nhan phim tu nguoi dung(up/down/enter)
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		if (c == 27) // khi nguoi dung nhan esc
		{

			system("cls");
			break;
		}
		else if (c == 32) // space // sap xep theo id va theo ten
		{
			UnHighLight(wherex(), wherey(), 9);
			if (x == true)
			{
				x = false;
				sortbyname(tmp, rl.size);
				clearReaderTable();
				displaytree(tmp, rl.size, count);
			}
			else
			{
				x = true;
				sortbyID(tmp, rl.size);
				clearReaderTable();
				displaytree(tmp, rl.size, count);
			}
			HighLight(130, 3, 9); // quay lai highlight option 1
		}
		else if (c == 72) // khi nguoi dung nhan UP
		{
			if (wherey() == 3)
			{
				UnHighLight(wherex(), wherey(), 9);
				gotoxy(130, 11);
				HighLight(wherex(), wherey(), 9);
			}
			else
			{
				UnHighLight(wherex(), wherey(), 9);
				gotoxy(130, wherey() - 4);
				HighLight(wherex(), wherey(), 9);
			}
		}
		else if (c == 80) // khi nguoi dung nhan Down
		{
			if (wherey() == 11)
			{
				UnHighLight(wherex(), wherey(), 9);
				gotoxy(130, 3);
				HighLight(wherex(), wherey(), 9);
			}
			else
			{
				UnHighLight(wherex(), wherey(), 9);
				gotoxy(130, wherey() + 4);
				HighLight(wherex(), wherey(), 9);
			}
		}
		else if (c == 75) /// left
		{
			if (count == 20)
				continue;
			UnHighLight(wherex(), wherey(), 9);
			count -= 20;
			clearReaderTable();
			displaytree(tmp, rl.size, count);
			gotoxy(130, 3);
			HighLight(wherex(), wherey(), 9);
		}
		else if (c == 77) // right
		{
			if (count >= rl.size)
				continue;
			UnHighLight(wherex(), wherey(), 9);
			count += 20;
			clearReaderTable();
			displaytree(tmp, rl.size, count);
			gotoxy(130, 3);
			HighLight(wherex(), wherey(), 9);
		}
		else if (c == 13) // Khi nguoi dung nhan ENTER
		{
			SetBGColor(15);
			if (wherey() == 3)//add
			{
				system("cls");
				string s=tableEnterRC(rl);
				ShowCur(false);
				int n = 0;
				tranvertree(rl.head, tmp, n);
				sortbyID(tmp, rl.size);
				count=20;
				if(s!="")
				{
					while(count<=rl.size)
					{
						if(tmp[count-20]->data.ID<=s&&tmp[count]->data.ID>=s)
						{
							break;
						}
						count+=20;
					}
				}
				system("cls");
				ReaderTable(tmp, rl.size, count);
				controlReaderTable(rl, tmp, count);
				system("cls");
				break;
			}
			else if (wherey() == 7)//delete
			{
				gotoxy(122, 40);
				cout << "                                      ";
				if (rl.size == 0)
				{
					system("cls");
					gotoxy(125, 20);
					cout << "EMPTY!!!\n";
					system("pause");
					system("cls");
					ReaderTable(tmp, rl.size, count);
					controlReaderTable(rl, tmp, count);
					break;
				}
				gotoxy(132, 20);
				deleteReaderMode(rl, tmp, count);
				resetpointerarray(tmp, rl.size);
				int n = 0;
				tranvertree(rl.head, tmp, n);
				sortbyID(tmp, n);
				clearReaderTable();
				displaytree(tmp, rl.size, count);
				controlReaderTable(rl, tmp, count);
				system("cls");
				break;
			}
			else
			{
				gotoxy(122, 40);//edit
				cout << "                                  ";
				SettingReaderMode(rl, tmp, count);
				sortbyID(tmp, 0);
				clearReaderTable();
				displaytree(tmp, rl.size, count);
				controlReaderTable(rl, tmp, count);
				break;
			}
		}
		else if (c == 9) // tab (chuc nang an)
		{
			gotoxy(130, 20);
			SetBGColor(10);
			cout << "ENTER NAME TO FIND : ";
			SetBGColor(15);
			string s = "";
			gotoxy(130, 21);
			ShowCur(true);
			s = EnterFirstName(s);
			ShowCur(false);
			if (s == "")
			{
				gotoxy(130, 20);
				cout << "                                ";
				continue;
			}
			else
			{
				nodeRC *t[MAX];
				int size = findReaderByName(tmp, t, rl.size, s);
				if (size == 0)
				{
					gotoxy(130, 20);
					cout << "                                ";
					gotoxy(130, 21);
					cout << "Reader can not be found";
					Sleep(1500);
					gotoxy(130, 21);
					cout << "                        ";
					continue;
				}
				system("cls");
				watchingReaderMode(t, size);
				ReaderTable(tmp, size, count);
				controlReaderTable(rl, tmp, count);
				break;
			}
		}
		else
		{
			continue;
		}
	}
}

void clearTOCLine(int i)//Xoa dong
{
	gotoxy(2, i);
	for (int j = 0; j < 6; j++)
		cout << " ";
	gotoxy(10, i);
	for (int j = 0; j < 36; j++)
		cout << " ";
	gotoxy(48, i);
	for (int j = 0; j < 15; j++)
		cout << " ";
	gotoxy(65, i);
	for (int j = 0; j < 32; j++)
		cout << " ";
	gotoxy(99, i);
	for (int j = 0; j < 11; j++)
		cout << " ";
	gotoxy(112, i);
	for (int j = 0; j < 11; j++)
		cout << " ";
	gotoxy(125, i);
	for (int j = 0; j < 5; j++)
		cout << " ";
}

void clearTableTOC()
{
	for (int i = 3; i < 3 + 2 * 19; i += 2)
	{
		clearTOCLine(i);
	}
}

// danh sach dau sach
string tableEnterTOC(TableOfContentList &tl)
{
	TableOfContent *p = new TableOfContent;
	SetColor(16);
	int x = 10, y = 2, width = 120, height = 80;
	gotoxy(x, y + height / 4);
	cout << "Limit input characters of each category:\n "; // hdsd
	gotoxy(x, y + height / 4 + 1);
	cout << "Name - 34 chars"; // hdsd
	gotoxy(x, y + height / 4 + 2);
	cout << "Genre - 15 chars"; // hdsd
	gotoxy(x, y + height / 4 + 3);
	cout << "Author - 32 chars"; // hdsd
	gotoxy(x, y + height / 4 + 4);
	cout << "Number Page - maximum:5 numbers"; // hdsd
	gotoxy(x, y + height / 4 + 5);
	cout << "Public Year - maximum: 4 numbers- Can not be larger than current year"; // hdsd
	gotoxy(x, y + height / 4 + 6);
	cout << "ISBN - 6 chars"; // hdsd
	gotoxy(x, y + height / 4 + 7);
	cout << "The number of books - maximum 99"; // hdsd
	for (int i = x; i < x + width + 18; i++)
	{
		SetBGColor(14);
		gotoxy(i, y + 8);
		cout << " ";
		gotoxy(i, y + 10);
		cout << " ";
		gotoxy(i, y + 12);
		cout << " ";
		for(int j=0;j<=2;j+=2)
		{
			gotoxy(x,11+j);		cout<<" ";
			gotoxy(x+30,11+j);  cout<<" ";
			gotoxy(x+50,11+j);  cout<<" ";
			gotoxy(x+86,11+j);  cout<<" ";
			gotoxy(x+104,11+j); cout<<" ";
			gotoxy(x+122,11+j); cout<<" ";
			gotoxy(x+137,11+j); cout<<" ";
		}
	}
	
	for(int i=0;i<=40;i++)
	{
		gotoxy(x+width-65+i,y+14); cout<<" ";
		gotoxy(x+width-65+i,y+17); cout<<" ";
	}
	gotoxy(x+width-65,y+15); cout<<"  ";
	gotoxy(x+width-26,y+15); cout<<"  ";
	gotoxy(x+width-65,y+16); cout<<"  ";
	gotoxy(x+width-26,y+16); cout<<"  ";
	
	//hien thi muc luc tren bang
	SetBGColor(15);
	gotoxy(x + 10, y + 9);
	cout << "| NAME |";
	gotoxy(x + width - 83, y + 9);
	cout << "| GENRE | ";
	gotoxy(x + width - 57, y + 9);
	cout << "| AUTHOR | ";
	gotoxy(x + width - 32, y + 9);
	cout << "| NUMBER PAGE | ";
	gotoxy(x + width - 14, y + 9);
	cout << "| PUBLIC YEAR | ";
	gotoxy(x + width + 6, y + 9);
	cout << "| ISBN | ";
	gotoxy(x + width - 59, y + 15);
	cout << "| Enter the number of books | ";
	ShowCur(true);
	//Nhap dau sach
	gotoxy(x + 3, y + 11);
	p->BookName = EnterBookName(p->BookName);
	if (p->BookName == "")
	{
		return "";
	}
	gotoxy(x + width - 87, y + 11);
	p->Genre = EnterGenre(p->Genre);
	if (p->Genre == "")
	{
		return"";
	}
	gotoxy(x + width - 67, y + 11);
	p->Author = EnterAuthor(p->Author);
	if (p->Author == "")
	{
		return"";
	}
	gotoxy(x + width - 27, y + 11);
	p->NumOfPage = enterNumPage(p->NumOfPage);
	if (p->NumOfPage == "")
	{
		return"";
	}
	gotoxy(x + width - 10, y + 11);
	p->PublicYear = enterYear(p->PublicYear);
	if (p->PublicYear == "")
	{
		return"";
	}
	gotoxy(x + width + 6, y + 11);
	p->ISBN = EnterISBN(p->ISBN);
	if (p->ISBN == "")
	{
		return"";
	}
	gotoxy(x + width - 45, y + 16);
	p->dms.size = enterNumBooks(p->dms.size);
	if (p->dms.size == 0)
	{
		return"";
	}
	p->dms = createBookList(p);
	ShowCur(false);
	int n = themTheoThuTuTheLoai(tl, *p);
	if (n == 1)//thong bao sau khi nhap
	{
		gotoxy(x, 20);
		cout << "~ADD SUCCESSFULL!!!~";
	}
	else
	{
		gotoxy(x, 20);
		cout << "~ADD FAILURE!!!~";
	}
	gotoxy(x, y + 15);
	Sleep(1500);
	// delete p;
	return p->ISBN;
}
void displayTOC(TableOfContent data, int &yTOC)//Hien thi noi dung dau sach
{
	gotoxy(4, yTOC);
	cout << data.ISBN;
	gotoxy(11, yTOC);
	cout << data.BookName;
	gotoxy(49, yTOC);
	cout << data.Genre;
	gotoxy(66, yTOC);
	cout << data.Author;
	gotoxy(102, yTOC);
	cout << data.NumOfPage;
	gotoxy(116, yTOC);
	cout << data.PublicYear;
}

void displayBookList(TableOfContent data, int yTOC, int pos)//Hien thi danh muc sach
{
	nodeB *p = data.dms.head;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
	gotoxy(126, yTOC);
	cout << p->data.BookID;
	gotoxy(139, yTOC);
	cout << p->data.BookStatus;
	gotoxy(145,yTOC);
	cout<<p->data.BookLocation;
}

void loadListTOC(TableOfContentList tl, int count)//duyet va in dau sach
{
	int yTOC = 3; // chi?`u cao ha`ng d?`u ti?n
	for (int i = count - 19; i < count; i++)
	{
		if (i == tl.size)
		{
			break;
		}
		displayTOC(*tl.ds[i], yTOC);
		yTOC += 2;
	}
}

void loadListSearch(TableOfContentList tl, int& count, int &flag)//duyet va in ra danh sach khi tim
{
	int yTOC = 3; // chi?`u cao ha`ng d?`u ti?n
	for (int i = count - 19; i < count; i++)
	{
		if (i == tl.size)
		{
			break;
		}
		if (tl.ds[i] != tl.ds[i - 1])
		{
			flag = i;
		}
		displayTOC(*tl.ds[i], yTOC);
		displayBookList(*tl.ds[i], yTOC, i - flag);
		yTOC += 2;
	}
}

void clearfilterBySearching()//Xoa danh sach sau khi tra
{
	for (int i = 3; i < 3 + 2 * 19; i += 2)
	{
		gotoxy(2, i);
		for (int j = 0; j < 6; j++)
			cout << " ";
		gotoxy(10, i);
		for (int j = 0; j < 36; j++)
			cout << " ";
		gotoxy(48, i);
		for (int j = 0; j < 15; j++)
			cout << " ";
		gotoxy(65, i);
		for (int j = 0; j < 32; j++)
			cout << " ";
		gotoxy(99, i);
		for (int j = 0; j < 11; j++)
			cout << " ";
		gotoxy(112, i);
		for (int j = 0; j < 11; j++)
			cout << " ";
		gotoxy(125, i);
		for (int j = 0; j < 9; j++)
			cout << " ";
		gotoxy(135, i);
		for (int j = 0; j < 7; j++)
			cout << " ";
		gotoxy(144,i);
		for(int j=0;j<7;j++)
			cout<<" ";
	}
}

void filterBySearching(TableOfContentList &tl, int count, int &flag)//sap xep sau khi search
{
	for (int i = 0; i <= 152; i++) // chay theo chieu dai tu trai sang phai
	{
		SetBGColor(6);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetColor(0);
		for (int j = 4; j < 3 + 2 * 19; j += 2) //In ra tu tren xuong duoi
		{
			gotoxy(i, j);
			cout << char(95); // in ra dau sach ngan cach tung dong
		}
		gotoxy(i, 3 + 2 * 19);
		cout << " ";
	}
	for (int i = 1; i < 3 + 2 * 19; i++) // ve cot ngan cach tung dong
	{
		gotoxy(0, i);
		cout << " ";
		gotoxy(9, i);
		cout << " ";
		gotoxy(47, i);
		cout << " ";
		gotoxy(64, i);
		cout << " ";
		gotoxy(98, i);
		cout << " ";
		gotoxy(111, i);
		cout << " ";
		gotoxy(124, i);
		cout << " ";
		gotoxy(134, i);
		cout << " ";
		gotoxy(143, i);
		cout << " ";
		gotoxy(152,i);
		cout<<" ";
	}
	SetBGColor(15);
	if (tl.size == 0)
	{
		gotoxy(60, 25);
		cout << "Empty!!!";
	}
	//in ra cac muc sach
	gotoxy(3, 1);
	cout << "ISBN";
	gotoxy(26, 1);
	cout << "BOOK NAME";
	gotoxy(55, 1);
	cout << "Genre";
	gotoxy(77, 1);
	cout << "AUTHOR";
	gotoxy(103, 1);
	cout << "PAGE";
	gotoxy(116, 1);
	cout << "YEAR";
	gotoxy(126, 1);
	cout << "BOOK ID";
	gotoxy(136, 1);
	cout << "STATUS";
	gotoxy(145,1);
	cout<<"LOCATE";
	loadListSearch(tl, count, flag);
	SetColor(0);
}

void controlfilterBySearching(TableOfContentList &tl, int count, int &flag)//dieu khien nut xoa
{
	while (true)
	{
		// nhan phim tu nguoi dung(up/down/enter)
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		if (c == 27) // khi nguoi dung nhan esc
		{
			system("cls");
			SetBGColor(15);
			break;
		}
		else if (c == 75) /// left
		{
			if (count == 19)
			{
				continue;
			}
			count -= 19;
			clearfilterBySearching();
			loadListSearch(tl, count, flag);
		}
		else if (c == 77) // right
		{
			if (count > tl.size)
			{
				continue;
			}
			count += 19;
			clearfilterBySearching();
			loadListSearch(tl, count, flag);
		}
		else continue;
	}
}

void editTOC(TableOfContent* &tmp, int y)//sua dau sach
{
	SetColor(16);
	ShowCur(true);
	gotoxy(4, y);
	TableOfContent *p = new TableOfContent(*tmp);
	gotoxy(11, y);
	//sua dau sach
	p->BookName = EnterBookName(tmp->BookName);
	if (p->BookName == "")
	{
		gotoxy(1, y);
		UnTick(wherex(), wherey());
		clearTOCLine(y);

		displayTOC(*tmp, y);
		return;
	}
	gotoxy(49, y);
	p->Genre = EnterGenre(tmp->Genre);
	if (p->Genre == "")
	{
		gotoxy(1, y);
		UnTick(wherex(), wherey());
		clearTOCLine(y);

		displayTOC(*tmp, y);

		return;
	}
	gotoxy(66, y);
	p->Author = EnterAuthor(tmp->Author);
	if (p->Author == "")
	{
		gotoxy(1, y);
		UnTick(wherex(), wherey());
		clearTOCLine(y);

		displayTOC(*tmp, y);

		return;
	}
	gotoxy(102, y);
	p->NumOfPage = enterNumPage(tmp->NumOfPage);
	if (p->NumOfPage == "")
	{
		gotoxy(1, y);
		UnTick(wherex(), wherey());
		clearTOCLine(y);

		displayTOC(*tmp, y);

		return;
	}
	gotoxy(116, y);
	p->PublicYear = enterYear(tmp->PublicYear);
	if (p->PublicYear == "")
	{
		gotoxy(1, y);
		UnTick(wherex(), wherey());
		clearTOCLine(y);
		displayTOC(*tmp, y);
		return;
	}
	ShowCur(false);
	p->dms.head=tmp->dms.head;
	tmp->dms.head==nullptr;
	delete tmp;
	tmp = p;
	gotoxy(130, 25);
	cout << "~EDIT SUCCESSFULL!!!~";
	gotoxy(1, y);
	UnTick(wherex(), wherey());
	Sleep(1500);
	system("cls");
}

void TableTOC(TableOfContentList &tl, int count)//Bang dau sach
{
	for (int i = 0; i <= 124; i++) // cha?y theo chi?`u da`i, tra?i -> pha?i
	{
		SetBGColor(6);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetColor(0);
		for (int j = 4; j < 3 + 2 * 19; j += 2) // co? bao nhi?u thg in ra tu` tr?n xu??ng duo?i
		{
			gotoxy(i, j);
			cout << char(95); // in ra d?u ga?ch ngang ngan ca?ch tu`ng ha`ng
		}
		gotoxy(i, 3 + 2 * 19);
		cout << " ";
	}
	for (int i = 1; i < 3 + 2 * 19; i++) // ve~ c??t ngan ca?ch tu`ng mu?c
	{
		gotoxy(0, i);
		cout << " ";
		gotoxy(9, i);
		cout << " ";
		gotoxy(47, i);
		cout << " ";
		gotoxy(64, i);
		cout << " ";
		gotoxy(98, i);
		cout << " ";
		gotoxy(111, i);
		cout << " ";
		gotoxy(124, i);
		cout << " ";
	}
	SetBGColor(15);
	if (tl.size == 0)
	{
		gotoxy(60, 25);
		cout << "Empty!!!";
	}
	gotoxy(3, 1);
	cout << "ISBN";
	gotoxy(26, 1);
	cout << "BOOK NAME";
	gotoxy(55, 1);
	cout << "Genre";
	gotoxy(77, 1);
	cout << "AUTHOR";
	gotoxy(103, 1);
	cout << "PAGE";
	gotoxy(116, 1);
	cout << "YEAR";
	loadListTOC(tl, count);
	SetBGColor(11);
	SetColor(0);
}

void TranverNotBorrowed(TableOfContentList &tl, TableOfContentList &tmp)//duyet sach chua muon
{
	for (int i = 0; i < tl.size; i++)
	{
		if (!checkBorrowed(tl.ds[i]))
		{
			tmp.ds[tmp.size] = tl.ds[i];
			tmp.size++;
		}
	}
}

void BorrowMode(nodeRC *p, TableOfContentList &tl)//che do muon
{
	int count = 19, flag = 0;
	for (int i = 0; i <= 124; i++) // cha?y theo chi?`u da`i, tra?i -> pha?i
	{
		SetBGColor(6);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetColor(0);
		for (int j = 4; j < 3 + 2 * 19; j += 2) // co? bao nhi?u thg in ra tu` tr?n xu??ng duo?i
		{
			gotoxy(i, j);
			cout << char(95); // in ra d?u ga?ch ngang ngan ca?ch tu`ng ha`ng
		}
		gotoxy(i, 3 + 2 * 19);
		cout << " ";
	}
	for (int i = 1; i < 3 + 2 * 19; i++) // ve~ c??t ngan ca?ch tu`ng mu?c
	{
		gotoxy(0, i);
		cout << " ";
		gotoxy(9, i);
		cout << " ";
		gotoxy(47, i);
		cout << " ";
		gotoxy(64, i);
		cout << " ";
		gotoxy(98, i);
		cout << " ";
		gotoxy(111, i);
		cout << " ";
		gotoxy(124, i);
		cout << " ";
	}
	SetBGColor(15);
	if (tl.size == 0)//thong bao neu danh sach trong
	{
		gotoxy(60, 25);
		cout << "Empty!!!";
	}
	gotoxy(3, 1);
	cout << "ISBN";
	gotoxy(26, 1);
	cout << "BOOK NAME";
	gotoxy(55, 1);
	cout << "Genre";
	gotoxy(77, 1);
	cout << "AUTHOR";
	gotoxy(103, 1);
	cout << "PAGE";
	gotoxy(116, 1);
	cout << "YEAR";

	TableOfContentList tmp;

	TranverNotBorrowed(tl, tmp);

	TableTOC(tmp, count);

	gotoxy(2, 3);
	Tick(2, 3);

	while (true)
	{
		char c = _getch();
		if (c == 27) // esc
		{
			return;
		}
		else if (c == 32) // space
		{
			system("cls");
			filterBySearching(tmp, count, flag);
			controlfilterBySearching(tmp, count, flag);
			system("cls");
			BorrowMode(p, tmp);
			break;
		}
		else if (c == 75) /// left
		{
			if (count == 19)
			{
				continue;
			}

			count -= 19;
			clearTableTOC();
			loadListTOC(tmp, count);
			gotoxy(2, 3);
			Tick(2, 3);
		}
		else if (c == 77) // right
		{
			if (count >= tmp.size)
			{
				continue;
			}

			count += 19;
			clearTableTOC();
			loadListTOC(tmp, count);
			gotoxy(2, 3);
			Tick(2, 3);
		}
		else if (c == 80) // down
		{
			if (count - 19 + (wherey() - 3) / 2 == tmp.size - 1)
			{
				UnTick(wherex(), wherey());
				gotoxy(2, 3);
				Tick(wherex(), wherey());
			}
			else if (wherey() == 3 + 2 * 18)
			{
				UnTick(wherex(), wherey());
				gotoxy(2, 3);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(2, wherey() + 2);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 72) // up
		{

			if (wherey() == 3)
			{
				if (count >= tmp.size)
				{
					UnTick(wherex(), wherey());
					gotoxy(2, 3 + (tmp.size - (count - 19) - 1) * 2);
					Tick(wherex(), wherey());
					continue;
				}
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3 + 2 * 18);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() - 2);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 13) // enter
		{
			TableOfContent *t = tmp.ds[count - 19 + ((wherey() - 3) / 2)];
			nodeBAR *a = new nodeBAR;
			nodeB *b = t->dms.head;
			while (b != nullptr)
			{
				if (b->data.BookStatus == 0)
				{
					a->data.bookID = b->data.BookID;
					b->data.BookStatus = 1;
					break;
				}
				else
					b = b->next;
			}
			system("cls");
			addBorrowedBook(p->data.dsmt, a);
			gotoxy(70, 20);
			cout << "BORROW SUCCESSFULLY!!!";
			t->BorrowTotal++;
			Sleep(2000);
			return;
		}
		else
			continue;
	}
}

void ControlEditMode(TableOfContentList &tl, int &count)//chuc nang cua che do chinh sua
{
	gotoxy(1, 3);
	Tick(wherex(), wherey());
	while (true)
	{
		char c = _getch();
		if (c == 72)
		{ // up
			if (count > tl.size && wherey() == 3)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 1 + 2 * (tl.size - (count - 19)));
				Tick(wherex(), wherey());
			}
			else if (wherey() != 3)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() - 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 1 + 2 * 19);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 80)
		{ // down
			if (count > tl.size && wherey() == 1 + 2 * (tl.size - (count - 19)))
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3);
				Tick(wherex(), wherey());
			}
			else if (wherey() != 1 + 2 * 19)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() + 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 27)
		{ // esc
			UnTick(wherex(), wherey());
			return;
		}
		else if (c == 13)
		{ // enter
			editTOC(tl.ds[count - 19 + (wherey() - 3) / 2], wherey());
			break;
		}
		else if (c == 77)
		{ // right
			if (count >= tl.size)
			{
				continue;
			}
			else
			{
				UnTick(1, wherey());
				count += 19;
				clearTableTOC();
				loadListTOC(tl, count);
				gotoxy(1, 3);
				Tick(wherex(), wherey());
				continue;
			}
		}
		else if (c == 75)
		{ // left
			if (count == 19)
			{
				continue;
			}
			else
			{
				UnTick(1, wherey());
				count -= 19;
				clearTableTOC();
				loadListTOC(tl, count);
				gotoxy(1, 3);
				Tick(wherex(), wherey());
				continue;
			}
		}
		else
		{
			continue;
		}
	}
}

void deleteTOCMode(TableOfContentList& tl,int &count)//che do xoa dau sach 
{
	gotoxy(1, 3);
	Tick(wherex(), wherey());
	while (true)
	{
		char c = _getch();
		if (c == 72)//up
		{ 
			if (count > tl.size && wherey() == 3)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 1 + 2 * (tl.size - (count - 19)));
				Tick(wherex(), wherey());
			}
			else if (wherey() != 3)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() - 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 1 + 2 * 19);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 80)
		{ // down
			if (count > tl.size && wherey() == 1 + 2 * (tl.size - (count - 19)))
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3);
				Tick(wherex(), wherey());
			}
			else if (wherey() != 1 + 2 * 19)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() + 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 27)
		{ // esc
			UnTick(wherex(), wherey());
			return;
		}
		else if (c == 13)
		{ // enter			
			int x=wherex(),y=wherey();
			UnTick(wherex(),wherey());
			int pos=count - 19 + (wherey() - 3) / 2;
			nodeB* tmp=tl.ds[pos]->dms.head;
			while(tmp!=nullptr)
			{
				if(tmp->data.BookStatus==1)
				{
					gotoxy(127,30);
					cout<<"BEING BORROWED, CAN'T DELETE!";
					Sleep(1500);
					gotoxy(127,30);
					cout<<"                               ";
					return;
				}
				tmp=tmp->next;
			}
			int a=confirm(130,20);
			if(a==0)
			{
				Tick(x,y);
				continue;
			}
			
			delete tl.ds[pos];
			for(int i=pos;i<tl.size-1;i++) tl.ds[i]=tl.ds[i+1];
			tl.size--;
			break;
		}
		else if (c == 77)
		{ // right
			if (count >= tl.size)
			{
				continue;
			}
			else
			{
				UnTick(1, wherey());
				count += 19;
				clearTableTOC();
				loadListTOC(tl, count);
				gotoxy(1, 3);
				Tick(wherex(), wherey());
				continue;
			}
		}
		else if (c == 75)
		{ // left
			if (count == 19)
			{
				continue;
			}
			else
			{
				UnTick(1, wherey());
				count -= 19;
				clearTableTOC();
				loadListTOC(tl, count);
				gotoxy(1, 3);
				Tick(wherex(), wherey());
				continue;
			}
		}
		else
		{
			continue;
		}
	}
}

int liquidatingBook(nodeB* p)//thanh li
{
	if(p==nullptr) return 0;
	
	for(nodeB* i=p;i!=nullptr;i=i->next)
	{
		if(i->data.BookStatus==0)
		{
			i->data.BookStatus=2;
			return 1;
		}
	}
	return 0;
}

void liquidatingMode(TableOfContentList& tl,int &count)//che do thanh li
{
	gotoxy(1, 3);
	Tick(wherex(), wherey());
	while (true)
	{
		char c = _getch();
		if (c == 72)
		{ // up
			if (count > tl.size && wherey() == 3)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 1 + 2 * (tl.size - (count - 19)));
				Tick(wherex(), wherey());
			}
			else if (wherey() != 3)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() - 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 1 + 2 * 19);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 80)
		{ // down
			if (count > tl.size && wherey() == 1 + 2 * (tl.size - (count - 19)))
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3);
				Tick(wherex(), wherey());
			}
			else if (wherey() != 1 + 2 * 19)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() + 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 27)
		{ // esc
			UnTick(wherex(), wherey());
			break;
		}
		else if (c == 13)
		{ // enter
			int pos=count - 19 + (wherey() - 3) / 2;
			int n=liquidatingBook(tl.ds[pos]->dms.head);
			if(n==1)
			{
				system("cls");
				gotoxy(70, 20);
				cout<<"LIQUIDATE SUCCESSFULLY";
				Sleep(1500);
				system("cls");
			}
			else
			{
				UnTick(wherex(),wherey());
				system("cls");
				gotoxy(70, 20);
				cout<<"CAN NOT LIQUIDATE";
				Sleep(1500); 
				system("cls");
			}
			break;
		}
		else if (c == 77)
		{ // right
			if (count >= tl.size)
			{
				continue;
			}
			else
			{
				UnTick(1, wherey());
				count += 19;
				clearTableTOC();
				loadListTOC(tl, count);
				gotoxy(1, 3);
				Tick(wherex(), wherey());
				continue;
			}
		}
		else if (c == 75)
		{ // left
			if (count == 19)
			{
				continue;
			}
			else
			{
				UnTick(1, wherey());
				count -= 19;
				clearTableTOC();
				loadListTOC(tl, count);
				gotoxy(1, 3);
				Tick(wherex(), wherey());
				continue;
			}
		}
		else
		{
			continue;
		}
	}
}

void EnterToSearch(TableOfContentList tl, TableOfContentList &l)//nhap ten sach de tim kiem
{
	gotoxy(1, 43);
	SetBGColor(20);
	cout << "Enter BookName:";
	SetBGColor(15);
	cout << " ";
	string inputSearch = "";
	inputSearch = EnterBookName(inputSearch);
	SetBGColor(15);
	system("cls");
	if (inputSearch == "")
	{
		return;
	}
	l = saveToSearch(tl, inputSearch);
}

void controlTOCTable(TableOfContentList &tl, int count)//dieu khien dau sach
{
	SetBGColor(11);
	ShowCur(false);
	for (int i = 130; i <= 142; i++) // in ra ? chu?c nang
	{
		gotoxy(i, 3);
		cout << " ";
		gotoxy(i, 4);
		cout << " ";
		gotoxy(i, 5);
		cout << " ";

		gotoxy(i, 7);
		cout << " ";
		gotoxy(i, 8);
		cout << " ";
		gotoxy(i, 9);
		cout << " ";

		gotoxy(i, 11);
		cout << " ";
		gotoxy(i, 12);
		cout << " ";
		gotoxy(i, 13);
		cout << " ";
		
		gotoxy(i, 15);
		cout << " ";
		gotoxy(i, 16);
		cout << " ";
		gotoxy(i, 17);
		cout << " ";
		
		gotoxy(i, 19);
		cout << " ";
		gotoxy(i, 20);
		cout << " ";
		gotoxy(i, 21);
		cout << " ";
		
	}
	gotoxy(135, 4);
	cout << "ADD";
	gotoxy(134, 8);
	cout << "EDIT";
	gotoxy(134, 12);
	cout << "SEARCH";
	gotoxy(134,16);
	cout<<"DELETE";
	gotoxy(132,20);
	cout<<"LIQUIDATE";
	HighLight(130, 3, 12);

	while (true)
	{
		// nhan phim tu nguoi dung(up/down/enter)
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		if (c == 27) // khi nguoi dung nhan esc
		{
			SetBGColor(15);
			break;
		}
		else if (c == 72) // khi nguoi dung nhan UP
		{
			if (wherey() == 3)
			{
				UnHighLight(wherex(), wherey(), 12);
				gotoxy(130, 19);
				HighLight(wherex(), wherey(), 12);
			}
			else
			{
				UnHighLight(wherex(), wherey(), 12);
				gotoxy(130, wherey() - 4);
				HighLight(wherex(), wherey(), 12);
			}
		}
		else if (c == 80) // khi nguoi dung nhan Down
		{
			if (wherey() == 19)
			{
				UnHighLight(wherex(), wherey(), 12);
				gotoxy(130, 3);
				HighLight(wherex(), wherey(), 12);
			}
			else
			{
				UnHighLight(wherex(), wherey(), 12);
				gotoxy(130, wherey() + 4);
				HighLight(wherex(), wherey(), 12);
			}
		}
		else if (c == 75) /// left
		{
			if (count == 19)
			{
				continue;
			}
			UnHighLight(wherex(), wherey(), 12);
			count -= 19;
			SetBGColor(15);
			clearTableTOC();

			loadListTOC(tl, count);
			gotoxy(130, 3);
			HighLight(wherex(), wherey(), 12);
		}
		else if (c == 77) // right
		{
			if (count > tl.size)
			{
				continue;
			}
			UnHighLight(wherex(), wherey(), 12);
			count += 19;
			SetBGColor(15);
			clearTableTOC();

			loadListTOC(tl, count);
			gotoxy(130, 3);
			HighLight(wherex(), wherey(), 12);
		}
		else if (c == 13) // Khi nguoi dung nhan ENTER
		{
			SetBGColor(15);
			if (wherey() == 3) // add
			{
				count = 19;
				system("cls");
				string locateISBN = tableEnterTOC(tl);
				if(locateISBN!="")
					while(count <= tl.size){
						if(tl.ds[count-19]->ISBN<=locateISBN &&locateISBN<=tl.ds[count]->ISBN) break;
						else count+=19;
					}
				system("cls");

				TableTOC(tl, count);
				controlTOCTable(tl, count);
				break;
			}
			else if (wherey() == 7) // edit
			{
				ControlEditMode(tl, count);
				TableTOC(tl, count);
				controlTOCTable(tl, count);
				break;
			}
			else if(wherey()==11) // search
			{
				int flag = count - 19;
				TableOfContentList l;
				EnterToSearch(tl, l);
				filterBySearching(l, count, flag);
				controlfilterBySearching(l, count, flag);
				SetBGColor(15);
				TableTOC(tl, count);
				controlTOCTable(tl, count);
				break;
			}
			else if(wherey()==15)//delete
			{
				deleteTOCMode(tl,count);
				system("cls");
				TableTOC(tl, count);
				controlTOCTable(tl, count);
				break;
			}
			else//liquidate
			{
				liquidatingMode(tl,count);
				TableTOC(tl, count);
				controlTOCTable(tl,count);
				break;
			} 
		}
		else
		{
			continue;
		}
	}
}

void printBAR(nodeBAR *b, int y, TableOfContentList tl)//in ra thong tin muon tra
{
	string name = findBookName(tl, b->data.bookID);
	gotoxy(12, 3 + 2 * y);
	cout << b->data.bookID << "\t";
	cout << name;
	gotoxy(72, 3 + 2 * y);
	cout << b->data.BorrowDate.day << "/" << b->data.BorrowDate.month << "/" << b->data.BorrowDate.year << "\t\t";
	cout << b->data.ReturnDate.day << "/" << b->data.ReturnDate.month << "/" << b->data.ReturnDate.year;
}

void BARofReader(nodeRC *p, TableOfContentList tl)//in ra thong va sach dang muon
{
	SetBGColor(6);
	gotoxy(10, 7);
	cout << " ";
	gotoxy(30, 7);
	cout << " ";
	gotoxy(65, 7);
	cout << " ";
	gotoxy(85, 7);
	cout << " ";
	gotoxy(100, 7);
	cout << " ";
	gotoxy(120, 7);
	cout << " ";
	for (int i = 10; i <= 120; i++)
	{
		SetBGColor(6);
		gotoxy(i, 6);
		cout << " ";
		gotoxy(i, 8);
		cout << " ";
		gotoxy(i, 10);
		cout << " ";
		gotoxy(i, 12);
		cout << " ";
		gotoxy(i, 14);
		cout << " ";
		gotoxy(i, 16);
		cout << " ";
	}
	SetBGColor(15);
	displayReader(p, 2);
	int y = 4;
	gotoxy(12, 1 + 2 * y);
	cout << "BookID\t" << "Name\t\t\t\t\t\t" << "Borrowed Date\t\t" << "Return Date\t";
	nodeBAR *b = p->data.dsmt.head;
	while (b != nullptr)
	{
		printBAR(b, y, tl);
		b = b->next;
		y++;
	}
}

void resetBookStatus(TableOfContentList &tl, nodeBAR *b, string isbn)//tra sach reset status ve 0
{
	for (int i = 0; i < tl.size; i++)
	{
		if (tl.ds[i]->ISBN == isbn)
		{
			nodeB *t = tl.ds[i]->dms.head;
			while (t != nullptr)
			{
				if (t->data.BookID == b->data.bookID)
				{
					t->data.BookStatus = 0;
				}
				t = t->next;
			}
		}
	}
}



void returnMode(nodeRC *p, TableOfContentList &tl)//che do tra sach
{
	gotoxy(10, 3 + 2 * 4);
	Tick(wherex(), wherey());
	while (true)
	{
		char c = _getch();
		if (c == 27) // esc
		{
			return;
		}
		else if (c == 72) // up
		{
			if (wherey() == 3 + 4 * 2)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3 + (3 + p->data.dsmt.size) * 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() - 2);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 80) // down
		{
			if (wherey() == 3 + (3 + p->data.dsmt.size) * 2)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3 + 2 * 4);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() + 2);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 13) // enter
		{
			UnTick(wherex(), wherey());
			if (wherey() == 3 + 2 * 4) // head
			{
				nodeBAR *b = p->data.dsmt.head;
				string isbn = "";
				for (int i = 0; i < 4; i++)
				{
					isbn += b->data.bookID[i];
				}
				resetBookStatus(tl, b, isbn);
				returnedBook(p->data.dsmt, b);
				gotoxy(50, 30);
				cout << "RETURN SUCCESSFULLY!!!";
				Sleep(2000);
				break;
			}
			else if (wherey() == 3 + 2 * 5)
			{
				nodeBAR *b = p->data.dsmt.head->next;
				string isbn = "";
				for (int i = 0; i < 4; i++)
				{
					isbn += b->data.bookID[i];
				}
				resetBookStatus(tl, b, isbn);
				returnedBook(p->data.dsmt, b);
				gotoxy(50, 30);
				cout << "RETURN SUCCESSFULLY!!!";
				Sleep(2000);
				break;
			}
			else
			{
				nodeBAR *b = p->data.dsmt.tail;
				string isbn = "";
				for (int i = 0; i < 4; i++)
				{
					isbn += b->data.bookID[i];
				}
				resetBookStatus(tl, b, isbn);
				returnedBook(p->data.dsmt, b);
				gotoxy(50, 30);
				cout << "RETURN SUCCESSFULLY!!!";
				Sleep(2000);
				break;
			}
		}
		else
			continue;
	}
}

void lostBook(TableOfContentList& tl,nodeBAR* b,string isbn)//mat sach 
{
	nodeB* tmp = nullptr;
	for(int i=0;i<tl.size;i++)
	{
		if(tl.ds[i]->ISBN==isbn)
		{
			tmp=tl.ds[i]->dms.head;
			break;
		}
	}
	while(tmp!=nullptr)
	{
		if(tmp->data.BookID==b->data.bookID) break;
		tmp=tmp->next;
	}
	tmp->data.BookStatus=2;
}

void lostMode(nodeRC* p,TableOfContentList& tl)//che do mat sach
{
	gotoxy(10, 3 + 2 * 4);
	Tick(wherex(), wherey());
	while (true)
	{
		char c = _getch();
		if (c == 27) // esc
		{
			return;
		}
		else if (c == 72) // up
		{
			if (wherey() == 3 + 4 * 2)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3 + (3 + p->data.dsmt.size) * 2);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() - 2);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 80) // down
		{
			if (wherey() == 3 + (3 + p->data.dsmt.size) * 2)
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), 3 + 2 * 4);
				Tick(wherex(), wherey());
			}
			else
			{
				UnTick(wherex(), wherey());
				gotoxy(wherex(), wherey() + 2);
				Tick(wherex(), wherey());
			}
		}
		else if (c == 13) // enter
		{
			UnTick(wherex(), wherey());
			if (wherey() == 3 + 2 * 4) // head
			{
				nodeBAR *b = p->data.dsmt.head;
				string isbn = "";
				for (int i = 0; i < 4; i++)
				{
					isbn += b->data.bookID[i];
				}
				lostBook(tl,b,isbn);
				returnedBook(p->data.dsmt,b);
				gotoxy(50, 30);
				cout << "SUCCESSFULLY!!!";
				Sleep(2000);
				break;
			}
			else if (wherey() == 3 + 2 * 5)
			{
				nodeBAR *b = p->data.dsmt.head->next;
				string isbn = "";
				for (int i = 0; i < 4; i++)
				{
					isbn += b->data.bookID[i];
				}
				lostBook(tl,b,isbn);
				returnedBook(p->data.dsmt,b);
				gotoxy(50, 30);
				cout << "SUCCESSFULLY!!!";
				Sleep(2000);
				break;
			}
			else
			{
				nodeBAR *b = p->data.dsmt.tail;
				string isbn = "";
				for (int i = 0; i < 4; i++)
				{
					isbn += b->data.bookID[i];
				}
				lostBook(tl,b,isbn);
				returnedBook(p->data.dsmt,b);
				gotoxy(50, 30);
				cout << "SUCCESSFULLY!!!";
				Sleep(2000);
				break;
			}
		}
		else
			continue;
	}
}

void controlBAR(ReaderList &rl, TableOfContentList &tl, int count, nodeRC *p)//chuc nang dieu khien muon tra
{
	Option(140, 3, 14, 0, "BORROW");
	Option(140, 8, 14, 0, "RETURN");
	Option(140,13,14,0,"LOST");
	HighLight(134, 2, 20);
	while (true)
	{
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		if (c == 72)
		{ // khi nguoi dung nhan up
			if (wherey() == 2)
			{
				UnHighLight(wherex(), wherey(), 20);
				gotoxy(wherex(), wherey() + 10);
				HighLight(wherex(), wherey(), 20);
			}
			else
			{
				UnHighLight(wherex(), wherey(), 20);
				gotoxy(wherex(), wherey() - 5);
				HighLight(wherex(), wherey(), 20);
			}
		}
		else if (c == 80) // khi nguoi dung nhan Down
		{
			if (wherey() == 12)
			{
				UnHighLight(wherex(), wherey(), 20);
				gotoxy(wherex(), wherey() - 10);
				HighLight(wherex(), wherey(), 20);
			}
			else
			{
				UnHighLight(wherex(), wherey(), 20);
				gotoxy(wherex(), wherey() + 5);
				HighLight(wherex(), wherey(), 20);
			}
		}
		else if (c == 27) // esc
		{
			system("cls");
			SetBGColor(15);
			return;
		}
		else if (c == 13)
		{ // enter
			if (wherey() == 2)
			{
				if (p->data.dsmt.size == 3)
				{
					SetBGColor(7);
					SetColor(20);
					gotoxy(50, 25);
					cout << "LIMIT REACHED! RETURN BEFORE BORROW!";
					Sleep(2000);
					SetBGColor(15);
					SetColor(0);
					gotoxy(50, 25);
					cout << "                                         ";
					gotoxy(134, 2);
					continue;
				}
				else if (p->data.CardStatus == 0)
				{
					gotoxy(50, 25);
					cout << "CARD IS LOCKED, CAN NOT BORROW!!";
					Sleep(2000);
					gotoxy(50, 25);
					cout << "                                         ";
					gotoxy(134, 2);
					continue;
				}
				system("cls");
				BorrowMode(p, tl);
				system("cls");
				BARofReader(p, tl);
				controlBAR(rl, tl, count, p);
				return;
			}
			else if(wherey()==7)
			{
				if (p->data.dsmt.size == 0)
				{
					gotoxy(50, 25);
					cout << "NO BORROWED BOOK";
					Sleep(1000);
					gotoxy(50, 25);
					cout << "                 ";
					gotoxy(134, 2);
					continue;
				}
				else
				{
					int n=TotalOverdue(p);
					returnMode(p, tl);
					if(TotalOverdue(p)<=0)
					{
						if(n>0) p->data.CardStatus=1; 
					}
					system("cls");
					BARofReader(p, tl);
					controlBAR(rl, tl, count, p);
					break;
				}
			}
			else
			{
				if(p->data.dsmt.size==0)
				{
					gotoxy(50, 25);
					cout << "NO BORROWED BOOK";
					Sleep(1000);
					gotoxy(50, 25);
					cout << "                 ";
					gotoxy(134, 2);
					continue;
				}
				else
				{
					lostMode(p,tl);
					system("cls");
					BARofReader(p,tl);
					controlBAR(rl,tl,count,p);
					break;
				}
			}
		}
	}
}

nodeRC *EnterIDtoBorrowandReturn(ReaderList rl)//nhap id de vao che do muon tra
{
	system("cls");
	ShowCur(true);
	SetBGColor(9);
	for(int i=0;i<=65;i++)
	{
		gotoxy(45+i,19); cout<<" ";
		gotoxy(45+i,21);cout<<" ";
		gotoxy(45+i,23);cout<<" ";
		for(int j=0;j<=4;j++)
		{
			gotoxy(45,19+j); cout<<" ";
			gotoxy(110,19+j); cout<<" ";
		}
	}
	SetBGColor(20);
	SetColor(15);
	gotoxy(50, 22);
	cout << "NOTE: only 4 numbers!, enter SPACE to open Reader List";
	SetBGColor(15);
	SetColor(0);
	gotoxy(50, 20);
	cout << "ENTER CARD ID: ";
	gotoxy(70, 20);
	string id = EnterID();
	ShowCur(false);
	if (id == "")
	{
		system("cls");
		return nullptr;
	}
	else if (id == " ")
	{
		system("cls");
		nodeRC *tmp[MAX];
		int size = 0;
		tranvertree(rl.head, tmp, size);
		watchingReaderMode(tmp, size);
		system("cls");
		return EnterIDtoBorrowandReturn(rl);
	}
	nodeRC *p = findReader(rl.head, id);
	if (p == nullptr)
	{
		gotoxy(60, 24);
		cout << "READER NOT FOUND";
		Sleep(1500);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                    ";
		system("cls");
		return EnterIDtoBorrowandReturn(rl);
	}
	else
	{
		system("cls");
		return p;
	}
}

void top10Borrow(TableOfContentList tl)//thong ke 10 dau sach duoc muon nhieu nhat
{
		for (int i = 0; i <= 133; i++) // cha?y theo chi?`u da`i, tra?i -> pha?i
	{
		SetBGColor(6);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetColor(0);
		for (int j = 4; j < 3 + 2 * 10; j += 2) // co? bao nhi?u thg in ra tu` tr?n xu??ng duo?i
		{
			gotoxy(i, j);
			cout << char(95); // in ra d?u ga?ch ngang ngan ca?ch tu`ng ha`ng
		}
		gotoxy(i, 3 + 2 * 10);
		cout << " ";
	}
	for (int i = 1; i < 3 + 2 * 10; i++) // ve~ c??t ngan ca?ch tu`ng mu?c
	{
		gotoxy(0, i);
		cout << " ";
		gotoxy(9, i);
		cout << " ";
		gotoxy(47, i);
		cout << " ";
		gotoxy(64, i);
		cout << " ";
		gotoxy(98, i);
		cout << " ";
		gotoxy(111, i);
		cout << " ";
		gotoxy(124, i);
		cout << " ";
		gotoxy(133,i);
		cout<<" ";
	}
	SetBGColor(15);
	gotoxy(3, 1);
	cout << "ISBN";
	gotoxy(26, 1);
	cout << "BOOK NAME";
	gotoxy(55, 1);
	cout << "Genre";
	gotoxy(77, 1);
	cout << "AUTHOR";
	gotoxy(103, 1);
	cout << "PAGE";
	gotoxy(116, 1);
	cout << "YEAR";
	gotoxy(126,1);
	cout<<"TOTAL";
	for (int i = 0; i < tl.size; i++)
	{
		for (int j = 0; j < tl.size - 1; j++)
		{
			if (tl.ds[j]->BorrowTotal > tl.ds[j + 1]->BorrowTotal)
			{
				swap(tl.ds[j], tl.ds[j + 1]);
			}
		}
	}

	int n = tl.size - 1;
	int y = 3;
	if (tl.ds[n]->BorrowTotal == 0)
	{
		SetBGColor(10);
		gotoxy(50, 15);
		cout << "ALL BOOK ARE NOT BORROWED!!!";
		SetBGColor(15);
	}
	while (n >= tl.size - 10 && n >= 0 && tl.ds[n]->BorrowTotal > 0)
	{
		displayTOC(*tl.ds[n], y);
		cout << "\t" << tl.ds[n]->BorrowTotal;
		n--;
		y += 2;
	}
	SetBGColor(10);
	gotoxy(137, 10);
	cout << "ESC to quit";
	SetBGColor(15);
	char c;

	while (true)
	{
		c = _getch();
		if (c == 27) // esc
		{
			return;
		}
		else
			continue;
	}
}
void sortOverdue(int OverdueArr[], nodeRC *tmp[], int size)//sap xep danh sach doc gia qua han
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (OverdueArr[j] < OverdueArr[j + 1])
			{
				swap(OverdueArr[j], OverdueArr[j + 1]);
				swap(tmp[j], tmp[j + 1]);
			}
		}
	}
}

void displayOverdue(nodeRC *tmp[], int OverdueArr[], int size, int count)//in ra danh sach doc gia qua han
{
	int y = 0;
		for (int i = 10; i <= 136; i++)
	{
		SetBGColor(6);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetColor(16);
		for (int j = 4; j < 3 + 2 * 20; j += 2)
		{
			gotoxy(i, j);
			cout << char(95);
		}
		gotoxy(i, 3 + 2 * 20);
		cout << " ";
	}
	for (int i = 1; i < 3 + 2 * 20; i++)
	{
		gotoxy(10, i);
		cout << " ";
		gotoxy(30, i);
		cout << " ";
		gotoxy(65, i);
		cout << " ";
		gotoxy(85, i);
		cout << " ";
		gotoxy(100, i);
		cout << " ";
		gotoxy(120, i);
		cout << " ";
		gotoxy(136,i);
		cout<<" ";
	}
	SetBGColor(15);
	gotoxy(17, 1);
	cout << "ID";
	gotoxy(45, 1);
	cout << "LAST NAME";
	gotoxy(72, 1);
	cout << "FIRST NAME";
	gotoxy(90, 1);
	cout << "GENDER";
	gotoxy(108, 1);
	cout << "STATUS";
	gotoxy(122,1);
	cout<<"TOTAL OVERDUE";
	for (int i = count - 20; i < count; i++)
	{
		if (OverdueArr[i] <= 0 || i == size )
			return;
		else
		{
			displayReader(tmp[i], y);
			gotoxy(wherex()+10,wherey());
			if(OverdueArr[i] <= 1){
				cout<< OverdueArr[i] << "(day)";
			}else{
				cout<< OverdueArr[i] << "(days)";
			}
			y ++;
		}
	}
}

void OverdueReader(ReaderList rl)//che do xem danh sach qua han
{
	int size = 0; int count=20;
	nodeRC *tmp[MAX];
	int *OverdueArr = new int[MAX];

	tranvertree(rl.head, tmp, size);
	for (int i = 0; i < rl.size; i++)
	{
		OverdueArr[i] = TotalOverdue(tmp[i]);
		if(OverdueArr[i]<=0) size--;
	}

	if (size > 0){
		sortOverdue(OverdueArr, tmp, rl.size);
		displayOverdue(tmp,OverdueArr,size,count);
	}
	else
	{
		SetBGColor(10);
		gotoxy(50, 15);
		cout << "NO OVERDUE READER";
		SetBGColor(15);
	}

	SetBGColor(10);
	gotoxy(140, 10);
	cout << "ESC to quit";
	SetBGColor(15);

	while (true)
	{
		char c = _getch();
		if (c == 27) // esc
		{
			break;
		}
		else if (c == 75) /// left
		{
			if (count == 20)
				continue;
			count -= 20;
			clearReaderTable();
			for(int i=3;i<3+20*2;i+=2)
			{
				gotoxy(122,i);
				cout<<"        ";
			}
			displayOverdue(tmp, OverdueArr, size, count);
		}
		else if (c == 77) // right
		{
			if (count >= size)
				continue;
			count += 20;
			clearReaderTable();
			for(int i=3;i<3+20*2;i+=2)
			{
				gotoxy(122,i);
				cout<<"        ";
			}
			displayOverdue(tmp, OverdueArr, size, count);
		}
		else
			continue;
	}
	delete[] OverdueArr;
}

void Statistic(ReaderList rl, TableOfContentList tl)//chuc nang thong ke
{
	Option(70, 10, 24, 4, "TOP 10 BORROWED BOOKS");
	Option(70, 14, 24, 4, "OVERDUE READER LIST");

	HighLight(64, 9, 30);
	while (true)
	{
		char c = _getch();
		if (c == 27) // esc
		{
			return;
		}
		else if (c == 72 || c == 80) // up & down
		{
			if (wherey() == 9)
			{
				UnHighLight(wherex(), wherey(), 30);
				gotoxy(wherex(), wherey() + 4);
				HighLight(wherex(), wherey(), 30);
			}
			else
			{
				UnHighLight(wherex(), wherey(), 30);
				gotoxy(wherex(), wherey() - 4);
				HighLight(wherex(), wherey(), 30);
			}
		}
		else if (c == 13) // enter
		{
			if (wherey() == 9)
			{
				system("cls");
				top10Borrow(tl);
				system("cls");
				Statistic(rl, tl);
				break;
			}
			else
			{
				system("cls");
				OverdueReader(rl);
				system("cls");
				Statistic(rl, tl);
				break;
			}
		}
		else
			continue;
	}
}

// dieu khien tren menu chinh
void Control(ReaderList &rl, TableOfContentList &tl)
{
	int x = 18;
	int y = 12;
	int width = 150;
	int height = 30;
	// danh dau lua chon dau
	gotoxy(x - 6, y + height / 4 + 1);

	HighLight(wherex(), wherey(), width / 3);
	while (true)
	{
		// nhan phim tu nguoi dung(up/down/enter)
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		if (c == 27)
			continue;
		else if (c == 72) // khi nguoi dung nhan UP
		{
			if (wherey() == y + height / 4 + 1)
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x - 6, y + height / 4 + 16 + 1);
				HighLight(wherex(), wherey(), width / 3);
			}
			else
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x - 6, wherey() - 4);
				HighLight(wherex(), wherey(), width / 3);
			}
		}
		else if (c == 80) // khi nguoi dung nhan Down
		{
			if (wherey() == y + height / 4 + 16 + 1)
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x - 6, y + height / 4 + 1);
				HighLight(wherex(), wherey(), width / 3);
			}
			else
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x - 6, wherey() + 4);
				HighLight(wherex(), wherey(), width / 3);
			}
		}
		else if (c == 13) // Khi nguoi dung nhan ENTER
		{
			SetBGColor(15);

			if (wherey() == y + height / 4 + 16 + 1) // quit
			{
				system("cls");
				int n = saveFileReader(rl);
				int m = saveTOC(tl);
				if (n == 0 || m == 0)
				{
					system("cls");
					gotoxy(60, 20);
					cout << "CAN'T SAVE!!!\n";
					Sleep(1000);
				}
				else
				{
					system("cls");
					gotoxy(60, 20);
					cout << "SAVING SUCCESSFUL!!!";
					Sleep(1000);
				}
				system("cls");
				break;
			}
			else if (wherey() == y + height / 4 + 1) // option 1 (reader card)
			{
				system("cls");
				int n = 0;
				nodeRC *tmp[MAX];
				tranvertree(rl.head, tmp, n);
				sortbyID(tmp, n);
				ReaderTable(tmp, rl.size, 20);
				controlReaderTable(rl, tmp, 20);
				system("cls");
				boxMenu();
				Control(rl, tl);
				break;
			}
			else if (wherey() == y + height / 4 + 4 + 1) // option 2(table of content)
			{
				system("cls");
				TableTOC(tl, 19);
				controlTOCTable(tl, 19);
				system("cls");
				boxMenu();
				Control(rl, tl);
				break;
			}
			else if (wherey() == y + height / 4 + 8 + 1) // option 3 (borrow and return)
			{
				if (rl.size == 0)
				{
					gotoxy(80, 20);
					cout << "EMPTY READERLIST";
					Sleep(2000);
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                 ";
				}
				else
				{
					int count = 19;
					nodeRC *p = EnterIDtoBorrowandReturn(rl);
					if (p != nullptr)
					{
						BARofReader(p, tl);
						controlBAR(rl, tl, count, p);
					}
				}
				SetBGColor(15);
				boxMenu();
				Control(rl, tl);
				break;
			}
			else if (wherey() == y + height / 4 + 12 + 1) // option 4;(statistic)
			{
				system("cls");
				Statistic(rl, tl);
				system("cls");
				boxMenu();
				Control(rl, tl);
				break;
			}
			continue;
		}
	}
}

int main()
{
	SetBGColor(0);
	//resizeConsole(1300, 750);//thay doi kich thuong console
	fullscreen();
	ReaderList rl;
	TableOfContentList tl;
	DisableSelection();//tat khong cho boi den
	//DisableCtrButton(0, 1, 1);//tat chuc nang phong to va an console
	DisableResizeWindow();//tat khong cho thay doi kich thuoc console
	ShowCur(false);//an con tro
	loading();//man hinh loading
	int n = loadFileReader(rl);
	int m = loadFileTOC(tl);
	
	if (n == 0 || m == 0)
	{
		cout << "CAN'T LOAD FILE\n";
		system("pause");
		return 0;
	}
	
	SetBGColor(15);
	boxMenu();
	Control(rl, tl);
	delete rl.head;//giai phong bo nho
	releaseMemory(tl);//giai phong bo nho
	return 0;
}
