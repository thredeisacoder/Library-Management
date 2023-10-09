#include "mylib.h"
#include "struct.h"
#include "process.h"

using namespace std;

// man hinh loading
void loading()
{
	string s = "POSTS AND TELECOMMUNICATIONS INSTITUTE OF TECHNOLOGY!!!";
	for (unsigned int i = 0; i <= s.length() - 1; i++)
	{
		gotoxy(40 + i, 10);
		cout << s[i];
		gotoxy(40 + i, 12);
		SetBGColor(15);
		cout << " ";
		SetBGColor(16);
		Sleep(20);
	}
	Sleep(1000);
	system("cls");
}

//Khung tieu de
void Tittle(int x, int y, int width, int height, string tittle)
{
	for (int i = x + width / 6; i <= x + width * 5 / 6 - 12; i++)//so cot 
	{
		for (int j = y - 2; j <= y + height / 6 - 2; j++)//to tung o cua tung cot
		{
			SetBGColor(15);//mau nen trang
			gotoxy(i, j);
			cout << " ";//to mau trang cho khung tieu de
		}
	}
	//dua con tro den giua khung va in tieu de
	gotoxy(x + width / 2 - 14, y + height / 16 - 1);
	SetColor(10);//chu mau xanh
	cout << tittle;
}

//in lua chon
void Option(int x, int y, int width, int height, string option)
{
	for (int i = x - 6; i <= x + width / 3 - 6; i++)//vong lap chay tu dau den het chieu dai option
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i, y - 1);
		cout << " ";
		gotoxy(i, y);
		cout << " ";
		SetBGColor(15);
		gotoxy(i, y + 1);
		cout << " ";
	}
	gotoxy(x, y);
	cout << option;
}

//tao menu
void boxMenu()
{
	int x = 20;
	int y = 2;
	int width = 120;
	int height = 30;

	if (width <= 1 || height <= 1) return;
	Tittle(x, y, width, height, "LIBRARY MANAGEMENT");
	Option(x + width / 3, y + height / 4, width, height, "READER CARD!");
	Option(x + width / 3, y + height / 4 + 4, width, height, "BOOK CATALOG!");
	Option(x + width / 3, y + height / 4 + 8, width, height, "TABLE OF CONTENT!");
	Option(x + width / 3, y + height / 4 + 12, width, height, "BORROW AND RETURN!");
	Option(x + width / 3, y + height / 4 + 16, width, height, "UPDATE INFORMATION!");
	Option(x + width / 3, y + height / 4 + 20, width, height, "QUIT!");

	//in 2 canh ben cua khung menu
	for (int i = y - 2; i <= y + height + 2; i++)
	{
		gotoxy(x + width / 6, i);
		cout << "  ";
		gotoxy(x + width * 5 / 6 - 12, i);
		cout << "  ";
	}


	//in khung duoi cua menu
	for (int i = x + width / 6; i < x + width * 5 / 6 - 12; i++)
	{
		gotoxy(i, y + height + 2);
		cout << " ";
	}

	//in huong dan
	gotoxy(x + width / 6 + 10, y + height * 5 / 6 + 6);
	cout << "Press Up and Down to move and Enter to choose!!! ";

	SetBGColor(16);
	SetColor(15);

}

// bat thanh sang
void HighLight(int x, int y, int width)
{
	for (int i = x; i <= x + width; i++)
	{
		for (int j = y; j <= y + 2; j += 2)
		{
			SetBGColor(9);
			gotoxy(i, j);
			cout << " ";
		}
	}
	SetBGColor(16);

	gotoxy(x, y);
}

//tat thanh sang
void UnHighLight(int x, int y, int width)
{
	for (int i = x; i <= x + width; i++)
	{
		for (int j = y; j <= y + 2; j += 2)
		{
			SetBGColor(15);
			gotoxy(i, j);
			cout << " ";
		}
	}
	SetBGColor(16);
	gotoxy(x, y);

}

