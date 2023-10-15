#include "mylib.h"
#include "struct.h"
#include "process.h"

using namespace std;

void title(int x,int y) {
	string s1="\t  _       _  _                                            \n";
	string s2="\t | |     |_|| |                                           \n";
	string s3="\t | |      _ | | ______  _  __  _______  _  __  _   _     \n";
	string s4="\t | |     | || |/_/__| || |/__|/ /__ | || |/__|| | | |    \n";
	string s5="\t | |____ | || || (_)| || |    |_|(_)| || |    | |_| |    \n";
	string s6="\t |_|____||_||_||_|__/_/|_|    |_|___/_||_|     \\\\_/     \n";
	string s7="\t                                                 /_/      \n";
	gotoxy(x, y + 1);
	cout << s1;
	gotoxy(x, y + 2);
	cout << s2;
	gotoxy(x, y + 3);
	cout << s3;
	gotoxy(x, y + 4);
	cout << s4;
	gotoxy(x, y + 5);
	cout << s5;
	gotoxy(x, y + 6);
	cout << s6;
	gotoxy(x, y + 7);
	cout << s7;
}

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
void Tittle(int x, int y, int width, int height)
{
	for (int i = x + width / 6; i <= x + width * 5 / 6 - 12; i++)//so cot 
	{
		for (int j = y - 4; j <= y + height / 6 - 1; j++)//to tung o cua tung cot
		{
			SetBGColor(15);//mau nen trang
			gotoxy(i, j);
			cout << " ";//to mau trang cho khung tieu de
		}
	}
		SetColor(20);//chu mau xanh
		title(x + 35, y - 5);
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
	int x =8;
	int y = 4;
	int width = 150;
	int height = 30;

	if (width <= 1 || height <= 1) return;
	Tittle(x, y, width, height);
	Option(x + width / 3, y + height / 4, width, height, "READER CARD!");
	Option(x + width / 3, y + height / 4 + 4, width, height, "TABLE OF CONTENT");
	Option(x + width / 3, y + height / 4 + 8, width, height, "BORROW AND RETURN!");
	Option(x + width / 3, y + height / 4 + 12, width, height, "STATISTIC");
	Option(x + width / 3, y + height / 4 + 16, width, height, "UPDATE INFORMATION!");
	Option(x + width / 3, y + height / 4 + 20, width, height, "QUIT!");

	//in 2 canh ben cua khung menu
	for (int i = y - 4; i <= y + height + 2; i++)
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
	gotoxy(x + width / 6 + 20, y + height * 5 / 6 + 6);
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
			SetBGColor(3);
			gotoxy(i, j);
			cout << " ";
			if (i == x || i == x + width-1)
			{
				gotoxy(i, y +1);
				cout << "  ";
			}
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
			if (i == x || i == x + width-1)
			{
				gotoxy(i, y + 1);
				cout << "  ";
			}
		}
	}
	SetBGColor(16);
	gotoxy(x, y);

}

