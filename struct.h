#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
#include <ctime>
#include <fstream>

using namespace std;

#define MAX 10000
struct Book
{
	string BookID = "";
	int BookStatus = 0;
	string BookLocation = "";
};
struct nodeB
{
	Book data;
	nodeB *next = nullptr;
};

struct BookList
{
	nodeB *head = nullptr;
	nodeB *tail = nullptr;
	int size = 0;
};

struct TableOfContent
{
	string ISBN;
	string BookName;
	string NumOfPage;
	string Author;
	string PublicYear;
	string Genre;

	BookList dms;
	int BorrowTotal = 0;
};

struct TableOfContentList
{
	TableOfContent *ds[MAX] = {nullptr};
	int size = 0;
};
struct Date
{
	int day = 0;
	int month = 0;
	int year = 0;
};

struct BorrowAndReturn
{
	string bookID = "";
	int status = 0;
	Date BorrowDate;
	Date ReturnDate;
};

struct nodeBAR
{
	BorrowAndReturn data;
	nodeBAR *next = nullptr;
};

struct BorrowAndReturnList
{
	nodeBAR *head = nullptr;
	nodeBAR *tail = nullptr;
	int size = 0;
};

struct Reader
{
	string ID = "";
	string Gender = "";
	string FirstName = "";
	string LastName = "";
	int CardStatus = 1;

	BorrowAndReturnList dsmt;
};

struct nodeRC
{
	Reader data;
	nodeRC *left = nullptr;
	nodeRC *right = nullptr;
};

struct ReaderList
{
	nodeRC *head = nullptr;
	int size = 0;
	string *notusedid = new string[MAX];
};

nodeB *makeNodeBook(Book data)
{
	nodeB *p = new nodeB;
	p->data = data;
	p->next = nullptr;
	return p;
}

nodeRC *makeNodeReader(Reader data)
{
	nodeRC *p = new nodeRC;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void releaseMemory(TableOfContentList &data)//giai phong bo nho
{
	for (int i = 0; i < data.size; i++)
	{
		delete data.ds[i];
		data.ds[i] = nullptr; // ??t con tr? th?nh nullptr d? tr?nh truy c?p b? nh? sau khi gi?i ph?ng
	}
	data.size = 0; // ??t k?ch thu?c v? 0 d? d?nh d?u danh s?ch r?ng
}

int compare(TableOfContentList tl, TableOfContent data)//kiem tra dau sach co trung hay khong
{
	for (int i = 0; i < tl.size; i++)
	{
		if (tl.ds[i]->ISBN == data.ISBN)
		{
			return 0;
		}
		else if (tl.ds[i]->BookName == data.BookName && tl.ds[i]->Author == data.Author && tl.ds[i]->Genre == data.Genre)
		{
			return 0;
		}
	}
	return 1;
} // done

int addTail(TableOfContentList &tl, TableOfContent& data)//them duoi
{
	if (tl.size == MAX)
	{
		return 0;
	}
	nodeB* tmp=data.dms.head;
	while(tmp!=nullptr)
	{
		tmp->data.BookLocation+="No."+to_string(tl.size+1);
		tmp=tmp->next;
	}
	tl.ds[tl.size] = new TableOfContent(data);
	tl.size++;
	return 1;
} // done
int themTheoThuTuTheLoai(TableOfContentList &tl, TableOfContent& data)//them dau sach theo thu tu the loai
{
	int locate;
	if (tl.size == 0)
	{
		return addTail(tl, data);
	}
	if (tl.size < MAX && compare(tl, data) != 0)
	{
		for (locate = 0; locate < tl.size; locate++)
		{
			if (tl.ds[locate]->Genre > data.Genre || (tl.ds[locate]->Genre == data.Genre && tl.ds[locate]->BookName > data.BookName))
			{
				break;
			}
		}
		for (int i = tl.size; i > locate; i--)
		{
			tl.ds[i] = tl.ds[i - 1];
		}
			nodeB* tmp=data.dms.head;
		while(tmp!=nullptr)
		{
			tmp->data.BookLocation+="No."+to_string(tl.size+1);
			tmp=tmp->next;
		}
		tl.ds[locate] = new TableOfContent(data);
		tl.size++;
	}
	else
	{
		return 0;
	}
	return 1;
}

TableOfContentList saveToSearch(TableOfContentList tl, string input)//loc de dau sach sau khi tim kiem
{
	TableOfContentList tmp;
	int index = 0;
	for (int i = 0; i < tl.size; i++)
	{
		string name=tl.ds[i]->BookName;
		if (name.find(input)!=std::string::npos) // tim ten sach chua chuoi nguoi dung nhap
		{
			for (int j = 0; j < tl.ds[i]->dms.size; j++)
			{
				tmp.ds[index] = tl.ds[i];
				index++;
				tmp.size++;
			}
		}
	}
	return tmp;
}
string generateID(TableOfContent *p, int i)//tao id tu dong
{
	string id = "";
	if (i >= 0 && i < 9)
	{
		id = p->ISBN + "_0" + to_string(i + 1);
	}
	else
	{
		id = p->ISBN + "_" + to_string(i + 1);
	}
	return id;
}

BookList createBookList(TableOfContent *p)//tao danh muc sach
{
	BookList *list = new BookList;
	for (int i = 0; i < p->dms.size; i++)
	{
		nodeB *newNode = new nodeB;
		newNode->data.BookStatus = 0;
		newNode->data.BookID = generateID(p, i);
		if (list->tail == nullptr)
		{
			list->head = newNode;
			list->tail = newNode;
		}
		else
		{
			list->tail->next = newNode;
			list->tail = newNode;
		}
	}
	list->size = p->dms.size;
	return *list;
}

Date currentTime()//thoi gian hien tai
{
	Date timeeee;
	// thời gian hiện tại tính theo hệ thống
	time_t now = time(0);
	tm *ltm = localtime(&now);
	// in ra các thành phần của cấu trúc tm struct
	timeeee.year = 1900 + ltm->tm_year;
	timeeee.month = 1 + ltm->tm_mon;
	timeeee.day = ltm->tm_mday;
	return timeeee;
}

int convertMonthtoDay(int month)//chuyen thang thanh ngay
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 2:
		return 28;
	default:
		return 30;
	}
}