//nhap doc gia moi
void tableEnterRC(ReaderList& rl)
{
	Reader data;
	SetColor(15);
	int x = 10, y = 2, width = 120, height = 80;
	gotoxy(x + width / 3, y + height / 4);
	cout << "GENDER: 1 FOR MALE & 2 FOR FEMALE !\n ";
	gotoxy(x + width / 3, y + height / 4 + 1);
	cout << "STATUS: 0(LOCKED) & 1(UNLOCKED)";
	for (int i = x + width / 6; i < x + width * 5 / 6; i++)
	{
		SetBGColor(15);
		gotoxy(i, y + 8);
		cout << " ";
		gotoxy(i, y + 10);
		cout << " ";
		gotoxy(i, y + 12);
		cout << " ";
	}
	SetBGColor(16);
	gotoxy(x + width / 6 + 1, y + 9);
	cout << " | ID |";
	gotoxy(x + width / 6 + 12, y + 9);
	cout << "| FIRST NAME | ";
	gotoxy(x + width / 6 + 30, y + 9);
	cout << " | LAST NAME | ";
	gotoxy(x + width / 6 + 45, y + 9);
	cout << " | GENDER | ";
	gotoxy(x + width / 6 + 60, y + 9);
	cout << " | STATUS | ";

	gotoxy(x + width / 6 + 1, y + 11);
	data.ID = EnterID();
	gotoxy(x + width / 6 + 14, y + 11);
	data.FirstName = EnterFirstName();
	gotoxy(x + width / 6 + 32, y + 11);
	data.LastName = EnterLastName();
	gotoxy(x + width / 6 + 47, y + 11);
	data.Gender = EnterGender();
	gotoxy(x + width / 6 + 62, y + 11);
	data.CardStatus = EnterCardStatus();

	gotoxy(x + width / 3, y + 15);
	int n = addNodeReader(rl, data);
	if (n == 1)	cout << "add successfully";
	else cout << "can not add";
	gotoxy(x + width / 3, y + 16);
	Sleep(1000);
}

void displayReader(nodeRC* p, int y)
{
	gotoxy(14, y);
	cout << p->data.ID;
	gotoxy(35, y);
	cout << p->data.FirstName;
	gotoxy(70, y);
	cout << p->data.LastName;
	gotoxy(90, y);
	cout << p->data.Gender;
	gotoxy(110, y);
	cout << p->data.CardStatus;
}

void displaytree(nodeRC* head, int& y)
{
	if (head == NULL) return;
	else
	{
		displaytree(head->left, y);
		y += 2;
		displaytree(head->right, y);
		displayReader(head, y);
	}
}

void DisplayReader(ReaderList rl)
{
	nodeRC* tmp = rl.head;
	int y = 1;
	displaytree(rl.head, y);
}


//danh sach doc gia
void ReaderTable(ReaderList& rl)
{
	for (int i = 10; i <= 120; i++)
	{
		SetBGColor(15);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetBGColor(16);
		SetColor(15);
		for (int j = 4; j < 33; j += 2)
		{
			gotoxy(i, j);
			cout << char(95);
		}
		SetColor(16);
		SetBGColor(15);
		gotoxy(i, 35);
		cout << " ";
	}
	for (int i = 1; i < 35; i++)
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
	SetBGColor(16);
	SetColor(15);
	gotoxy(17, 1);
	cout << "ID";
	gotoxy(45, 1);
	cout << "FIRST NAME";
	gotoxy(72, 1);
	cout << "LAST NAME";
	gotoxy(90, 1);
	cout << "GENDER";
	gotoxy(108, 1);
	cout << "STATUS";

	DisplayReader(rl);

	SetBGColor(15);
	SetColor(16);
	for (int i = 130; i <= 138; i++)
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
	gotoxy(132, 4);
	cout << "ADD";
	gotoxy(131, 8);
	cout << "DELETE";
	gotoxy(132, 12);
	cout << "SET";

	HighLight(130, 3, 8);

	while (true)
	{
		// nhan phim tu nguoi dung(up/down/enter)
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		if (c == 27)//khi nguoi dung nhan esc
		{
			system("cls");
			break;
		}
		if (c == 72)//khi nguoi dung nhan UP
		{
			if (wherey() == 3)
			{
				UnHighLight(wherex(), wherey(), 8);
				gotoxy(130, 11);
				HighLight(wherex(), wherey(), 8);
			}
			else
			{
				UnHighLight(wherex(), wherey(), 8);
				gotoxy(130, wherey() - 4);
				HighLight(wherex(), wherey(), 8);
			}
		}
		else if (c == 80)//khi nguoi dung nhan Down
		{
			if (wherey() == 11)
			{
				UnHighLight(wherex(), wherey(), 8);
				gotoxy(130, 3);
				HighLight(wherex(), wherey(), 8);

			}
			else
			{
				UnHighLight(wherex(), wherey(), 8);
				gotoxy(130, wherey() + 4);
				HighLight(wherex(), wherey(), 8);
			}
		}
		else if (c == 13)//Khi nguoi dung nhan ENTER
		{
			SetBGColor(16);
			if (wherey() == 3)
			{
				system("cls");
				tableEnterRC(rl);
				system("cls");
				break;
			}
			else if (wherey() == 7)
			{
				system("cls");
				break;
			}
			else
			{
				system("cls");
				break;
			}
		}
		else
		{
			continue;
		}
	}
}

