#include "BookCatalog.cpp"

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
