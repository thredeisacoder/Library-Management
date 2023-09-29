#include "Book.cpp"

// thong tin muon va tra sach
struct BorrowAndReturn 
{
		Book book;
		string LoanDate;
		string ReturnDate;
		int Status;
};

struct nodeBorrowAndReturn
{
	BorrowAndReturn data;
	nodeBorrowAndReturn* next;
};

struct BorrowAndReturnList
{
	nodeBorrowAndReturn* head;
	nodeBorrowAndReturn* tail;
	int size=-1;
};
