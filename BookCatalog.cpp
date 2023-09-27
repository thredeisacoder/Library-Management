#include "Book.cpp"

//danh muc sach
class BookCatalog : public Book{
public:
    string BookLocation;
	
	BookCatalog() :Book()
	{
	}
	BookCatalog(string BookID,int BookStatus,string BookLocation ): Book(BookID,BookStatus)
	{
		this->BookLocation=BookLocation;
	}
};

struct nodeBookCataLog
{
	BookCatalog data;
	nodeBookCatalog* next;
};

struct BookCatalogList
{
	nodeBookCatalog* head;
	nodeBookCatalog* tail;
	int size=-1;
};

