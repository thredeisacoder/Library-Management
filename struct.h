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
/////////////////////////////////////////////Danh muc sach/////////////////////////////////////////////////
struct nodeB
{
	Book data;
	nodeB* next = nullptr;
};

struct BookList
{
	nodeB* head = nullptr;
	nodeB* tail = nullptr;
	int size = 0;
};

///////////////////////////////////////////////dau sach/////////////////////////////////
struct TableOfContent
{
	string ISBN;
	string BookName;
	string NumOfPage;
	string Author;
	string PublicYear;
	string Genre;

	BookList dms;
	int BorrowTotal=0;
};

struct TableOfContentList
{
	TableOfContent* ds[MAX] = { nullptr };
	int size = 0;
};
void releaseMemory(TableOfContentList& data)
{
	for (int i = 0; i < data.size; i++)
	{
		delete data.ds[i];
		data.ds[i] = nullptr; // ??t con tr? th?nh nullptr d? tr?nh truy c?p b? nh? sau khi gi?i ph?ng
	}
	data.size = 0; // ??t k?ch thu?c v? 0 d? d?nh d?u danh s?ch r?ng
}

int compare(TableOfContentList tl, TableOfContent data)
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

int addTail(TableOfContentList& tl, TableOfContent data)
{
	if (tl.size == MAX)
	{
		return 0;
	}
	tl.ds[tl.size] = new TableOfContent(data);
	tl.size++;
	return 1;
} // done
int themTheoThuTuTheLoai(TableOfContentList& tl, TableOfContent data)
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
		tl.ds[locate] = new TableOfContent(data);
		tl.size++;
	}
	else
	{
		return 0;
	}
	return 1;
} // done

// TableOfContent *searchByName(TableOfContentList tl, string input)
// {
// 	for (int i = 0; i < tl.size; i++)
// 		if (tl.ds[i]->BookName.find(input))
// 		{
// 			return tl.ds[i];
// 		}
// 	return NULL;
// }

