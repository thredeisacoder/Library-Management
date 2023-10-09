#pragma once
#include <iostream>
#include <string.h>

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
	nodeB* next;
};

struct BookList
{
	nodeB* head = NULL;
	nodeB* tail = NULL;
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
	nodeBAR* next = NULL;
};

struct BorrowAndReturnList
{
	nodeBAR* head = NULL;
	nodeBAR* tail = NULL;
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
	TableOfContent* ds[MAX];
	int size = 0;
};

/////////////////////////////////////////////DOC GIA/////////////////////////////////////////////////

struct Reader {
	string ID;
	string Gender;
	string FirstName;
	string LastName;
	int CardStatus = 1;

	BorrowAndReturnList dsmt;
};

struct nodeRC
{
	Reader data;
	nodeRC* left = NULL;
	nodeRC* right = NULL;
};

struct ReaderList
{
	nodeRC* head = NULL;
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
	if (l.head == NULL)
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
		for (nodeB* i = l.head; i != NULL; i = i->next)//duyet tu dau toi cuoi
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

int addTableOfContent(TableOfContentList& l, TableOfContent TOC)
{
	if (l.size == MAX - 1) return 0;
	l.ds[l.size] = new TableOfContent(TOC);
	l.size++;
	return 1;
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

int  addNodeReader(ReaderList& l, Reader data)
{
	nodeRC* p = makeNodeReader(data);
	if (l.size == 0)
	{
		p->data.ID = l.size + 1;
		l.head = p;
		++l.size;
		return 1;
	}
	else
	{
		string newName = data.LastName + data.LastName;
		nodeRC* tmp = l.head;

		while (tmp->left != NULL && tmp->right != NULL)
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

		if (tmp->left == NULL)
		{
			tmp->left = p;
			return 1;
		}

		if (tmp->right == NULL)
		{
			tmp->right = p;
			return 1;
		}
	}

	return 0;
}

nodeRC* findMaxLeft(nodeRC* t)
{
	if (t->left == NULL)
	{
		return t;
	}
	else return findMaxLeft(t->left);
}

int  deleteNodeReader(ReaderList& l, string ID) {
	if (l.head == NULL) return 0;
	else
	{
		nodeRC* tmp = l.head;
		nodeRC* pre = NULL;
		while (tmp->left != NULL && tmp->right != NULL)
		{
			if (tmp->data.ID < ID)
			{
				pre = tmp;
				tmp = tmp->left;
			}
			else if (tmp->data.ID > ID)
			{
				pre = tmp;
				tmp = tmp->right;
			}
			else
			{
				if (tmp->left == NULL && tmp->right == NULL)
				{
					delete tmp;
				}
				else if (tmp->left == NULL)
				{
					pre->right = tmp->right;
					delete tmp;
				}
				else if (tmp->right == NULL)
				{
					pre->left = tmp->left;
					delete tmp;
				}
				else
				{
					nodeRC* t = findMaxLeft(tmp->right);
					swap(tmp->data, t->data);
					delete t;
				}
				return 1;
			}
		}
	}
}



