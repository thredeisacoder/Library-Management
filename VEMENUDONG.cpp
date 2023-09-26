#include <iostream>
#include "mylib.h"
#include <windows.h>
#include <conio.h>
using namespace std;

void boxMenu(int x,int y,int width,int height)
{

	if(width<=1||height<=1) return;

    for(int i=x+width/6;i<=x+width*5/6-12;i++)
    {
        for(int j=y-2;j<=y+height/6-2;j++)
        {
            SetBGColor(15);
            SetColor(16);
            gotoxy(i,j);
            cout<<" ";
        }
    }

	gotoxy(x+width/2-14,y+height/16-1);
	SetColor(10);
	cout<<"~QUAN LY THU VIEN~";


	for(int i=x+width/3-6;i<=x+width*2/3-6;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y+height/4-1);
		cout<<" ";
		gotoxy(i,y+height/4);
		cout<<" ";
		SetBGColor(15);
		gotoxy(i,y+height/4+1);
		cout<<" ";
	}
	gotoxy(x+width/3,y+height/4);
	cout<<"\t1.OPTION 1";



	for(int i=x+width/3-6;i<=x+width*2/3-6;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y+height/4+4-1);
		cout<<" ";
		gotoxy(i,y+height/4+4);
		cout<<" ";
		gotoxy(i,y+height/4+4+1);
		cout<<" ";
	}
	gotoxy(x+width/3,y+height/4+4);
	cout<<"\t2.OPTION 2";




	for(int i=x+width/3-6;i<=x+width*2/3-6;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y+height/4+8-1);
		cout<<" ";
		gotoxy(i,y+height/4+8);
		cout<<" ";
		gotoxy(i,y+height/4+8+1);
		cout<<" ";
	}
		gotoxy(x+width/3,y+height/4+8);
	cout<<"\t3.OPTION 3";




	for(int i=x+width/3-6;i<=x+width*2/3-6;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y+height/4+12-1);
		cout<<" ";
		gotoxy(i,y+height/4+12);
		cout<<" ";
		gotoxy(i,y+height/4+12+1);
		cout<<" ";
	}
	gotoxy(x+width/3,y+height/4+12);
	cout<<"\t4.OPTION 4";




	for(int i=x+width/3-6;i<=x+width*2/3-6;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y+height/4+16-1);
		cout<<" ";
		gotoxy(i,y+height/4+16);
		cout<<" ";
		gotoxy(i,y+height/4+16+1);
		cout<<" ";
	}
	gotoxy(x+width/3,y+height/4+16);
	cout<<"\t0.QUIT";

    for(int i=y-2;i<=y+height-2;i++)
    {
        gotoxy(x+width/6,i);
        cout<<"  ";
        gotoxy(x+width*5/6 - 12,i);
        cout<<"  ";
    }

	gotoxy(x+width/6+10,y+height*5/6+2);
	cout<<"Press Up and Down to move and Enter to choose!!! ";

	for(int i=x+width/6;i<x+width*5/6 -12;i++)
	{
		gotoxy(i,y+height-2);
		cout<<" ";
	}

	SetBGColor(16);
	SetColor(15);

}

void HighLight(int x,int y,int width)
{
    for(int i=x;i<=x+width/3;i++)
	{
		for(int j=y;j<=y+2;j+=2)
		{
			SetBGColor(2);
			gotoxy(i,j);
			cout<<" ";
		}
	}
	gotoxy(x,y);
}

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


void Control(int x,int y,int width,int height)
{
    gotoxy(x+width/3-6,y+height/4-1);
    HighLight(wherex(),wherey(),width);
	while(true)
	{
		char c=getch();
		if(c==-32)
        {
            c=getch();
		}
		if(c==72)
		{
			if(wherey()==y+height/4-1)
			{
				UnHighLight(wherex(),wherey(),width);
                gotoxy(x+width/3-6,y+height/4+16-1);
                HighLight(wherex(),wherey(),width);

			}
			else
			{
				UnHighLight(wherex(),wherey(),width);
			    gotoxy(x+width/3-6,wherey()-4);
			    HighLight(wherex(),wherey(),width);
			}
		}
		else if(c==80)
        {
			if(wherey()==y+height/4+16-1)
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
        else if(c==13)
        {
        	SetBGColor(16);
            if(wherey()==y+height/4+16-1)
            {
            	gotoxy(x+width,y+height);
                break;
            }
            if(wherey()==y+height/4-1)
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
	boxMenu(6,2,120,30);
	DisableCtrButton(0,1,1);
	DisableResizeWindow();
	ShowCur(0);
	Control(6,2,120,30);

	return 0;
}
