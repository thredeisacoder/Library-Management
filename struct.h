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
	string BookID;
	int BookStatus;
	string BookLocation;
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
void generateID(BookList &bookList)
{
	int min = 1000;
	int max = 10000;
	string a[MAX] = {"DA"};
	bool b[MAX] = {false};
	srand(time(0)); // Sử dụng thời gian hiện tại làm seed

	nodeB *p = bookList.head;
	int i = min;

	while (p && i < max)
	{
		int tmp;
		do
		{
			tmp = rand() % (max - min) + min;
		} while (b[tmp]);
		a[i] = "DA" + to_string(tmp);
		b[tmp] = true;

		p->data.BookID = a[i]; // Gán BookID cho cuốn sách trong danh sách
		p = p->next;
		i++;
	}
}

BookList *createBookList()
{
	BookList *list = new BookList;

	for (int i = 0; i < list->random; i++)
	{
		nodeB *newNode = new nodeB;
		generateID(*list);
		newNode->data.BookStatus = 0;
		newNode->data.BookLocation = " " + to_string(i);
		if (list->tail == nullptr) {
            list->head = newNode;
            list->tail = newNode;
        } else {
            list->tail->next = newNode;
            list->tail = newNode;
        }
	}
	return list;
}

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
	TableOfContent *ds[MAX] = {NULL};
	int size = 0;
};
void releaseMemory(TableOfContentList &data)
{
	for (int i = 0; i < data.size; i++)
	{
		delete data.ds[i];
		data.ds[i] = nullptr; // Đặt con trỏ thành nullptr để tránh truy cập bộ nhớ sau khi giải phóng
	}
	data.size = 0; // Đặt kích thước về 0 để đánh dấu danh sách rỗng
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

TableOfContent *searchByName(TableOfContentList tl, string input)
{
	for (int i = 0; i < tl.size; i++)
		if (tl.ds[i]->BookName == input)
		{
			return tl.ds[i];
		}
	return NULL;
}

TableOfContentList saveToSearch(TableOfContentList tl, string input)
{
	TableOfContentList tmp;
	int index = 0;
	for (int i = 0; i < tl.size; i++)
	{
		if (tl.ds[i]->BookName == input)
		{
			tmp.size++;
			tmp.ds[index] = tl.ds[i];
			index++;
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
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////

nodeB *makeNodeBook(Book data)
{
	nodeB *p = new nodeB;
	p->data = data;
	p->next = NULL;
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
		for (nodeB *i = l.head; i != nullptr; i = i->next) // duyet tu dau toi cuoi
		{
			if (p->data.BookID >= i->data.BookID) // khi id cua sach can them >id cua i thi chen p truoc i
			{
				p->next = i;
				preB->next = p;
				++l.size;
				return 1;
			}
			else // neu khong thi cap nhat phan tu pre va i
			{
				preB = i;
				i = i->next;
			}
		}
		// khi khong co phan tu nao co id >p
		l.tail->next = p;
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

void loadfileID(string* usedID,string* notusedID,int&ul,int&nl)//cap nhat 2 file id
{
	fstream f("idrcnotused.txt",ios::in);
	if(f.is_open())
	{
		string l="";
		while(!f.eof())
		{
			getline(f,l);
			if(!l.empty()) notusedID[nl++]=l;
		}
		f.close();
	}
	
	f.open("idrcused.txt",ios::in);
	if(f.is_open())
	{
		string s="";
		while(!f.eof())
		{
			getline(f,s);
			if(!s.empty())	usedID[ul++]=s;
		}
		f.close();
	}
}

void savefileID(string* usedID,string* notusedID,int ul,int nl)//luu lai 2 file ID
{
	fstream f("idrcnotused.txt",ios::out);
	for(int i=0;i<nl;i++)
	{
		f<<notusedID[i]<<endl;
	}
	f.close();
	f.open("idrcused.txt",ios::out);
	for(int i=0;i<ul;i++)
	{
		f<<usedID[i]<<endl;
	}
	f.close();
}

string createID()//tao ID doc gia
{
	string *usedID=new string[MAX];
	string *notusedID=new string[MAX];
	int ul=0,nl=0;
	loadfileID(usedID,notusedID,ul,nl);

	string s=notusedID[0];

	for(int i=0;i<nl-1;i++)
	{
		notusedID[i]=notusedID[i+1];
	}
	nl--;
	for(int i=0;i<ul;i++)
	{
		if(s<usedID[i])
		{
			for(int j=ul;j>i;j--)
			{
				usedID[j]=usedID[j-1];
			}
			usedID[i]=s;
			ul++;
			break;
		}
		else if(i==ul-1)
		{
			 usedID[ul]=s;
			 ul++;
		}
	}
	savefileID(usedID,notusedID,ul,nl);
	delete[] usedID;
	delete[] notusedID;
	return s;
}

/*string makeID(nodeRC *pre, nodeRC *p)
{
	string s = "";
	int n = 0;
	for (int i = 0; i < 5; i++)
	{
		int x = int(pre->data.ID[pre->data.ID.length() - 1 - i] - '0');
		n = n + pow(10, i) * x;
	}

	n++;

	while (s.length() < 5)
	{
		s = char(n % 10 + '0') + s;
		n /= 10;
	}
	return s;
}*/

int treeLevel(nodeRC *t)//tim do cao cua node
{
	if (t == nullptr) return -1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}
bool checkAvl(nodeRC* root)//kiem tra cay la AVL hay chua
{
	if (root == NULL) 	return true;
	if (abs(treeLevel(root->left) - treeLevel(root->right)) > 1) return false;
	return checkAvl(root->left) && checkAvl(root->right);
}
nodeRC *turnRight(nodeRC *a)//xoay phai
{
	nodeRC *b = a->left;
	nodeRC *d = b->right;
	a->left = d;
	b->right = a;
	return b;
}
nodeRC *turnLeft(nodeRC *a)//xoay trai
{
	nodeRC *b = a->right;
	nodeRC *c = b->left;
	a->right = c;
	b->left = a;
	return b;
}

nodeRC *updateTreeAvl(nodeRC *t)//dieu chinh cay thanh AVL
{
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1){
		if (treeLevel(t->left) > treeLevel(t->right)){
			nodeRC *p = t->left;
			if (treeLevel(p->left) >= treeLevel(p->right)){
				t = turnRight(t);
			} else{
				t->left = turnLeft(t->left);
				t = turnRight(t);
			}
		} else {
			nodeRC *p = t->right;
			if (treeLevel(p->right) >= treeLevel(p->left)){
				t = turnLeft(t);
			} else{
				t->right = turnRight(t->right);
				t = turnLeft(t);
			
			}
		}	
	}
	if (t->left != nullptr) t->left = updateTreeAvl(t->left);
	if (t->right != nullptr) t->right = updateTreeAvl(t->right);
	return t;
}

int addNodeReader(ReaderList &l, Reader data)
{
	nodeRC *p = makeNodeReader(data);
	if (l.size == 0)
	{
		if(p->data.ID=="")p->data.ID = createID();
		l.head = p;
		++l.size;
		return 1;
	}
	else
	{
		string newName = data.LastName + data.LastName;
		nodeRC *tmp = l.head;

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
		if(p->data.ID=="")	p->data.ID = createID();
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
		if(!checkAvl(l.head)) updateTreeAvl(l.head);
	}
	return 0;
}

int deleteNodeReader(ReaderList &l, string ID)
{
	if (l.size == 0)
	{
		return 0;
	}
	nodeRC *par = nullptr;
	nodeRC *cur = l.head;

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
	if (cur == nullptr) // khong tim thay ID
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
		nodeRC *pre = nullptr;
		nodeRC *tmp = cur->left;
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
