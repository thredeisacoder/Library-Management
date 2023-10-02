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

nodeBAR* makeNodeBAR(BorrowAndReturn BAR)
{
	nodeBAR* p=new noode;
	p->data=BAR;
	p->next=NULL;
}

void addNodeBAR(BorrowAndReturnList &l,BorrowAndReturn BAR)
{
	node* p=makenode(BAR);
	l.tail->next=p;
	return l;
}

void deleteNodeBAR(BorrowAndReturnList &l,BorrowAndReturn BAR)
{
	nodeBAR* tmp=l.head->next;
	if(l.head->data==BAR) 
	{
		l.head=l.head->next;
	}
	while(tmp->next!=l.tail)
	{
		if(tmp->data==BAR)
		{
			break;
		}
		tmp=tmp->next;
	}
	nodeBAR* t=l.head;
	while(t->next!=tmp)
	{
		t=t->next;
	}
	t=tmp->next;
	delete tmp;
}
