#include "Book.cpp"

// thong tin muon va tra sach
class BorrowAndReturn : public Book
{
	public:
		string LoanDate;
		string ReturnDate;
		int Status;
		
		BorrowAndReturn(string BookID,string BookStatus,string LoanDate,string ReturnDate,int Status): Book(BookID,BookStatus)
		{
			this->LoanDate=LoanDate;
			this->ReturnDate=ReturnDate;
			this->Status=Status;
		}
};

struct nodeBorroAndReturn
{
	BorrowAndReturn data;
	nodeBorroAndReturn* next;
};

struct BorrowAndReturnList
{
	nodeBorrowAndReturn* head;
	nodeBorrowAndReturn* head;
	int size=-1;
};
