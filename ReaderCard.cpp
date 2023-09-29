#include "BorrowAndReturn.cpp"
#include "process.cpp"
//the doc gia

struct ReaderCard {
    string ID;
    string Sex;
    string FirstName;
    string LastName;
    int CardStatus;
    
	BorrowAndReturn* dsmtr;

};

struct nodeRC
{
	ReaderCard data;
	nodeRC* left;
	nodeRC* right;
};

struct ReaderCardList
{
	nodeRC* head;
	int size=-1;
};

nodeRC* makeCard(ReaderCard data)
{
	nodeRC* p=new nodeRC;
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}

ReaderCard EnterInfor()
{
	ReaderCard RC;
	cout<<"\nFirst Name  : ";
	RC.FirstName=EnterName();
	cout<<"\nLast Name: ";
	RC.LastName=EnterName();
	cout<<"\nSex: ";
	RC.Sex=EnterSex();
	cout<<"\nStatus: ";
	RC.CardStatus=EnterCardStatus();
	RC.dsmtr=NULL;
	return RC;
}

nodeRC* AddReader(nodeRC* head,ReaderCard RC,int &size)
{
	if(head==NULL)
	{
		nodeRC* p=new nodeRC;
		p=makeCard(RC);
		p->data.ID=size+1;
		head=p;
		++size;
	}
	else 
	{
		if(head->data.ID>RC.ID)
		{
			head->left=AddReader(head->left,RC,size);
		}
		else
		{
			head->right=AddReader(head->right,RC,size);
		}
	}
}

nodeRC* DeleteReader(nodeRC* head,string ID,int size)
{
	if(head==NULL) return head;
	else if(head->left->data.ID==ID)
	{
		
	}
	else if(head->right->data.ID==ID)
	{
		
	}
	else
	{
		if(ID<head->data.ID)
		{
			head->left=DeleteReader(head->left,ID,size);
		}
		else
		{
			head->right=DeleteReader(head->right,ID,size);
		}
	}
}








