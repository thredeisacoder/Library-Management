#include "BorrowAndReturn.cpp"

//the doc gia
class ReaderCard {
public:
    string ID;
    string Sex;
    string FirstName;
    string LastName;
    int CardStatus;
    
	BorrowAndReturn* dsmtr;
	
	ReaderCard(String ID,string Sex,string FirstName,string LastName,int CardStatus,BorrowAndReturn* dsmtr)
	{
		this->ID=ID;
		this->Sex=Sex;
		this->FirstName=FirstName;
		this->LastName=LastName;
		this->CardStatus=CardStatus;
		this->dsmtr=dsmtr;
	}
};

struct nodeReaderCard
{
	ReaderCard data;
	nodeReaderCard* left;
	nodeReaderCard* right;
};

struct ReaderCardList
{
	nodeReaderCard* head;
	int size=-1;
};

