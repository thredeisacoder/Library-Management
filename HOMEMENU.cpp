#include "mylib.h"

using namespace std;

void loading()
{
	string s="HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO TAI TP HCM!!!";
		for(int i=0;i<s.length();i++)
		{
			gotoxy(40+i,10);
			cout<<s[i];
			gotoxy(40+i,12);
			SetBGColor(15);
			cout<<" ";
			SetBGColor(16);
			Sleep(80);
		}
		Sleep(1500);
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


void Option(int x, int y, int width, int height, string option)
{
	for (int i = x-6; i <= x + width / 3-6 ; i++)//vong lap chay tu dau den het chieu dai option
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i, y -1);
		cout << " ";
		gotoxy(i, y);
		cout << " ";
		SetBGColor(15);
		gotoxy(i, y + 1);
		cout << " ";
	}
	gotoxy(x, y);
	cout <<option;
}



//tao menu
void boxMenu()
{
	int x=20;
	int y=2;
	int width=120;
	int height=30;

	if(width<=1||height<=1) return;
	Tittle(x,y,width,height, "QUAN LI THU VIEN");
	Option(x + width / 3, y + height / 4 , width, height, "TABLE OF CONTENT LIST");
	Option(x + width / 3, y + height / 4 + 4 , width, height, "READER LIST");
	Option(x + width / 3, y + height / 4 + 8, width, height, "BORROW AND RETURN LIST");
	Option(x + width / 3, y + height / 4 +12, width, height, "BOOK CATALOG LIST");
	Option(x + width / 3, y + height / 4 + 16 , width, height, "option 5");
	Option(x + width / 3, y + height / 4 + 20 , width, height, "QUIT!");
	

	//in 2 canh ben cua khung menu
	for(int i=y-2;i<=y+height+2;i++)
    {
        gotoxy(x+width/6,i);
        cout<<"  ";
        gotoxy(x+width*5/6 - 12,i);
        cout<<"  ";
    }


	//in khung duoi cua menu
	for (int i = x + width / 6; i < x + width * 5 / 6 - 12; i++)
	{
		gotoxy(i, y + height +2);
		cout << " ";
	}

		//in huong dan
	gotoxy(x + width / 6 + 10, y + height * 5 / 6 + 6);
	cout << "Press Up and Down to move and Enter to choose!!! ";

	SetBGColor(16);
	SetColor(15);

}
// bat thanh sang
void HighLight(int x,int y,int width)
{
    for(int i=x;i<=x+width/3;i++)
	{
		for(int j=y;j<=y+2;j+=2)
		{
			SetBGColor(9);
			gotoxy(i,j);
			cout<<" ";
		}
	}
	gotoxy(x,y);
}
//tat thanh sang
void UnHighLight(int x,int y,int width)
{
	for(int i=x;i<=x+width/3;i++)
	{
		for(int j=y;j<=y+2;j+=2)
		{
			SetBGColor(15);
			gotoxy(i,j);
			cout<<" ";
		}
	}
	gotoxy(x,y);
}

//dieu khien tren menu
void Control()
{
	int x=20;int y=2;int width=120;int height=30;
	//danh dau lua chon dau
    gotoxy(x+width/3-6,y+height/4-1);
    HighLight(wherex(),wherey(),width);
	while(true)
	{
		// nhan phim tu nguoi dung(up/down/enter)
		char c=getch();
		if(c==-32)
        {
            c=getch();
		}

		if(c==72)//khi nguoi dung nhan UP
		{
			if(wherey()==y+height/4-1)
			{
				UnHighLight(wherex(),wherey(),width);
                gotoxy(x+width/3-6,y+height/4+20-1);
                HighLight(wherex(),wherey(),width);

			}
			else
			{
				UnHighLight(wherex(),wherey(),width);
			    gotoxy(x+width/3-6,wherey()-4);
			    HighLight(wherex(),wherey(),width);
			}
		}
		else if(c==80)//khi nguoi dung nhan Down
        {
			if(wherey()==y+height/4+20-1)
			{
				UnHighLight(wherex(),wherey(),width);
                gotoxy(x+width/3-6,y+height/4-1);
                HighLight(wherex(),wherey(),width);

			}
			else
			{
				UnHighLight(wherex(),wherey(),width);
			    gotoxy(x+width/3-6,wherey()+4);
			    HighLight(wherex(),wherey(),width);
			}
        }
        else if(c==13)//Khi nguoi dung nhan ENTER
        {
        	SetBGColor(16);
            if(wherey()==y+height/4+16-1)
            {
            	system("cls");
                break;
            }
            else if(wherey()==y+height/4-1)
            {
                system("cls");
                break;
            }
            else if(wherey()==y+height/4+4-1)
            {
                system("cls");
                break;
            }
            else if(wherey()==y+height/4+8-1)
            {
                system("cls");
                break;
            }
            else if(wherey()==y+height/4+12-1)
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

int main()
{
	DisableSelection();
	resizeConsole(1200,600);
	DisableCtrButton(0,1,1);
	DisableResizeWindow();
	loading();
	boxMenu();
	ShowCur(0);
	Control();

	return 0;
}
