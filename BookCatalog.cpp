#include "Book.cpp"

using namespace std;
//danh muc sach
struct BookCatalog 
{
	Book book;
    string BookLocation;
};

struct nodeBookCatalog
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

