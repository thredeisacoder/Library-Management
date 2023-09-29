#include "Book.cpp"

// thong tin muon va tra sach
struct BorrowAndReturn 
{
		Book book;
		string LoanDate;
		string ReturnDate;
		int Status;
};

struct nodeBAR
{
	BorrowAndReturn data;
	nodeBAR* next;
};

struct BorrowAndReturnList
{
	nodeBAR* head;
	nodeBAR* tail;
	int size=-1;
};
