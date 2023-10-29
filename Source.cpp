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

	string s = "          POSTS AND TELECOMMUNICATIONS INSTITUTE OF TECHNOLOGY! ";

	printlogo();
	for (unsigned int i = 0; i < s.length() - 1; i++)
	{
		SetColor(15);
		gotoxy(80 + i, 30);
		cout << s[i];
		Sleep(60);
	}
	
	for(int i=0;i<70;i++)
	{
		SetBGColor(15);
		gotoxy(80 + 3/2*i, 31);
		cout << " ";
		gotoxy(80 + 3/2*i, 32);
		cout << " ";
		SetBGColor(15);
		Sleep(60);
	}

	Sleep(1500);
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
	Option(x + 10, y + height / 5 , width / 3 - 6, height, "READER CARD!");//chua chinh
	Option(x + 10, y + height / 5 + 4, width / 3 - 6, height, "TABLE OF CONTENT");//chua chinh
	Option(x + 10, y + height / 5 + 8, width/ 3 - 6, height, "BORROW AND RETURN!");//chua chinh
	Option(x + 10, y + height / 5 + 12, width/ 3 - 6, height, "STATISTIC");//chua chinh
	Option(x + 10, y + height / 5 + 16, width/ 3 - 6, height, "UPDATE INFORMATION!");//chua chinh
	Option(x + 10, y + height / 5 + 20, width/ 3 - 6, height, "QUIT!");//chua chinh

	gotoxy(x + width / 6 + 48, y + height * 5 / 6);
	cout << "Press Up and Down to move and Enter to choose!!! ";

}

void HighLight(int x, int y, int width)//bat thanh sang
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
void UnHighLight(int x, int y, int width)//tat thanh sang
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

void Tick(int x,int y)//danh dau
{
	SetBGColor(20);
	cout<<"  ";
	gotoxy(x,y);
	SetBGColor(15);
}
void UnTick(int x,int y)//huy danh dau
{
	SetBGColor(15);
	cout<<"  ";
	gotoxy(x,y);
}

void clearReaderLine(int i)
{
	gotoxy(6,i);
	cout<<"   ";
	gotoxy(14, i);
	for(int j=14;j<30;j++) cout << " ";
	gotoxy(35, i);
	for(int j=35;j<65;j++) cout << " ";
	gotoxy(70, i);
	for(int j=70;j<85;j++) cout << " ";
	gotoxy(90, i);
	for(int j=90;j<100;j++) cout << " ";
	gotoxy(105,i);
	for(int j=105;j<120;j++) cout << " ";
}

void clearReaderTable()
{
	for (int i = 3; i <  3+ 2 * 20; i+=2)
	{
		clearReaderLine(i);
	}
}

//in 1 doc gia
void displayReader(nodeRC* p, int y)//in doc gia tren do cao y
{
	while(y>=20)
	{
		y-=20;
	}
	gotoxy(14, 3+2*y);
	cout << p->data.ID;
	gotoxy(35, 3+2*y);
	cout << p->data.FirstName;
	gotoxy(70, 3+2*y);
	cout << p->data.LastName;
	gotoxy(90, 3+2*y);
	cout << p->data.Gender;
	gotoxy(105,3+2*y);
	int s= p->data.CardStatus;
	if(s==1) cout<<"1 (activated)";
	else if(s==0) cout<<"0 (locked)";
}
void sortbyID(nodeRC* tmp[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(tmp[i]->data.ID>tmp[j]->data.ID)
			{
				swap(tmp[i],tmp[j]);
			}
		}
	}
}

//nhap doc gia moi
void tableEnterRC(ReaderList& rl)
{
	ShowCur(true);
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
	if(p->FirstName=="")
	{
		delete p;
		return ;
	}
	gotoxy(x + width / 6 + 28, y + 11);
	p->LastName = EnterLastName(p->LastName);
	if(p->LastName=="")
	{
		delete p;
		return ;
	}
	gotoxy(x + width / 6 + 47, y + 11);
	p->Gender = EnterGender(p->Gender);
	if(p->Gender=="")
	{
		delete p;
		return ;
	}
	ShowCur(false);
	gotoxy(x , y + 15);
	int n = addNodeReader(rl, *p);
	if (n == 1)	cout << "~ADD Successfully~";
	else cout << "Can not add";
	delete p;
	gotoxy(x , y + 16);
	Sleep(1000);
}

