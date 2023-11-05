#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
#include <random>
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
	nodeB *next = nullptr;
};

struct BookList
{
	nodeB *head = nullptr;
	nodeB *tail = nullptr;
	int size = 0;
	int random = rand() % 10 + 1;
};

/////////////////////////////////////////////muon tra/////////////////////////////////////////////////
struct Date
{
	int day = 0;
	int month = 0;
	int year = 0;
};

struct BorrowAndReturn
{
	string BookID = "";
	Date BorrowDate;
	Date ReturnDate;
	int Status = 0;
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
};

struct TableOfContentList
{
	TableOfContent *ds[MAX] = {nullptr};
	int size = 0;
};
void releaseMemory(TableOfContentList &data)
{
	for (int i = 0; i < data.size; i++)
	{
		delete data.ds[i];
		data.ds[i] = nullptr; // �?t con tr? th�nh nullptr d? tr�nh truy c?p b? nh? sau khi gi?i ph�ng
	}
	data.size = 0; // �?t k�ch thu?c v? 0 d? d�nh d?u danh s�ch r?ng
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

int addTail(TableOfContentList &tl, TableOfContent data)
{
	if (tl.size == MAX)
	{
		return 0;
	}
	tl.ds[tl.size] = new TableOfContent(data);
	tl.size++;
	return 1;
} // done
int themTheoThuTuTheLoai(TableOfContentList &tl, TableOfContent data)
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
TableOfContent *searchByISBN(TableOfContentList tl, string data)
{
	if (tl.size == 0)
		return NULL;
	for (int i = 0; i < tl.size; i++)
	{
		if (tl.ds[i]->ISBN == data)
		{
			TableOfContent *p = tl.ds[i];
			tl.ds[i] = NULL;
			return p;
		}
	}
	return NULL;
}
string generateID(TableOfContent *p, int i)
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

BookList createBookList(TableOfContent *p)
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
	nodeRC *left = nullptr;
	nodeRC *right = nullptr;
};

struct ReaderList
{
	nodeRC *head = nullptr;
	int size = 0;
	string *notusedid = new string[MAX];
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////

nodeB *makeNodeBook(Book data)
{
	nodeB *p = new nodeB;
	p->data = data;
	p->next = nullptr;
	return p;
}

int addNodeBook(BookList &l, Book data)
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

int deleteNodeBC(BookList &l, string ID)
{
	if (l.head == NULL) // khi danh sach rong thi ko xoa duoc
	{
		return 0;
	}
	else if (l.head->data.BookID == ID) // phan tu dau co id can xoa
	{
		nodeB *tmp = l.head;
		l.head = tmp->next;
		delete tmp;
		return 1;
	}
	else
	{
		nodeB *tmp = l.head->next;
		nodeB *pre = l.head;
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
nodeBAR *makeNodeBAR(BorrowAndReturn data)
{
	nodeBAR *p = new nodeBAR;
	p->data = data;
	return p;
}

int addNodeBAR(BorrowAndReturnList &l, BorrowAndReturn data)
{
	nodeBAR *p = makeNodeBAR(data);
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
		nodeBAR *tmp = l.head->next;
		nodeBAR *pre = l.head;
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

int deleteNodeBAR(BorrowAndReturnList &l, string ID)
{
	if (l.head == NULL) // kiem tra danh sach rong
	{
		return 0;
	}
	else if (l.head->data.BookID == ID) // khi phan tu dau co id can xoa
	{
		nodeBAR *tmp = l.head;
		l.head = l.head->next;
		delete tmp;
		return 1;
	}
	else
	{
		nodeBAR *tmp = l.head->next;
		nodeBAR *pre = l.head;
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
////////////////////////////////////////////////////////////////////////////////////////
nodeRC *makeNodeReader(Reader data)
{
	nodeRC *p = new nodeRC;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

string createID(string *notusedid, int n) // tao ID doc gia
{

	string s = notusedid[0];
	for (int i = 0; i < n; i++)
	{
		notusedid[i] = notusedid[i + 1];
	}
	return s;
}

void releaseID(string *notusedid, int n, string ID) // tra lai id sau khi xoa de dung cho lan sau
{
	notusedid[n] = ID;
}

int treeLevel(nodeRC *t) // tim do cao cua node
{
	if (t == nullptr)
		return -1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}
bool checkAvl(nodeRC *root) // kiem tra cay la AVL hay chua
{
	if (root == NULL)
		return true;
	if (abs(treeLevel(root->left) - treeLevel(root->right)) > 1)
		return false;
	return checkAvl(root->left) && checkAvl(root->right);
}
nodeRC *turnRight(nodeRC *a) // xoay phai
{
	nodeRC *b = a->left;
	nodeRC *d = b->right;
	a->left = d;
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

nodeRC *updateTreeAvl(nodeRC *t) // dieu chinh cay thanh AVL
{
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1)
	{
		if (treeLevel(t->left) > treeLevel(t->right))
		{
			nodeRC *p = t->left;
			if (treeLevel(p->left) >= treeLevel(p->right))
			{
				t = turnRight(t);
			}
			else
			{
				t->left = turnLeft(t->left);
				t = turnRight(t);
			}
		}
		else
		{
			nodeRC *p = t->right;
			if (treeLevel(p->right) >= treeLevel(p->left))
			{
				t = turnLeft(t);
			}
			else
			{
				t->right = turnRight(t->right);
				t = turnLeft(t);
			}
		}
	}
	if (t->left != nullptr)
		t->left = updateTreeAvl(t->left);
	if (t->right != nullptr)
		t->right = updateTreeAvl(t->right);
	return t;
}

int addNodeReader(ReaderList &l, Reader data)
{
	nodeRC *p = makeNodeReader(data);
	if (p->data.ID == "")
		p->data.ID = createID(l.notusedid, MAX - l.size);
	if (l.size == 0)
	{
		l.head = p;
		++l.size;
		return 1;
	}
	else
	{
		string newID = p->data.ID;
		nodeRC *tmp = l.head;

		while (tmp->left != nullptr && tmp->right != nullptr)
		{
			string ID = tmp->data.ID;
			if (ID > newID)
			{
				tmp = tmp->left;
			}
			else if (ID < newID)
			{
				tmp = tmp->right;
			}
			else
			{
				delete p;
				return 0;
			}
		}
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
		if (!checkAvl(l.head))
			updateTreeAvl(l.head);
	}
}

nodeRC* findMinIDNode(nodeRC* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

nodeRC* deleteNodeReader(nodeRC* root, string ID) {
    if (root == nullptr) {
        return root;
    }

    if (ID < root->data.ID) {
        root->left = deleteNodeReader(root->left, ID);
    } else if (ID > root->data.ID) {
        root->right = deleteNodeReader(root->right, ID);
    } else {
        if (root->left == nullptr) {
            nodeRC* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            nodeRC* temp = root->left;
            delete root;
            return temp;
        }

        nodeRC* minIDNode = findMinIDNode(root->right);
        root->data.ID = minIDNode->data.ID;
        root->right = deleteNodeReader(root->right, minIDNode->data.ID);
    }
	if(!checkAvl(root)) updateTreeAvl(root);
    return root;
}

// void releaseID(vector<int> &notusedid, int MAX, string id)
// {
// 	for (int i = 0; i < notusedid.size(); i++)
// 	{
// 		if (id == to_string(notusedid[i]))
// 		{
// 			notusedid.erase(notusedid.begin() + i);
// 			break;
// 		}
// 	}
// }