int compareDate(Date returnDate)//so sanh thoi gian
{
	Date cur = currentTime();
	if (cur.year > returnDate.year)
	{
		return 1;
	}
	else if (cur.month > returnDate.month)
	{
		return 1;
	}
	else if (cur.day > returnDate.day)
	{
		return 1;
	}
	return 0;
}

int countOverdueDay(Date returnDate)//dem ngay qua han
{
	Date cur = currentTime();
	int year = cur.year - returnDate.year;
	int count = 365 * year;
	int month = cur.month - returnDate.month;
	int day;
	if (month > 0)
	{
		for (int i = returnDate.month + 1; i <= cur.month; i++)
		{
			count += convertMonthtoDay(i);
		}
	}
	if(month < 0)
	{
		for (int i = cur.month + 1; i <= returnDate.month; i++)
		{
			count -= convertMonthtoDay(i);
		}
	}
	day = cur.day - returnDate.day;
	count += day;
	return count;
}

int TotalOverdue(nodeRC *p)//tinh tong ngay qua han
{
	nodeBAR *b = p->data.dsmt.head;
	int total = 0;
	for (int i = 0; i < p->data.dsmt.size; i++)
	{
		Date returnDate = b->data.ReturnDate;
		if (returnDate.day == 0 || returnDate.month == 0 || returnDate.year == 0)
		{
			b = b->next;
		}
		else
		{
			if (compareDate(b->data.ReturnDate))
			{
				total += countOverdueDay(b->data.ReturnDate);
			}
			b = b->next;
		}
	}
	return total;
}

int checkBorrowed(TableOfContent *p)//kiem tra con sach de muon khong
{
	int n = p->dms.size;
	nodeB *tmp = p->dms.head;
	for (int i = 0; i < n; i++)
	{
		if (tmp->data.BookStatus == 0)
		{
			return 0;
		}
		tmp = tmp->next;
	}
	return 1;
}

Date HandleLogicalTime(Date time)//xu li thoi gian theo dung logic
{
	time.day += 7;
	if (time.day > convertMonthtoDay(time.month) && time.month < 12)
	{
		time.day = time.day - convertMonthtoDay(time.month);
		time.month++;
	}
	else if (time.day > convertMonthtoDay(time.month) && time.month == 12)
	{
		time.month = 1;
		time.day = time.day - convertMonthtoDay(12);
		time.year++;
	}
	return time;
}

