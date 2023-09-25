#include <iostream>
#include "mylib.h"
#include <windows.h>
using namespace std;

void boxMenu(int x,int y,int width,int hight)
{

	if(width<=1||hight<=1) return;

	for(int i=x+1;i<x+width - 12;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y-2);
		cout<<" ";
		gotoxy(i,y+hight/6-2);
		cout<<" ";

	}

	gotoxy(x+width/2-14,y+hight/16-1);
	SetColor(10);
	cout<<"QUAN LY SINH VIEN";




	for(int i=x+1;i<=x+width/4;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y+hight/4-1);
		cout<<" ";
		gotoxy(i,y+hight/4);
		cout<<" ";
		SetBGColor(15);
		gotoxy(i,y+hight/4+1);
		cout<<" ";
	}
	gotoxy(x+2,y+hight/4);
	cout<<"\t1.OPTION 1";



	for(int i=x+1;i<=x+width/4;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y+hight/4+4-1);
		cout<<" ";
		gotoxy(i,y+hight/4+4);
		cout<<" ";
		gotoxy(i,y+hight/4+4+1);
		cout<<" ";
	}
	gotoxy(x+2,y+hight/4+4);
	cout<<"\t2.OPTION 2";




	for(int i=x+1;i<=x+width/4;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y+hight/4+8-1);
		cout<<" ";
		gotoxy(i,y+hight/4+8);
		cout<<" ";
		gotoxy(i,y+hight/4+8+1);
		cout<<" ";
	}
		gotoxy(x+2,y+hight/4+8);
	cout<<"\t3.OPTION 3";




	for(int i=x+1;i<=x+width/4;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y+hight/4+12-1);
		cout<<" ";
		gotoxy(i,y+hight/4+12);
		cout<<" ";
		gotoxy(i,y+hight/4+12+1);
		cout<<" ";
	}
	gotoxy(x+2,y+hight/4+12);
	cout<<"\t4.OPTION 4";




	for(int i=x+1;i<=x+width/4;i++)
	{
		SetBGColor(15);
		SetColor(16);
		gotoxy(i,y+hight/4+16-1);
		cout<<" ";
		gotoxy(i,y+hight/4+16);
		cout<<" ";
		gotoxy(i,y+hight/4+16+1);
		cout<<" ";
	}
	gotoxy(x+2,y+hight/4+16);
	cout<<"\t0.QUIT";

	for(int i=x+1;i<x+width - 12;i++)
	{
		gotoxy(i,y+hight);
		cout<<char(196);
	}

	SetBGColor(16);
	SetColor(15);

    system("pause");
}



int main()
{
	boxMenu(10,8,120,30);
	return 0;
}
