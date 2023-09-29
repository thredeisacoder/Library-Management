#include "BookCatalog.cpp"
#include "processTOC.cpp"

//dau sach
struct TableOfContent
{
	string ISBN;
	string BookName;
	int NumOfPage;
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
	l.ds[n]=new TableOfContent;
	l.ds[n]=TOC;
}

TableOfContent EnterInforTOC()
{
	TableOfContent TOC;
	cout<<"enter ISBN:";
	TOC.ISBN=enterISBN();
	
	
	
}