int addBorrowedBook(BorrowAndReturnList &dsmt, nodeBAR *p)//muonn sach
{
	if (dsmt.size >= 3)
	{
		return 0;
	}
	if (p->data.BorrowDate.day == 0)
	{
		p->data.BorrowDate = currentTime();
	}
	p->data.ReturnDate = HandleLogicalTime(p->data.BorrowDate);
	if (dsmt.size == 0)
	{
		dsmt.head = p;
		dsmt.tail = p;
		dsmt.size++;
		return 1;
	}
	else
	{
		dsmt.tail->next = p;
		dsmt.tail = p;
		dsmt.size++;
		return 1;
	}
	return 0;
}

int returnedBook(BorrowAndReturnList &dsmt, nodeBAR *p)//tra sach
{
	if (dsmt.size == 0)
	{
		return 0;
	}
	nodeBAR *tmp = dsmt.head;
	while (tmp != nullptr)
	{
		if (tmp == p)
		{
			if (tmp == dsmt.head)
			{
				dsmt.head = tmp->next;
				dsmt.size--;
				delete tmp;
				return 1;
			}
			else if (dsmt.tail == p)
			{
				nodeBAR *prev = dsmt.head;
				while (prev->next != p)
				{
					prev = prev->next;
				}

				dsmt.tail = prev;
				dsmt.tail->next = nullptr;
				delete p;
				dsmt.size--;

				if (dsmt.size == 0)
				{
					dsmt.head = dsmt.tail = nullptr;
				}

				return 1;
			}
			else
			{
				nodeBAR *prev = dsmt.head;
				while (prev->next != tmp)
				{
					prev = prev->next;
				}
				prev->next = tmp->next;
				delete tmp;
				dsmt.size--;
				return 1;
			}
		}
		tmp = tmp->next;
	}
	return 0;
}

int addNodeBook(BookList &l, Book data)//them sach vao danh muc sach
{
	nodeB *p = makeNodeBook(data);
	if (l.head == nullptr)
	{
		l.head = p;
		l.tail = p;
		++l.size;
		return 1;
	}
	else
	{
		nodeB *preB = l.head;
		if (p->data.BookID >= l.head->data.BookID)
		{
			p->next = l.head;
			l.head = p;
			++l.size;
			return 1;
		}
		for (nodeB *i = l.head; i->next != nullptr; i = i->next) // duyet tu dau toi cuoi
		{
			if (p->data.BookID >= i->data.BookID) // khi id cua sach can them >id cua i thi chen p truoc i
			{
				p->next = i;
				preB->next = p;
				++l.size;
				return 1;
			}
		}
		// khi khong co phan tu nao co id >p
		l.tail->next = p;
		l.tail = p;
		++l.size;
		return 1;
	}
	return 0;
}

string createID(string *notusedid, int n) // tao ID doc gia
{

	string s = notusedid[0];
	for (int i = 0; i < n - 1; i++)
	{
		notusedid[i] = notusedid[i + 1];
	}
	return s;
}

void releaseID(string *notusedid, int &n, string ID) // tra lai id sau khi xoa de dung cho lan sau
{
	notusedid[n] = ID;
	n++;
}

int treeLevel(nodeRC *t) // tim do cao cua node
{
	if (t == nullptr)
		return -1;
	if (t->left == nullptr && t->right == nullptr)
		return 1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}
bool checkAvl(nodeRC *root) // kiem tra cay la AVL hay chua
{
	if (root == nullptr)
		return true;
	if (abs(treeLevel(root->left) - treeLevel(root->right)) > 1)
		return false;
	return checkAvl(root->left) && checkAvl(root->right);
}
nodeRC *turnRight(nodeRC *a) // xoay phai
{
	nodeRC *b = a->left;
	nodeRC *c = b->right;
	a->left = c;
	b->right = a;
	return b;
}
nodeRC *turnLeft(nodeRC *a) // xoay trai
{
	nodeRC *b = a->right;
	nodeRC *c = b->left;
	a->right = c;
	b->left = a;
	return b;
}