//nhap doc gia moi
void tableEnterRC(ReaderList& rl)
{
	Reader* p=new Reader;
	SetColor(15);
	int x = 10, y = 2, width = 120, height = 80;
	gotoxy(x + width / 3, y + height / 4);
	cout << "GENDER: 1 FOR MALE OR 2 FOR FEMALE !";
	gotoxy(x + width / 3, y + height / 4 + 1);
	cout << "STATUS: 0(LOCKED) OR 1(UNLOCKED)";
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
	cout << "| FIRST NAME | ";
	gotoxy(x + width / 6 + 25, y + 9);
	cout << " | LAST NAME | ";
	gotoxy(x + width / 6 + 45, y + 9);
	cout << " | GENDER | ";
	gotoxy(x + width / 6 + 60, y + 9);
	cout << " | STATUS | ";

	gotoxy(x + width / 6 + 62, y + 11);
	cout << p->CardStatus ;
	gotoxy(x + width / 6 + 1, y + 11);
	p->FirstName = EnterFirstName();
	gotoxy(x + width / 6 + 28, y + 11);
	p->LastName = EnterLastName();
	gotoxy(x + width / 6 + 47, y + 11);
	p->Gender = EnterGender();

	gotoxy(x + width / 3, y + 15);
	int n = addNodeReader(rl, *p);
	if (n == 1)	cout << "~ADD Successfully~";
	else cout << "Can not add";
	delete p;
	gotoxy(x + width / 3, y + 16);
	Sleep(1000);
}
//in 1 doc gia
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
//duyet danh sach doc gia
void displaytree(nodeRC* head, int &y)
{
	if (head == NULL) return;
	else
	{
		displayReader(head, y);
		y += 2;
		displaytree(head->left, y);
		displaytree(head->right, y);
	}
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

	int y = 3;
	displaytree(rl.head, y);

	SetBGColor(15);
	SetColor(16);
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
	cout << "SET";
	SetColor(15);

	HighLight(130, 3, 9);

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
		else if (c == 80)//khi nguoi dung nhan Down
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
		else if (c == 13)//Khi nguoi dung nhan ENTER
		{
			SetBGColor(16);
			if (wherey() == 3)
			{
				system("cls");
				tableEnterRC(rl);
				system("cls");
				ReaderTable(rl);
				system("cls");
				break;
			}
			else if (wherey() == 7)
			{
				if (rl.size == 0)
				{
					system("cls");
					cout << "empty list!!!";
					system("pause");
					ReaderTable(rl);
					break;
				}
				system("cls");
				SetColor(20);
				cout << "enter id to delete: ";
				string s = EnterID();
				int n=deleteNodeReader(rl, s);
				if (n == 0) cout << "can not delete";
				else cout << "successful";
				system("pause");
				ReaderTable(rl);
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

//danh sach dau sach
void tableEnterTOC(TableOfContentList& tl)
{
	TableOfContent* p = new TableOfContent;
	SetColor(15);
	int x = 10, y = 2, width = 120, height = 80;
	gotoxy(x + width / 3, y + height / 4);
	cout << "GENDER: 1 FOR MALE & 2 FOR FEMALE !\n ";//hdsd
	gotoxy(x + width / 3, y + height / 4 + 1);
	cout << "STATUS: 0(LOCKED) & 1(UNLOCKED)";//hdsd
	for (int i = x; i < x + width + 10; i++)
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
	gotoxy(x + 17, y + 9);
	cout << "| NAME |";
	gotoxy(x + width - 79, y + 9);
	cout << "| GENRE | ";
	gotoxy(x + width - 49, y + 9);
	cout << "| AUTHOR | ";
	gotoxy(x + width - 23, y + 9);
	cout << "| NUMBER PAGE | ";
	gotoxy(x + width - 6, y + 9);
	cout << "| PUBLIC YEAR | ";


	gotoxy(x + 3, y + 11);
	p->BookName = EnterFirstName();
	gotoxy(x + width - 79, y + 11);
	p->Genre = EnterGenre();
	gotoxy(x + width - 59, y + 11);
	p->Author = EnterAuthor();
	gotoxy(x + width - 20, y + 11);
	p->NumOfPage = enterNumPage();
	gotoxy(x + width - 2, y + 11);
	p->PublicYear = enterYear();

	gotoxy(x + width / 3, y + 15);
	if (addTableOfContent(tl, *p) == 1) cout << "add successful";
	else cout << "can not add";
	Sleep(1500);
}
void displayTOC(TableOfContent data, int &yTOC){
	gotoxy(2, yTOC);
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
void loadList(TableOfContentList tl) {
	int yTOC = 3; //chiều cao hàng đầu tiên
	for (int i = 0; i < tl.size; i++){
		displayTOC(*tl.ds[i], yTOC);
		yTOC+=2;
	}
}
void TableTOC(TableOfContentList& tl)
{
	for (int i = 0; i <= 124; i++)//chạy theo chiều dài, trái -> phải
	{
		SetBGColor(15);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetBGColor(16);
		SetColor(15);
		for (int j = 4; j < 4 + 2 * tl.size; j += 2)//có bao nhiêu thg in ra từ trên xuống dưới
		{
			gotoxy(i, j);
			cout << char(95);//in ra dấu gạch ngang ngăn cách từng hàng
		}
		SetColor(16);
		SetBGColor(15);
		gotoxy(i, 4 + 2 * tl.size);
		cout << " ";
	}
	for (int i = 1; i < 4 + 2 * tl.size; i++)//vẽ cột ngăn cách từng mục 
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
	if(tl.size == 0){
		gotoxy(60, 25);
		cout << "Empty!!!";
	}
	SetBGColor(16);
	SetColor(15);
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
	loadList(tl);

	SetBGColor(15);
	SetColor(16);
	for (int i = 130; i <= 139; i++)//in ra ô chức năng
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
	gotoxy(133, 8);
	cout << "EDIT";
	gotoxy(132, 12);
	cout << "SEARCH";

	HighLight(130, 3, 9);

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
		else if (c == 80)//khi nguoi dung nhan Down
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
		else if (c == 13)//Khi nguoi dung nhan ENTER
		{
			SetBGColor(16);
			if (wherey() == 3)
			{
				system("cls");
				tableEnterTOC(tl);
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

//dieu khien tren menu chinh
void Control(ReaderList& rl, TableOfContentList& tl)
{
	int x = 8; int y = 4; int width = 150; int height = 30;
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
				TableTOC(tl);
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
	resizeConsole(1200, 650);
	DisableCtrButton(0, 1, 1);
	DisableResizeWindow();
	//loading();
	boxMenu();
	Control(rl, tl);

	return 0;
}
