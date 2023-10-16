#pragma once
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

#define MAX 10000
struct Book
{
	string BookID;
	int BookStatus;
	string BookLocation;
};

struct nodeB
{
	Book data;
	nodeB* next=nullptr;
};

struct BookList
{
	nodeB* head = nullptr;
	nodeB* tail = nullptr;
	int size = 0;
};

/////////////////////////////////////////////muon tra/////////////////////////////////////////////////

struct Date
{
	int day;
	int month;
	int year;
};

struct BorrowAndReturn
{
	string BookID;
	Date BorrowDate;
	Date ReturnDate;
	int Status = 0;
};

struct nodeBAR
{
	BorrowAndReturn data;
	nodeBAR* next = nullptr;
};

struct BorrowAndReturnList
{
	nodeBAR* head = nullptr;
	nodeBAR* tail = nullptr;
	int size = 0;
};

/////////////////////////////////////////////dau sach/////////////////////////////////////////////////
struct TableOfContent
{
	string ISBN;
	string BookName;
	string NumOfPage;
	string Author;
	string PublicYear;
	string Genre;

	BookList dms;
};

struct TableOfContentList
{
	TableOfContent* ds[MAX] = {NULL};
	int size = 0;
};
void addTail(TableOfContentList& tl, TableOfContent data) {
	tl.ds[tl.size++] = new TableOfContent(data);
}

TableOfContent* searchByName(TableOfContentList tl, string input) {
	for (int i = 0; i < tl.size; i++)
		if (tl.ds[i]->BookName == input)
			return tl.ds[i];
	return NULL;
}

void themTheoThuTuTenSach(TableOfContentList& tl, TableOfContent data) {
	if (tl.size < MAX) {
		int locate;
		for (locate = 0; locate < tl.size && tl.ds[locate]->BookName < data.BookName; locate++);
		for (int i = tl.size++; i > locate; i--)
			tl.ds[i] = tl.ds[i - 1];
		tl.ds[locate] = new TableOfContent(data);
	}
}

/////////////////////////////////////////////DOC GIA/////////////////////////////////////////////////

struct Reader {
	string ID="";
	string Gender="";
	string FirstName="";
	string LastName="";
	int CardStatus = 1;

	BorrowAndReturnList dsmt;
};

struct nodeRC
{
	Reader data;
	nodeRC* left = nullptr;
	nodeRC* right = nullptr;
};