void tableEnterTOC(TableOfContentList& tl)
{
	TableOfContent* p = new TableOfContent;
	SetColor(15);
	int x = 10, y = 2, width = 120, height = 80;
	gotoxy(x + width / 3, y + height / 4);
	cout << "GENDER: 1 FOR MALE & 2 FOR FEMALE !\n ";
	gotoxy(x + width / 3, y + height / 4 + 1);
	cout << "STATUS: 0(LOCKED) & 1(UNLOCKED)";
	for (int i = x + width / 6; i < x + width * 5 / 6; i++)
	{
		SetBGColor(15);
		gotoxy(i, y + 8);
		cout << " ";
		gotoxy(i, y + 10);
		cout << " ";
		gotoxy(i, y + 12);
		cout << " ";
	}
	SetBGColor(16);
	gotoxy(x + width / 6, y + 9);
	cout << " | NAME |";
	gotoxy(x + width / 6 + 18, y + 9);
	cout << "| GENRE | ";
	gotoxy(x + width / 6 + 28, y + 9);
	cout << " | AUTHOR | ";
	gotoxy(x + width / 6 + 45, y + 9);
	cout << " | NUMBER PAGE | ";
	gotoxy(x + width / 6 + 64, y + 9);
	cout << " | PUBLIC YEAR | ";


	gotoxy(x + width / 6 + 1, y + 11);
	p->BookName = EnterFirstName();
	gotoxy(x + width / 6 + 18, y + 11);
	p->Genre = EnterFirstName();
	gotoxy(x + width / 6 + 28, y + 11);
	p->Author = EnterFirstName();
	gotoxy(x + width / 6 + 47, y + 11);
	p->NumOfPage = enterNumOfPage();
	gotoxy(x + width / 6 + 62, y + 11);
	p->PublicYear = enterNumOfPage();

	gotoxy(x + width / 3, y + 15);
	if (addTableOfContent(tl, *p) == 1) cout << "add successful";
	else cout << "can not add";
	Sleep(1500);
}

//dieu khien tren menu chinh
void Control(ReaderList& rl, TableOfContentList& tl)
{
	int x = 20; int y = 2; int width = 120; int height = 30;
	//danh dau lua chon dau
	gotoxy(x + width / 3 - 6, y + height / 4 - 1);

	HighLight(wherex(), wherey(), width / 3);
	while (true)
	{
		// nhan phim tu nguoi dung(up/down/enter)
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		if (c == 27) continue;
		else if (c == 72)//khi nguoi dung nhan UP
		{
			if (wherey() == y + height / 4 - 1)
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x + width / 3 - 6, y + height / 4 + 20 - 1);
				HighLight(wherex(), wherey(), width / 3);

			}
			else
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x + width / 3 - 6, wherey() - 4);
				HighLight(wherex(), wherey(), width / 3);
			}
		}
		else if (c == 80)//khi nguoi dung nhan Down
		{
			if (wherey() == y + height / 4 + 20 - 1)
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x + width / 3 - 6, y + height / 4 - 1);
				HighLight(wherex(), wherey(), width / 3);

			}
			else
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x + width / 3 - 6, wherey() + 4);
				HighLight(wherex(), wherey(), width / 3);
			}
		}
		else if (c == 13)//Khi nguoi dung nhan ENTER
		{
			SetBGColor(16);
			if (wherey() == y + height / 4 + 20 - 1)//Quit
			{
				system("cls");
				break;
			}
			else if (wherey() == y + height / 4 + 16 - 1)//option 5
			{
				system("cls");
				boxMenu();
				Control(rl, tl);
				break;
			}
			else if (wherey() == y + height / 4 - 1)//option 1
			{
				system("cls");
				ReaderTable(rl);
				system("cls");
				boxMenu();
				Control(rl, tl);
				break;
			}
			else if (wherey() == y + height / 4 + 4 - 1)//option 2
			{
				system("cls");
				boxMenu();
				Control(rl, tl);
				break;
			}
			else if (wherey() == y + height / 4 + 8 - 1)//option 3
			{
				system("cls");
				tableEnterTOC(tl);
				system("cls");
				boxMenu();
				Control(rl, tl);
				break;
			}
			else if (wherey() == y + height / 4 + 12 - 1)//option 4;
			{
				system("cls");
				boxMenu();
				Control(rl, tl);
				break;
			}
		}
		else
		{
			continue;
		}
	}
}


int main()
{
	ReaderList rl;
	TableOfContentList tl;

	DisableSelection();
	resizeConsole(1200, 600);
	DisableCtrButton(0, 1, 1);
	DisableResizeWindow();
	loading();
	boxMenu();
	Control(rl, tl);

	return 0;
}