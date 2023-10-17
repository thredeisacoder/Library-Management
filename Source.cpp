#include "mylib.h"
#include "struct.h"
#include "process.h"
#include <fstream>
using namespace std;

void title(int x, int y) {
	string s[19];
	string a[13];
	a[1] = " __       __   ______    ______         ___       ______   ____    ____ ";
	a[2] = "|  |     |  | |   _  |  |   _  |       /   |     |   _  |  |   |  /   / ";
	a[3] = "|  |     |  | |  |_)  | |  |_)  |     /  ^  |    |  |_)  |  |   |/   /  ";
	a[4] = "|  |     |  | |   _  <  |      /     /  /_|  |   |      /    |_    _/   ";
	a[5] = "|  `----.|  | |  |_)  | |  ||  |-.  /  _____  |  |  ||  |-.    |  |     ";
	a[6] = "|_______||__| |______/  | _| `.__| /__/     |__| | _| `.__|    |__|     ";
	a[7] = " 				                                                             _  ";
	a[8]  = "				 _ __ ___   __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_";
	a[9]  = "				| '_ ` _ | / _` | '_ | / _` |/ _` |/ _ | '_ ` _  |/ _ | '_ || __|";
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
	//draw logo
	for(int i = 1; i <= 12; i++){
		SetColor(i);
		gotoxy(x,y + 1 + i);
		cout << a[i];
	}
	//draw book
	for(int i = 1; i <= 18; i++){
		SetColor(i);
		gotoxy(x + 35, 19 + i);
		cout << s[i];
	}
}
// man hinh loading
void loading()
{
	Sleep(1000);
/*	string logo[34];
	logo[0] = "                                                                      ";
	logo[1] = "                                                                      ";
	logo[2] = "                                                                      ";
	logo[3] = "                                                                      ";
	logo[4] = "                                     .^!7777!~:.                      ";
	logo[5] = "                                  ^7YYYYYY55PPPY!                     ";
	logo[6] = "                              .^!JJ!^.     .~?5PP?                    ";
	logo[7] = "                            :~77~.            ^YPP^                   ";
	logo[8] = "                          .!!~:                :5P!                   ";
	logo[9] = "                         ~?:.                   7P~                   ";
	logo[10] = "                       .??.                     ~P:                   ";
	logo[11] = "                      ^Y7                       !J                    ";
	logo[12] = "                     ~P7                        J^                    ";
	logo[13] = "                    !P?                     .  :7                     ";
	logo[14] = "                   7PY.                    :^  ~.                     ";
	logo[15] = "                  ~PP~ ......  ........ . :7: :^::::::                ";
	logo[16] = "                 .YPY  ?5J??YY!!JJ55JJ!.~~~~^.:??Y5J??.               ";
	logo[17] = "                 7PP7  JP~  ^P5.  Y5.  :~!!:     !P~                  ";
	logo[18] = "                .YPP^  JPYJJYJ~   Y5. ..^!Y~     !P~                  ";
	logo[19] = "                ^P5P^  JP~...     Y5.  !Y7GJ     7G~                  ";
	logo[20] = "                !P5P~  7Y^        ?J.^JPY~Y7     ~Y^                  ";
	logo[21] = "                ~P5PJ             .~JPPJ:                             ";
	logo[22] = "                .5PPP!          ^75PPJ^                               ";
	logo[23] = "                 :J5PP?^    .^7YPPY7:                                 ";
	logo[24] = "                  .~?JJJ7!7J5P5J!:                                    ";
	logo[25] = "                    :~!?JJJ?!^.                                       ";
	logo[26] = "              :7777777777777777777!7777777777777777777~               ";
	logo[27] = "              :YYYYYYYYYYYYYYYYYYY7YYYYYYYYYYYYYYYYYYY7               ";
	logo[28] = "               .......           .::.          .......                ";
	logo[29] = "                                                                      ";
	logo[30] = "                                                                      ";*/
	string s = " POSTS AND TELECOMMUNICATIONS INSTITUTE OF TECHNOLOGY! ";
	/*for (int i = 1; i < 34; i++) {
		cout << "\t\t\t\t\t";
		SetColor(20);
		cout << logo[i] << endl;
	}*/
	printlogo();
	for (unsigned int i = 0; i < s.length() - 1; i++)
	{
		SetColor(16);
		gotoxy(80 + i, 30);
		cout << s[i];
		SetBGColor(15);
		gotoxy(80 + 2*i-5, 31);
		cout << "  ";
		gotoxy(80 + 2*i-5, 31);
		cout << "  ";
		SetBGColor(15);
		Sleep(75);
	}

	Sleep(2000);
	system("cls");
}

//Khung tieu de
void Tittle(int x, int y, int width, int height)
{
	for (int i = x ; i <= x + width - 8; i++)//so cot 
	{
		for (int j = y - 4; j <= y + height / 3; j++)//to tung o cua tung cot
		{
			SetBGColor(15);//mau nen trang
			gotoxy(i, j);
			cout << " ";//to mau trang cho khung tieu de
		}
	}
	SetColor(20);//chu mau xanh
	title(x + 30, y - 4);
}