void tableSettingRC(nodeRC* p,int y)//chinh sua thong tin doc gia
{
	ShowCur(true);
	SetColor(16);
	Reader* data=new Reader(p->data);
	gotoxy(6,wherey());
	SetColor(20);
	cout<<"->>";
	SetColor(16);


	gotoxy(35, y);
	data->FirstName = EnterFirstName(p->data.FirstName);
	if(data->FirstName=="")
	{
		delete data;
		clearReaderLine(y);
		displayReader(p,(y-3)/2);
		return;
	}
	gotoxy(70,y);
	data->LastName = EnterLastName(p->data.LastName);
	if(data->LastName=="")
	{
		delete data;
		clearReaderLine(y);
		displayReader(p,(y-3)/2);
		return;
	}
	gotoxy(90, y );
	data->Gender = EnterGender(p->data.Gender);
	if(data->Gender=="")
	{
		delete data;
		clearReaderLine(y);
		displayReader(p,(y-3)/2);
		return;
	}
	gotoxy(105, y);
	data->CardStatus=EnterStatus(p->data.CardStatus);
	if(data->CardStatus==-1)
	{
		delete data;
		clearReaderLine(y);
		displayReader(p,(y-3)/2);
		return;
	}
	p->data=*data;
	
	
	clearReaderLine(y);
	displayReader(p,(y-3)/2);
	ShowCur(false);
	Sleep(1000);
}
//sap xep theo ten
void sortbyname(nodeRC* tmp[],int n)
{
	for(int i=0;i<n;i++)
	{
		string s1=tmp[i]->data.LastName+tmp[i]->data.FirstName;
		for(int j=i+1;j<n;j++)
		{
			string s2=tmp[j]->data.LastName+tmp[j]->data.FirstName;
			if(s1 >s2)
			{
				swap(tmp[i],tmp[j]);
			}
		}
	}
}
//duyet danh sach doc gia
void displaytree(nodeRC* tmp[],int n,int count)//duyet mang de in ra 
{
	gotoxy(2,1);
	cout<<"       ";
	int y=0;
	for(int i=count-20;i<count;i++)
	{
		if(i==n) break;
		displayReader(tmp[i],y);
		y++;
	}

	gotoxy(2,1);
	cout<<count/20<<"/"<<n/20+1;
}

void tranvertree(nodeRC* head,nodeRC* tmp[],int& n)//duyet cay dua vao mang con tro tmp
{
	if (head == nullptr) return;
	else
	{
		tmp[n]=head;
		n++;
		tranvertree(head->left,tmp,n);
		tranvertree(head->right,tmp,n);
	}
}


int selectDisplayMode()
{
	SetColor(0);
	Option(70,21,30,3,"Sort By ID!!");

	Option(70,26,30,3,"Sort By Name!!");

	HighLight(64,20,36);

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
			return 0;
		}
		else if (c == 72)//khi nguoi dung nhan UP
		{
			if (wherey() == 20)
			{
				UnHighLight(wherex(), wherey(), 36);
				gotoxy(wherex(),wherey()+5);
				HighLight(wherex(), wherey(), 36);
			}
			else
			{
				UnHighLight(wherex(), wherey(), 36);
				gotoxy(wherex(), wherey() - 5);
				HighLight(wherex(), wherey(), 36);
			}
		}
		else if (c == 80)//khi nguoi dung nhan Down
		{
			if (wherey() == 25)
			{
				UnHighLight(wherex(), wherey(), 36);
				gotoxy(wherex(),wherey()-5);
				HighLight(wherex(), wherey(), 36);
			}
			else
			{
				UnHighLight(wherex(), wherey(), 36);
				gotoxy(wherex(), wherey() + 5);
				HighLight(wherex(), wherey(), 36);
			}
		}
		else if (c == 13)//Khi nguoi dung nhan ENTER
		{
			SetBGColor(15);
			if (wherey() == 20)
			{
				return 1;
			}
			else if (wherey() == 25)
			{
				return 2;
			}
		}
		else
		{
			continue;
		}
	}
	
}

//danh sach doc gia
void ReaderTable(nodeRC* tmp[],int n,int count)
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
	cout << "FIRST NAME";
	gotoxy(72, 1);
	cout << "LAST NAME";
	gotoxy(90, 1);
	cout << "GENDER";
	gotoxy(108, 1);
	cout << "STATUS";

	displaytree(tmp,n,count);
}

