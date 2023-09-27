#include "BookCatalog.cpp"

//dau sach
class TableOfContent
{
	public:
		string ISBN;
		string BookName;
		string PublicYear;
		string Author;
		int NumOfPage;
		string Genre;
		BookCatalog* dms;
		
	TableOfContent(string ISBN,string BookName,string PublicYear,string Author,int NumOfPage,string Genre,BookCatalog* dms)
	{
		this->ISBN=ISBN;
		this->BookName=BookName;
		this->PublicYear=PubicYear;
		this->Author=Author;
		this->NumOfPage=NumOfPage;
		this->Genre=Genre;
		this->dms=dms;
	}
};

struct TableOfContentList
{
	TableOfContent* ds[1000];
	int n=-1;
};