//in lua chon
void Option(int x, int y, int width, int height, string option)
{
	for (int i = x - 6; i <= x + width ; i++)//vong lap chay tu dau den het chieu dai option
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

//tao menu
void boxMenu()
{
	int x = 8;
	int y = 13;
	int width = 150;
	int height = 30;
	if (width <= 1 || height <= 1) return;
	Tittle(x, y - 9, width, height);
	Option(x , y + height / 4, width / 3 - 6, height, "READER CARD!");//chua chinh
	Option(x , y + height / 4 + 4, width / 3 - 6, height, "TABLE OF CONTENT");//chua chinh
	Option(x , y + height / 4 + 8, width/ 3 - 6, height, "BORROW AND RETURN!");//chua chinh
	Option(x , y + height / 4 + 12, width/ 3 - 6, height, "STATISTIC");//chua chinh
	Option(x , y + height / 4 + 16, width/ 3 - 6, height, "UPDATE INFORMATION!");//chua chinh
	Option(x , y + height / 4 + 20, width/ 3 - 6, height, "QUIT!");//chua chinh

	gotoxy(x + width / 6 + 48, y + height * 5 / 6);
	cout << "Press Up and Down to move and Enter to choose!!! ";

}

// bat thanh sang
void HighLight(int x, int y, int width)
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

//tat thanh sang
void UnHighLight(int x, int y, int width)
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

//nhap doc gia moi
void tableEnterRC(ReaderList& rl)
{
	Reader* p = new Reader;
	SetColor(16);
	int x = 10, y = 2, width = 120, height = 80;
	gotoxy(x , y + height / 4);
	cout << "GENDER: 1 FOR MALE OR 2 FOR FEMALE !";
	gotoxy(x , y + height / 4 + 1);
	cout << "STATUS: 0(LOCKED) OR 1(UNLOCKED)";
	for (int i = x + width / 6; i < x + width * 5 / 6; i++)
	{
		SetBGColor(14);
		gotoxy(i, y + 8);
		cout << " ";
		gotoxy(i, y + 10);
		cout << " ";
		gotoxy(i, y + 12);
		cout << " ";
	}
	SetBGColor(15);
	gotoxy(x + width / 6 + 1, y + 9);
	cout << "| FIRST NAME | ";
	gotoxy(x + width / 6 + 25, y + 9);
	cout << " | LAST NAME | ";
	gotoxy(x + width / 6 + 45, y + 9);
	cout << " | GENDER | ";
	gotoxy(x + width / 6 + 60, y + 9);
	cout << " | STATUS | ";

	gotoxy(x + width / 6 + 62, y + 11);
	cout << p->CardStatus;
	gotoxy(x + width / 6 + 1, y + 11);
	p->FirstName = EnterFirstName(p->FirstName);
	gotoxy(x + width / 6 + 28, y + 11);
	p->LastName = EnterLastName(p->LastName);
	gotoxy(x + width / 6 + 47, y + 11);
	p->Gender = EnterGender(p->Gender);

	gotoxy(x , y + 15);
	int n = addNodeReader(rl, *p);
	if (n == 1)	cout << "~ADD Successfully~";
	else cout << "Can not add";
	delete p;
	gotoxy(x , y + 16);
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
void displaytree(nodeRC* head, int& y)
{
	if (head == nullptr) return;
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
		SetBGColor(14);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetColor(16);
		for (int j = 4; j < 3 + 2 * rl.size; j += 2)
		{
			gotoxy(i, j);
			cout << char(95);
		}
		gotoxy(i, 3 + 2 * rl.size);
		cout << " ";
	}
	for (int i = 1; i < 3 + 2 * rl.size; i++)
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
	cout << "FIRST NAME";
	gotoxy(72, 1);
	cout << "LAST NAME";
	gotoxy(90, 1);
	cout << "GENDER";
	gotoxy(108, 1);
	cout << "STATUS";

	int y = 3;
	displaytree(rl.head, y);

	SetBGColor(11);
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

	SetBGColor(15);
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
			SetBGColor(15);
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
					gotoxy(125, 20);
					cout << "EMPTY!!!\n";
					system("pause");
					system("cls");
					ReaderTable(rl);
					break;
				}

				gotoxy(132, 20);
				SetColor(20);
				cout << "enter id to delete: ";
				string s = "";
				s= EnterID(s);
				int n = deleteNodeReader(rl, s);
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
	SetColor(16);
	int x = 10, y = 2, width = 120, height = 80;
	gotoxy(x , y + height / 4);
	cout << "Limit input characters of each category:\n ";//hdsd
	gotoxy(x , y + height / 4 + 1);
	cout << "Name - 34 chars";//hdsd
	gotoxy(x , y + height / 4 + 2);
	cout << "Genre - 15 chars";//hdsd
	gotoxy(x , y + height / 4 + 3);
	cout << "Author - 32 chars";//hdsd
	gotoxy(x , y + height / 4 + 4);
	cout << "Number Page - 5 chars";//hdsd
	gotoxy(x , y + height / 4 + 5);
	cout << "Public Year - 4 chars";//hdsd
	for (int i = x; i < x + width + 10; i++)
	{
		SetBGColor(14);
		gotoxy(i, y + 8);
		cout << " ";
		gotoxy(i, y + 10);
		cout << " ";
		gotoxy(i, y + 12);
		cout << " ";
	}
	SetBGColor(15);
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
	p->BookName = EnterFirstName(p->BookName);
	gotoxy(x + width - 79, y + 11);
	p->Genre = EnterGenre(p->Genre);
	gotoxy(x + width - 59, y + 11);
	p->Author = EnterAuthor(p->Author);
	gotoxy(x + width - 20, y + 11);
	p->NumOfPage = enterNumPage(p->NumOfPage);
	gotoxy(x + width - 2, y + 11);
	p->PublicYear = enterYear(p->PublicYear);
	int n = themTheoThuTuTheLoai(tl, *p);
	if(n == 1){
		gotoxy(x , 20);
		cout << "~ADD SUCCESSFULL!!!~";
	}else{
		gotoxy(x , 20);
		cout << "~ADD FAILURE!!!~";
	}
	gotoxy(x , y + 15);
	Sleep(1500);
}
void displayTOC(TableOfContent data, int& yTOC) {
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
	for (int i = 0; i < tl.size; i++) {
		displayTOC(*tl.ds[i], yTOC);
		yTOC += 2;
	}
}

