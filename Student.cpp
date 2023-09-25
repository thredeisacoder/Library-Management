#include <iostream>

using namespace std;

struct Student
{
	private:
	char* ID;
	char* FirstName ;
	char* LastName;
	char* PhoneNum;
	char* ClassID;
	
	public:
	Student(){
		this->ID=new char[15]; 
		this->FirstName=new char[18]; 
		this->LastName=new char[7]; 
		this->PhoneNum=new char[10];
		this->ClassID=new char[15];
	}
	Student(char* ID,char* FirstName,char* LastName,char* PhoneNum,char* ClassID)
	{
		this->ID=ID;
		this->FirstName=FirstName;
		this->LastName=LastName;
		this->PhoneNum=PhoneNum;
		this->ClassID=ClassID;
	}
	~Student()
	{
		delete this->ID;
		delete this->FirstName;
		delete this->LastName;
		delete this->PhoneNum;
		delete this->ClassID;
	}
	void SetID(char* ID)
	{
		this->ID=ID;
	}
	char* GetID()
	{
		return this->ID;
	}
	void SetFisrtName(char* FirstName)
	{
		this->FirstName=FirstName;
	}
	char* GetFirstName()
	{
		return this->FirstName;
	}
	void SetLastName(char* LastName)
	{
		this->LastName=LastName;
	}
	char* GetLastName()
	{
		return this->LastName;
	}
	void SetPhoneNum(char* PhoneNum);
	{
		this->PhoneNum=PhoneNum;
	}
	char* GetPhoneNum()
	{
		return this->PhoneNum;
	}
	void SetClassID(char* ClassID)
	{
		this->ClassID=ClassID;
	}
	char* GetClassID()
	{
		return this->ClassID;
	}
	
	void display()
	{
		cout<<"ID: "<<this->ID<endl;
		cout<<"First Name: "<<this->FirstName<<endl;
		cout<<"Last Name: "<<this->LastName<<endl;
		cout<<"Phone Number: "<<this->PhoneNum<endl;
		cout<<"ClassID: "<<this->ClassID<<endl;
	}
};