struct ReaderList
{
	nodeRC* head = nullptr;
	int size = 0;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////

nodeB* makeNodeBook(Book data)
{
	nodeB* p = new nodeB;
	p->data = data;
	p->next = NULL;
	return p;
}

int addNodeBook(BookList& l, Book data)
{
	nodeB* p = makeNodeBook(data);
	if (l.head == nullptr)
	{
		l.head = p;
		l.tail = p;
		++l.size;
		return 1;
	}
	else
	{
		nodeB* preB = l.head;
		if (p->data.BookID >= l.head->data.BookID)
		{
			p->next = l.head;
			l.head = p;
			++l.size;
			return 1;
		}
		for (nodeB* i = l.head; i != nullptr; i = i->next)//duyet tu dau toi cuoi
		{
			if (p->data.BookID >= i->data.BookID)//khi id cua sach can them >id cua i thi chen p truoc i
			{
				p->next = i;
				preB->next = p;
				++l.size;
				return 1;
			}
			else//neu khong thi cap nhat phan tu pre va i
			{
				preB = i;
				i = i->next;
			}
		}
		//khi khong co phan tu nao co id >p
		l.tail->next = p;
		++l.size;
		return 1;
	}
	return 0;
}

int deleteNodeBC(BookList& l, string ID)
{
	if (l.head == NULL)//khi danh sach rong thi ko xoa duoc
	{
		return 0;
	}
	else if (l.head->data.BookID == ID) //phan tu dau co id can xoa
	{
		nodeB* tmp = l.head;
		l.head = tmp->next;
		delete tmp;
		return 1;
	}
	else
	{
		nodeB* tmp = l.head->next;
		nodeB* pre = l.head;
		while (tmp != NULL)
		{
			if (tmp->data.BookID == ID)
			{
				pre->next = tmp->next;
				delete tmp;
				return 1;
			}
			else
			{
				pre = tmp;
				tmp = tmp->next;
			}
		}
		return 0;
	}

}
//
nodeBAR* makeNodeBAR(BorrowAndReturn data)
{
	nodeBAR* p = new nodeBAR;
	p->data = data;
	return p;
}

int addNodeBAR(BorrowAndReturnList& l, BorrowAndReturn data)
{
	nodeBAR* p = makeNodeBAR(data);
	if (l.head == NULL)
	{
		l.head = p;
		return 1;
	}
	else if (l.head->data.BookID > data.BookID)
	{
		p->next = l.head;
		l.head = p;
		return 1;
	}
	else
	{
		nodeBAR* tmp = l.head->next;
		nodeBAR* pre = l.head;
		while (tmp != NULL)
		{
			if (tmp->data.BookID > data.BookID)
			{
				p->next = tmp;
				pre->next = p;
				return 1;
			}
		}
	}
	return 0;
}

int deleteNodeBAR(BorrowAndReturnList& l, string ID)
{
	if (l.head == NULL)//kiem tra danh sach rong
	{
		return 0;
	}
	else if (l.head->data.BookID == ID)//khi phan tu dau co id can xoa
	{
		nodeBAR* tmp = l.head;
		l.head = l.head->next;
		delete tmp;
		return 1;
	}
	else
	{
		nodeBAR* tmp = l.head->next;
		nodeBAR* pre = l.head;
		while (tmp != NULL)
		{
			if (tmp->data.BookID == ID)
			{
				pre->next = tmp->next;
				delete tmp;
				return 1;
			}
			else
			{
				pre = tmp;
				tmp = tmp->next;
			}
		}
	}
	return 0;
}
//
nodeRC* makeNodeReader(Reader data)
{
	nodeRC* p = new nodeRC;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

string makeID(nodeRC* pre, nodeRC* p)
{
	string s = "";
	int n = 0;
	for (int i = 0; i < 5; i++)
	{
		int x = int(pre->data.ID[pre->data.ID.length() - 1 - i]-'0');
		n =n+ pow(10,i) * x;
	}

	n++;

	while (s.length()<5)
	{
		s = char(n % 10 +'0') + s;
		n /= 10;
	}
	return  s;
}

int  addNodeReader(ReaderList& l, Reader data)
{
	nodeRC* p = makeNodeReader(data);
	if (l.size == 0)
	{
		p->data.ID ="00001";
		l.head = p;
		++l.size;
		return 1;
	}
	else
	{
		string newName = data.LastName + data.LastName;
		nodeRC* tmp = l.head;

		while (tmp->left != nullptr && tmp->right != nullptr)
		{
			string Name = tmp->data.LastName + tmp->data.FirstName;
			if (Name > newName)
			{
				tmp = tmp->left;
			}
			else
			{
				tmp = tmp->right;
			}
		}
		p->data.ID = makeID(tmp, p);
		if (tmp->left == nullptr)
		{
			tmp->left = p;
			++l.size;
			return 1;
		}

		if (tmp->right == nullptr)
		{
			tmp->right = p;
			++l.size;
			return 1;
		}
	}
	return 0;
}

int  deleteNodeReader(ReaderList& l, string ID) 
{
	if (l.size == 0)
	{
		return 0;
	}
	nodeRC* par = nullptr;
	nodeRC* cur = l.head;

	while (cur != nullptr && cur->data.ID != ID)
	{
		if (cur->data.ID < ID)
		{
			par = cur;
			cur = cur->right;
		}
		else
		{
			par = cur;
			cur = cur->left;
		}
	}
	if (cur == nullptr)//khong tim thay ID
	{
		return 0;
	}

	if (cur->left == nullptr)
	{
		delete cur;
		l.size--;
		return 1;
	}
	else if (cur->right = nullptr)
	{
		delete cur;
		l.size--;
		return 1;
	}
	else
	{
		nodeRC* pre = nullptr;
		nodeRC* tmp = cur->left;
		while (tmp->left != nullptr)
		{
			pre = tmp;
			tmp = tmp->left;
		}

		if (par == nullptr)
		{
			cur->right = tmp->right;
			delete tmp;
			l.size--;
			return 1;
		}
		else
		{
			cur->data = tmp->data;
			pre->left = tmp->right;
			delete tmp;
			l.size--;
			return 1;
		}
	}
}