void filterBySearching(TableOfContentList& tl, string input)
{
	TableOfContentList l = saveToSearch(tl, input);
	for (int i = 0; i <= 124; i++)//chạy theo chiều dài, trái -> phải
	{
		SetBGColor(14);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetColor(0);
		for (int j = 4; j < 3 + 2 * l.size; j += 2)//có bao nhiêu thg in ra từ trên xuống dưới
		{
			gotoxy(i, j);
			cout << char(95);//in ra dấu gạch ngang ngăn cách từng hàng
		}
		gotoxy(i, 3 + 2 * l.size);
		cout << " ";
	}
	for (int i = 1; i < 3 + 2 * l.size; i++)//vẽ cột ngăn cách từng mục 
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
	if (l.size == 0) {
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
	loadList(l);
	SetBGColor(11);
	SetColor(0);
}
void TableTOC(TableOfContentList& tl)
{
	for (int i = 0; i <= 124; i++)//chạy theo chiều dài, trái -> phải
	{
		SetBGColor(14);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetColor(0);
		for (int j = 4; j < 3 + 2 * tl.size; j += 2)//có bao nhiêu thg in ra từ trên xuống dưới
		{
			gotoxy(i, j);
			cout << char(95);//in ra dấu gạch ngang ngăn cách từng hàng
		}
		gotoxy(i, 3 + 2 * tl.size);
		cout << " ";
	}
	for (int i = 1; i < 3 + 2 * tl.size; i++)//vẽ cột ngăn cách từng mục 
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
	if (tl.size == 0) {
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
	loadList(tl);
	SetBGColor(11);
	SetColor(0);
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
			SetBGColor(15);
			if (wherey() == 3)
			{
				system("cls");
				tableEnterTOC(tl);
				system("cls");
				TableTOC(tl);
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
				cout << "Enter BookName: ";
				string inputSearch="";
				inputSearch = EnterFirstName(inputSearch);
				system("cls");
				filterBySearching(tl, inputSearch);
				gotoxy(120, 20);
				system("pause");
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
	int x = 8; int y = 13; int width = 150; int height = 30;
	//danh dau lua chon dau
	gotoxy(x - 6, y + height / 4 - 1);

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
				gotoxy(x  - 6, y + height / 4 + 20 - 1);
				HighLight(wherex(), wherey(), width / 3);

			}
			else
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x  - 6, wherey() - 4);
				HighLight(wherex(), wherey(), width / 3);
			}
		}
		else if (c == 80)//khi nguoi dung nhan Down
		{
			if (wherey() == y + height / 4 + 20 - 1)
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x  - 6, y + height / 4 - 1);
				HighLight(wherex(), wherey(), width / 3);

			}
			else
			{
				UnHighLight(wherex(), wherey(), width / 3);
				gotoxy(x  - 6, wherey() + 4);
				HighLight(wherex(), wherey(), width / 3);
			}
		}
		else if (c == 13)//Khi nguoi dung nhan ENTER
		{
			SetBGColor(15);
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
	SetBGColor(0);
	ShowCur(1);
	resizeConsole(1300, 750);
	ReaderList rl;
	TableOfContentList tl;
	int n = loadFileReader(rl);
	int m = loadFileTOC(tl);
	if (n == 0 || m == 0)
	{
		cout << "CAN'T LOAD FILE\n";
		system("pause");
		return 0;
	}
	DisableSelection();
	DisableCtrButton(0, 1, 1);
	DisableResizeWindow();
//	loading();
	SetBGColor(15);
	boxMenu();
	Control(rl, tl);
	n = saveFileReader(rl);
	m = saveTOC(tl);
	if (n == 0||m==0)
	{
		cout << "CAN'T SAVE!!!\n";
		boxMenu();
		Control(rl, tl);
	}
	delete rl.head;
	releaseMemory(tl);
	return 0;
}