void deleteReaderMode(ReaderList& rl,nodeRC* tmp[],int& count)//che do xoa
{
	char c;
	gotoxy(11,3);
	Tick(wherex(),wherey());
	while (true)
	{
		c=_getch();
		if(c==13) //enter
		{
			UnTick(wherex(),wherey());
			int pos=count-20+(wherey()-3)/2;
			string s=tmp[pos]->data.ID;
			deleteNodeReader(rl,s);
			returnIDAfterDelete(s);
			break;
		}
		else if(c==27)//esc
		{
			UnTick(wherex(),wherey());
			break;
		}
		else if(c==80)//down
		{
			if(count>rl.size&&wherey()==3+2*(rl.size-1-(count-20))) 
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),3);
				Tick(wherex(),wherey());
			}
			else if(wherey()!=3+2*19){
				UnTick(wherex(),wherey());
				gotoxy(wherex(),wherey()+2);
				Tick(wherex(),wherey());
			}
			else
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),3);
				Tick(wherex(),wherey());
			}
		}
		else if(c==72)//up
		{
			if(count>rl.size&&wherey()==3) 
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),3+2*(rl.size-1-(count-20)));
				Tick(wherex(),wherey());
			}
			else if(wherey()!=3)
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),wherey()-2);
				Tick(wherex(),wherey());
			}
			else
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),3+2*19);
				Tick(wherex(),wherey());
			}
		}
		else if(c==75)///left
		{
			int y=0;
			if(count==20) continue;
			UnTick(wherex(),wherey());
			count-=20;
			clearReaderTable();
			displaytree(tmp,rl.size,count);
			gotoxy(11,3);
			Tick(wherex(),wherey());
		}
		else if(c==77)//right
		{
			int y=0;
			if(count>=rl.size) continue;
			UnTick(wherex(),wherey());
			count+=20;
			clearReaderTable();
			displaytree(tmp,rl.size,count);
			gotoxy(11,3);
			Tick(wherex(),wherey());
		}
		else
		{
			continue;
		}
	}
}

void SettingReaderMode(ReaderList& rl,nodeRC* tmp[],int& count)//che do chinh sua
{
	char c;
	gotoxy(11,3);
	Tick(wherex(),wherey());
	while (true)
	{
		c=_getch();
		if(c==13) //enter
		{
			UnTick(wherex(),wherey());
			int pos=count-20+(wherey()-3)/2;
			tableSettingRC(tmp[pos],wherey());
			break;
		}
		else if(c==27)//esc
		{
			UnTick(wherex(),wherey());
			break;
		}
		else if(c==80)//down
		{
			if(count>rl.size&&wherey()==3+2*(rl.size-1-(count-20))) 
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),3);
				Tick(wherex(),wherey());
			}
			else if(wherey()!=3+2*19)
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),wherey()+2);
				Tick(wherex(),wherey());
			}
			else
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),3);
				Tick(wherex(),wherey());
			}
		}
		else if(c==72)//up
		{
			if(count>rl.size&&wherey()==3) 
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),3+2*(rl.size-1-(count-20)));
				Tick(wherex(),wherey());
			}
			else if(wherey()!=3)
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),wherey()-2);
				Tick(wherex(),wherey());
			}
			else
			{
				UnTick(wherex(),wherey());
				gotoxy(wherex(),3+2*19);
				Tick(wherex(),wherey());
			}
		}
		else if(c==75)///left
		{
			int y=0;
			if(count==20) continue;
			UnTick(wherex(),wherey());
			count-=20;
			clearReaderTable();
			displaytree(tmp,rl.size,count);
			gotoxy(11,3);
			Tick(wherex(),wherey());
		}
		else if(c==77)//right
		{
			int y=0;
			if(count>=rl.size) continue;
			UnTick(wherex(),wherey());
			count+=20;
			clearReaderTable();
			displaytree(tmp,rl.size,count);
			gotoxy(11,3);
			Tick(wherex(),wherey());
		}
		else
		{
			continue;
		}
	}
}