nodeRC *updateTreeAvl(nodeRC *root)//cap nhat cay avl
{
	if (root == nullptr)
		return root;
	else if (checkAvl(root))
		return root;

	int balance = height(root->left) - height(root->right);

	if (balance > 1)
	{
		if (height(root->left->left) >= height(root->left->right))
		{
			root = turnRight(root);
		}
		else
		{
			root->left = turnLeft(root->left);
			root = turnRight(root);
		}
	}
	else if (balance < -1)
	{
		if (height(root->right->right) >= height(root->right->left))
		{
			root = turnLeft(root);
		}
		else
		{
			root->right = turnRight(root->right);
			root = turnLeft(root);
		}
	}

	root->left = updateTreeAvl(root->left);
	root->right = updateTreeAvl(root->right);

	return root;
}

int addNodeReader(ReaderList &l, Reader& data)//them node reader
{
	nodeRC *p = makeNodeReader(data);
	if (TotalOverdue(p) > 0)
	{
		p->data.CardStatus = 0;
	}
	if (p->data.ID == "")
	{
		p->data.ID = createID(l.notusedid, MAX - l.size);
		data.ID=p->data.ID;
	}
	if (l.head == nullptr)
	{
		l.head = p;
		++l.size;
		return 1;
	}
	else
	{
		string newID = p->data.ID;
		nodeRC *tmp = l.head;

		while (tmp != nullptr)
		{
			string ID = tmp->data.ID;
			if (ID > newID)
			{
				if (tmp->left == nullptr)
				{
					tmp->left = p;
					++l.size;
					return 1;
				}
				tmp = tmp->left;
			}
			else if (ID < newID)
			{
				if (tmp->right == nullptr)
				{
					tmp->right = p;
					++l.size;
					return 1;
				}
				tmp = tmp->right;
			}
			else
			{
				delete p;
				return 0;
			}
		}
	}
	return 0;
}

int findReaderByName(nodeRC *tmp[], nodeRC *t[], int n, string name)//tim doc gia bang ten
{
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		string s = tmp[i]->data.FirstName + tmp[i]->data.LastName;
		if (s.find(name) != std::string::npos)
		{
			t[size++] = tmp[i];
		}
	}
	return size;
}

nodeRC *findmin(nodeRC *root)//tim min
{
	if (root->left == nullptr)
		return root;

	while (root->left != nullptr)
	{
		root = root->left;
	}
	return root;
}

nodeRC *findReader(nodeRC *root, string id)//tim doc gia
{
	if (root == nullptr)
		return nullptr;
	else
	{
		if (root->data.ID == id)
			return root;
		else if (root->data.ID < id)
			return findReader(root->right, id);
		else
			return findReader(root->left, id);
	}
}

nodeRC *findprenode(nodeRC *root, nodeRC *p)//tim node truoc node can xu li
{
	if (root == p)
		return nullptr;
	if (root == nullptr)
		return nullptr;
	nodeRC *pre = root;
	if (pre != nullptr)
	{
		while (pre->left != nullptr && pre->right != nullptr)
		{
			if (pre->left == p || pre->right == p)
				break;
			else if (pre->data.ID > p->data.ID)
			{
				pre = pre->left;
			}
			else
			{
				pre = pre->right;
			}
		}
		return pre;
	}
	else
		return nullptr;
}

nodeRC *deletenode(nodeRC *p)//xoa node
{
	if (p->left == nullptr && p->right == nullptr)
	{
		return nullptr;
	}
	else if (p->left == nullptr)
	{
		nodeRC *a = p->right;
		delete p;
		return a;
	}
	else if (p->right == nullptr)
	{
		nodeRC *a = p->left;
		delete p;
		return a;
	}
	else
	{
		nodeRC *tmp = findmin(p->right);
		p->data.ID = tmp->data.ID;
		p->data.FirstName = tmp->data.FirstName;
		p->data.LastName = tmp->data.LastName;
		p->data.Gender = tmp->data.Gender;
		p->data.CardStatus = tmp->data.CardStatus;
		p->data.dsmt = tmp->data.dsmt;
		nodeRC *pre = findprenode(p->right, tmp);
		if (pre == nullptr)
			p->right = deletenode(tmp);
		else
		{
			pre->left = tmp->right;
			delete tmp;
		}
		return p;
	}
}

string findBookName(TableOfContentList tl, string id)//tim ten sach ID
{
	string isbn = "";
	for(int i = 0; i < 4; i++){
		isbn += id[i];
	}
	for (int i = 0; i < tl.size; i++)
	{
		if (tl.ds[i]->ISBN == isbn)
		{
			return tl.ds[i]->BookName;
		}
	}
	return "";
}