TableOfContentList saveToSearch(TableOfContentList tl, string input)
{
	TableOfContentList tmp;
	int index = 0;
	for (int i = 0; i < tl.size; i++)
	{
		if (!tl.ds[i]->BookName.find(input)) // tim ten sach chua chuoi nguoi dung nhap
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
// TableOfContent* searchByISBN(TableOfContentList tl, string data)
// {
// 	if (tl.size == 0)
// 		return NULL;
// 	for (int i = 0; i < tl.size; i++)
// 	{
// 		if (tl.ds[i]->ISBN == data)
// 		{
// 			TableOfContent* p = tl.ds[i];
// 			tl.ds[i] = NULL;
// 			return p;
// 		}
// 	}
// 	return NULL;
// }
string generateID(TableOfContent* p, int i)
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

BookList createBookList(TableOfContent* p)
{
	BookList* list = new BookList;
	for (int i = 0; i < p->dms.size; i++)
	{
		nodeB* newNode = new nodeB;
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

/////////////////////////////////////////////muon tra/////////////////////////////////////////////////
struct Date
{
	int day = 0;
	int month = 0;
	int year = 0;
};

struct BorrowAndReturn
{
	string bookID="";
	Date BorrowDate;
	Date ReturnDate;
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

Date currentTime(){
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
int addBorrowedBook(BorrowAndReturnList& dsmt, nodeBAR* p)
{
	if (dsmt.size >= 3) {
		return 0;
	}
	if(p->data.BorrowDate.day==0)	p->data.BorrowDate = borrowTime();
	// newNode->data.ReturnDate = ... ; thoi gian tra
	if (dsmt.size == 0) {
		dsmt.head = p;
		dsmt.tail = p;
		dsmt.size++;
		return 1;
	}
	else {
		dsmt.tail->next = p;
		dsmt.tail = p;
		dsmt.size++;
		return 1;
	}
	return 0;
}
int returnedBook(BorrowAndReturnList& dsmt, nodeBAR* p) {
	if (dsmt.size == 0) {
		return 0;
	}
	nodeBAR* tmp = dsmt.head;
	while (tmp != nullptr) {
		if (tmp==p) 
		{
			if (tmp == dsmt.head) 
			{
				dsmt.head = tmp->next;
				dsmt.size--;
				delete tmp;
				return 1;
			}
			else if (tmp == dsmt.tail) {
				if (dsmt.head->next == tmp) {
					dsmt.tail = dsmt.head;
				}
				else {
					dsmt.tail = dsmt.head->next;
				}
				dsmt.size--;
				delete tmp;
				return 1;
			}
			else {
				dsmt.head->next = dsmt.tail;
				dsmt.size--;
				delete tmp;
				return 1;
			}
		}
		tmp = tmp->next;
	}
	return 0;
}
/////////////////////////////////////////////DOC GIA/////////////////////////////////////////////////
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
	nodeRC* left = nullptr;
	nodeRC* right = nullptr;
};

struct ReaderList
{
	nodeRC* head = nullptr;
	int size = 0;
	string* notusedid = new string[MAX];
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////

nodeB* makeNodeBook(Book data)
{
	nodeB* p = new nodeB;
	p->data = data;
	p->next = nullptr;
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
		for (nodeB* i = l.head; i->next != nullptr; i = i->next) // duyet tu dau toi cuoi
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

int deleteNodeBC(BookList& l, string ID)
{
	if (l.head == NULL) // khi danh sach rong thi ko xoa duoc
	{
		return 0;
	}
	else if (l.head->data.BookID == ID) // phan tu dau co id can xoa
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
////////////////////////////////////////////////////////////////////////////////////////
nodeRC* makeNodeReader(Reader data)
{
	nodeRC* p = new nodeRC;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

string createID(string* notusedid, int n) // tao ID doc gia
{

	string s = notusedid[0];
	for (int i = 0; i < n - 1; i++)
	{
		notusedid[i] = notusedid[i + 1];
	}
	return s;
}

void releaseID(string* notusedid, int n, string ID) // tra lai id sau khi xoa de dung cho lan sau
{
	notusedid[n] = ID;
}

int treeLevel(nodeRC* t) // tim do cao cua node
{
	if (t == nullptr) return -1;
	if (t->left == nullptr && t->right == nullptr) return 1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}
bool checkAvl(nodeRC* root) // kiem tra cay la AVL hay chua
{
	if (root == nullptr)	return true;
	if (abs(treeLevel(root->left) - treeLevel(root->right)) > 1) return false;
	return checkAvl(root->left) && checkAvl(root->right);
}
nodeRC* turnRight(nodeRC* a) // xoay phai
{
	nodeRC* b = a->left;
	nodeRC* c = b->right;
	a->left = c;
	b->right = a;
	return b;
}
nodeRC* turnLeft(nodeRC* a) // xoay trai
{
	nodeRC* b = a->right;
	nodeRC* c = b->left;
	a->right = c;
	b->left = a;
	return b;
}

int height(nodeRC* t) {
	if (t == nullptr) return -1;
	return max(height(t->left), height(t->right)) + 1;
}

nodeRC* updateTreeAvl(nodeRC* root)
{
	if (root == nullptr) return root;
	else if (checkAvl(root)) return root;

	int balance = height(root->left) - height(root->right);

	if (balance > 1) {
		if (height(root->left->left) >= height(root->left->right)) {
			root = turnRight(root);
		}
		else {
			root->left = turnLeft(root->left);
			root = turnRight(root);
		}
	}
	else if (balance < -1) {
		if (height(root->right->right) >= height(root->right->left)) {
			root = turnLeft(root);
		}
		else {
			root->right = turnRight(root->right);
			root = turnLeft(root);
		}
	}

	root->left = updateTreeAvl(root->left);
	root->right = updateTreeAvl(root->right);

	return root;
}

int addNodeReader(ReaderList& l, Reader data)
{
	nodeRC* p = makeNodeReader(data);
	if (p->data.ID == "") p->data.ID = createID(l.notusedid, MAX - l.size);
	if (l.head == nullptr)
	{
		l.head = p;
		++l.size;
		return 1;
	}
	else
	{
		string newID = p->data.ID;
		nodeRC* tmp = l.head;

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


nodeRC* findmin(nodeRC* root)
{
	if (root->left == nullptr) return root;

	while (root->left != nullptr)
	{
		root = root->left;
	}
	return root;
}

nodeRC* findReader(nodeRC* root, string id)
{
	if (root == nullptr) return nullptr;
	else
	{
		if (root->data.ID == id) return root;
		else if (root->data.ID < id) return findReader(root->right, id);
		else return findReader(root->left, id);
	}
}

nodeRC* findprenode(nodeRC* root, nodeRC* p)
{
	if (root == p) return nullptr;
	if (root == nullptr) return nullptr;
	nodeRC* pre = root;
	if (pre != nullptr)
	{
		while (pre->left != nullptr && pre->right != nullptr)
		{
			if (pre->left == p || pre->right == p) break;
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
	else return nullptr;
}

nodeRC* deletenode(nodeRC* p)
{
	if (p->left == nullptr && p->right == nullptr)
	{
		return nullptr;
	}
	else if (p->left == nullptr)
	{
		nodeRC* a = p->right;
		delete p;
		return a;
	}
	else if (p->right == nullptr)
	{
		nodeRC* a = p->left;
		delete p;
		return a;
	}
	else
	{
		nodeRC* tmp = findmin(p->right);
		p->data.ID = tmp->data.ID;
		p->data.FirstName = tmp->data.FirstName;
		p->data.LastName = tmp->data.LastName;
		p->data.Gender = tmp->data.Gender;
		p->data.CardStatus = tmp->data.CardStatus;
		p->data.dsmt = tmp->data.dsmt;
		nodeRC* pre = findprenode(p->right, tmp);
		if (pre == nullptr) p->right = deletenode(tmp);
		else
		{
			pre->left = tmp->right;
			delete tmp;
		}
		return p;
	}
}
///////////////muon tra////////

string findBookName(TableOfContentList tl, string id)
{
	string isbn = "";
	isbn += id[0] + id[1] + id[2] + id[3] + id[4];
	for (int i = 0; i < tl.size; i++)
	{
		if (tl.ds[i]->ISBN == isbn)
		{
			return tl.ds[i]->BookName;
		}
	}
}

















