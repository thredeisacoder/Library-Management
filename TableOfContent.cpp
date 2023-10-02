#include "BookCatalog.cpp"
#include "processTOC.cpp"

//dau sach
struct TableOfContent
{
	string ISBN;
	string BookName;
	string NumOfPage;
	string Author;
	string PublicYear;
	string Genre;
	BookCatalog* dms;
};

struct TableOfContentList
{
	TableOfContent* ds[1000];
	int n=-1;
};

void addTableOfContent(TableOfContentList &l, TableOfContent TOC)
{
	l.n++;
	l.ds[l.n]=new TableOfContent(TOC);
}

TableOfContent EnterInforTOC()
{
	TableOfContent TOC;
	cout<<"enter ISBN:";
	TOC.ISBN=enterISBN();
	cout<<"enter Book's Name :";
	TOC.BookName=enterName();
	cout<<"enter Number of Page: ";
	TOC.NumOfPage=enterNumOfPage();
	cout<<"enter Author: ";
	TOC.Author=enterName();
	cout<<"enter publication year: ";
	TOC.PublicYear=enterNumOfPage();
	cout<<"enter genre: ";
	TOC.Genre=enterName();
	return TOC;

}