void controlReaderTable(ReaderList &rl,nodeRC* tmp[],int count)
{
	SetBGColor(11);
	SetColor(0);
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
		else if (c == 72)//khi nguoi dung nhan UP
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
		else if(c==75)///left
		{
			if(count==20) continue;
			UnHighLight(wherex(),wherey(),9);
			count-=20;
			clearReaderTable();
			displaytree(tmp,rl.size,count);
			gotoxy(130,3);
			HighLight(wherex(),wherey(),9);

		}
		else if(c==77)//right
		{
			if(count>=rl.size) continue;
			UnHighLight(wherex(),wherey(),9);
			count+=20;
			clearReaderTable();
			displaytree(tmp,rl.size,count);
			gotoxy(130,3);
			HighLight(wherex(),wherey(),9);
		}
		else if (c == 13)//Khi nguoi dung nhan ENTER
		{
			SetBGColor(15);
			if (wherey() == 3)
			{
				system("cls");
				tableEnterRC(rl);
				system("cls");
				int n=0;
				tranvertree(rl.head,tmp,n);
				sortbyID(tmp,rl.size);
				system("cls");
				ReaderTable(tmp,rl.size,count);
				controlReaderTable(rl,tmp,count);
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
					ReaderTable(tmp,rl.size,count);
					controlReaderTable(rl,tmp,count);
					break;
				}

				gotoxy(132, 20);
				deleteReaderMode(rl,tmp,count);
				int n=0;
				system("cls");
				tranvertree(rl.head,tmp,n);
				sortbyID(tmp,n);
				system("cls");
				ReaderTable(tmp,rl.size,count);
				controlReaderTable(rl,tmp,count);
				system("cls");
				break;
			}
			else
			{
				SettingReaderMode(rl,tmp,count);
				controlReaderTable(rl,tmp,count);
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
	gotoxy(x , y + height / 4 + 6);
	cout << "ISBN - 6 chars";//hdsd
	for (int i = x; i < x + width + 25; i++)
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
	gotoxy(x + width + 10, y + 9);
	cout << "| ISBN | ";


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
	gotoxy(x + width + 10, y + 11);
	p->ISBN = EnterID_ISBN(p->ISBN);
	p->dms = *createBookList();
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
void loadListTOC(TableOfContentList tl, int count) {
	int yTOC = 3; //chiều cao hàng đầu tiên
	for (int i = count - 19; i < count; i++) {
		if(i == tl.size){
			break;
		}
		displayTOC(*tl.ds[i], yTOC);
		yTOC += 2;
	}
}

void filterBySearching(TableOfContentList& tl, int count)
{
	gotoxy(1, 43);
	SetBGColor(20);
	cout << "Enter BookName:";
	SetBGColor(15);
	cout << " ";
	string inputSearch="";
	inputSearch = EnterFirstName(inputSearch);	
	SetBGColor(15);
	system("cls");
	TableOfContentList l = saveToSearch(tl, inputSearch);
	for (int i = 0; i <= 124; i++)//chạy theo chiều dài, trái -> phải
	{
		SetBGColor(6);
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
	loadListTOC(l, count);
	SetBGColor(11);
	SetColor(0);
}
void editTOC(TableOfContentList& tl){
	gotoxy(130, 40);
	cout << "Enter ISBN: ";
	string input = "";
	input = EnterID_ISBN(input);
	TableOfContent* tmp = searchByISBN(tl, input);
	if(tmp == NULL){
		gotoxy(130, 41);
		cout << "ISBN not found!!!!!!";
		Sleep(1000);
		return ;
	}
	SetColor(16);
	system("cls");
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
	for (int i = x; i < x + width + 25; i++)
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
	gotoxy(x + width + 10, y + 9);
	cout << "| ISBN | ";

	gotoxy(x + 3, y + 11);
	tmp->BookName = EnterFirstName(tmp->BookName);
	gotoxy(x + width - 79, y + 11);
	tmp->Genre = EnterGenre(tmp->Genre);
	gotoxy(x + width - 59, y + 11);
	tmp->Author = EnterAuthor(tmp->Author);
	gotoxy(x + width - 20, y + 11);
	tmp->NumOfPage = enterNumPage(tmp->NumOfPage);
	gotoxy(x + width - 2, y + 11);
	tmp->PublicYear = enterYear(tmp->PublicYear);
	gotoxy(x + width + 10, y + 11);
	tmp->ISBN = EnterID_ISBN(tmp->ISBN);
	int n = themTheoThuTuTheLoai(tl, *tmp);
	if(n == 0){
		gotoxy(x , 20);
		cout << "~EDIT SUCCESSFULL!!!~";
	}else{
		gotoxy(x , 20);
		cout << "~EDIT FAILURE!!!~";
	}
	gotoxy(x , y + 15);
	Sleep(1500);
}
void TableTOC(TableOfContentList& tl, int count)
{
	for (int i = 0; i <= 124; i++)//chạy theo chiều dài, trái -> phải
	{
		SetBGColor(6);
		gotoxy(i, 0);
		cout << " ";
		gotoxy(i, 2);
		cout << " ";
		SetColor(0);
		for (int j = 4; j < 3 + 2 * 19; j += 2)//có bao nhiêu thg in ra từ trên xuống dưới
		{
			gotoxy(i, j);
			cout << char(95);//in ra dấu gạch ngang ngăn cách từng hàng
		}
		gotoxy(i, 3 + 2 * 19);
		cout << " ";
	}
	for (int i = 1; i < 3 + 2 * 19; i++)//vẽ cột ngăn cách từng mục 
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
	loadListTOC(tl, count);
	SetBGColor(11);
	SetColor(0);
}

void clearTableTOC(){
	for (int i = 3; i <  3+ 2 * 19; i+=2)
	{
		gotoxy(2, i);
		for(int j=0;j<6;j++) cout << " ";
		gotoxy(10, i);
		for(int j=0;j<36;j++) cout << " ";
		gotoxy(48, i);
		for(int j=0;j<15;j++) cout << " ";
		gotoxy(65, i);
		for(int j=0;j<32;j++) cout << " ";
		gotoxy(99, i);
		for(int j=0;j<11;j++) cout << " ";
		gotoxy(112,i);
		for(int j=0;j<11;j++) cout << " ";
		gotoxy(125,i);
		for(int j=0;j<5;j++) cout << " ";
	}
}

// void printBooklist(){}

void controlTOCTable(TableOfContentList &tl, int count){
	SetBGColor(11);
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
		else if(c==75)///left
		{
			if(count == 19) {continue;}
			UnHighLight(wherex(),wherey(),9);
			count -= 19;
			clearTableTOC();
			loadListTOC(tl, count);
			gotoxy(130,3);
			HighLight(wherex(),wherey(),9);
		}
		else if(c==77)//right
		{
			if(count > tl.size) {continue;}
			UnHighLight(wherex(),wherey(),9);
			count +=19;
			clearTableTOC();
			loadListTOC(tl, count);
			gotoxy(130,3);
			HighLight(wherex(),wherey(),9);
		}
		else if (c == 13)//Khi nguoi dung nhan ENTER
		{
			count = 19;
			SetBGColor(15);
			if (wherey() == 3)
			{
				system("cls");
				tableEnterTOC(tl);
				system("cls");
				TableTOC(tl, count);
				controlTOCTable(tl, count);
				break;
			}
			else if (wherey() == 7)
			{
				editTOC(tl);
				system("cls");
				TableTOC(tl, count);
				controlTOCTable(tl, count);
				break;
			}
			else
			{
				filterBySearching(tl, count);
				gotoxy(120, 20);
				while(true){
					gotoxy(127, 5);
					cout << "ESC : Return to menu!";
					char a=_getch();
					SetBGColor(15);
					if(a == 27){
						system("cls");
						TableTOC(tl, count);
						controlTOCTable(tl, count);
						break;
					}else{
						continue;
					}
				}
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
	int x = 18; int y = 12; int width = 150; int height = 30;
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
				int n = saveFileReader(rl);
				int m = saveTOC(tl);
				if (n == 0||m==0)
				{
					system("cls");
					gotoxy(60,20);
					cout << "CAN'T SAVE!!!\n";
					Sleep(1000);
				}
				else
				{
					system("cls");
					gotoxy(60,20); 
					cout<<"SAVING SUCCESSFUL!!!";
					Sleep(1000);
				}
				system("cls");
				boxMenu();
				Control(rl, tl);
				break;
			}
			else if (wherey() == y + height / 4 - 1)//option 1
			{
				system("cls");
				int n=0;
				nodeRC* tmp[MAX];
				tranvertree(rl.head,tmp,n);
				int x=selectDisplayMode();
				if(x==0) 
				{
					system("cls");
					boxMenu();
					Control(rl, tl);
					break;
				}
				else if(x==1) sortbyID(tmp,rl.size);
				else sortbyname(tmp,rl.size);
				
				system("cls");
				ReaderTable(tmp,rl.size,20);
				controlReaderTable(rl,tmp,20);
				system("cls");
				boxMenu();
				Control(rl, tl);
				break;
			}
			else if (wherey() == y + height / 4 + 4 - 1)//option 2
			{
				system("cls");
				TableTOC(tl, 19);
				controlTOCTable(tl, 19);
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
	resizeConsole(1300, 750);
	ReaderList rl;
	TableOfContentList tl;
	DisableSelection();
	DisableCtrButton(0, 1, 1);
	DisableResizeWindow();
	ShowCur(false);
//	loading();
//	resetIDRCfile(); return 0;//dieu chinh lai danh sach ID tu dau //
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
	delete rl.head;
	releaseMemory(tl);
	return 0;
}
