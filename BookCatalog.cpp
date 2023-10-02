#include "Book.cpp"

using namespace std;
//danh muc sach

struct BookCatalog 
{
	Book book;
    string BookLocation;
};

struct nodeBC
{
	BookCatalog data;
	nodeBC* next;
};

struct BookCatalogList
{
	nodeBC* head=NULL;
	nodeBC* tail=NULL;
	int size=-1;
};

nodeBC* makenode(BookCatalog data)
{
	nodeBC* p=new nodeBC;
	p->data=data;
	p->next=NULL;
	return p;
}
//them danh muc sach
BookCatalogList addNodeBC(BookCatalogList l,BookCatalog data)
{
	if(l.head==NULL)
	{
		l.head=makenode(data);
		l.tail=l.head;
	}
	else
	{
		l.tail->next=makenode(data);
	}
	return l;
}
// delete with ID
BookCatalogList deleteNodeBC(BookCatalogList l,string ID)
{
	if(l.head==NULL)
	{
		return l;
	}
	nodeBC* tmp=l.head;
	if(l.head->data.book.BookID==ID)
	{
		l.head=l.head->next;
		delete tmp;
	}
	else
	{
		while(tmp->next!=NULL)
		{
			tmp=tmp->next;
			if(tmp->next->data.book.BookID==ID)
			{
				nodeBC* t=tmp->next;
				tmp->next=t->next;
				delete t;
			}
		}
	}
	return l;
}


