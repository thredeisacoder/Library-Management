#include <iostream>

using namespace std;

class Subject
{
	private:
		char* SID;
		char* SName ;
		char* NumOfTheoreCre;
		char* NumOfPracCre;
		
	public:
		Subject(){
			this->SID=new char[15]; 
			this->SName=new char[25];
			this->NumOfTheoreCre=new char[5]; 
			this->NumOfPracCre=new char[5];
		}
		Student(char* SID,char* SName,char* NumOfTheoreCre,char* NumOfPracCre)
		{
			this->SID=SID; 
			this->SName=SName;
			this->NumOfTheoreCre=NumOfTheoreCre;
			this->NumOfPracCre=NumOfPracCre;
		}
		~Student()
		{
			delete this->SID;
			delete this->SName;
			delete this->NumOfTheoreCre;
			delete this->NumOfPracCre;
		}
		void SetSID(char* SID)
		{
			this->SID=SID;
		}
		char* GetSID()
		{
			return this->SID;
		}
		void SetSName(char* SName)
		{
			this->SName=SName;
		}
		char* GetSName()
		{
			return this->SName;
		}
		void SetNumOfTheoreCre(char* NumOfTheoreCre);
		{
			this->NumOfTheoreCre=NumOfTheoreCre;
		}
		char* GetNumOfTheoreCre()
		{
			return this->NumOfTheoreCre;
		}
		void SetNumOfPracCre(char* NumOfPracCre)
		{
			this->NumOfPracCre=NumOfPracCre;
		}
		char* GetNumOfPracCre()
		{
			return this->NumOfPracCre;
		}
		
	void display()
	{
		cout<<"Subject ID: "<<this->SID<endl;
		cout<<"Subject Name: "<<this->FirstName<<endl;
		cout<<"Number of Theoretical Credits: "<<this->NumOfTheoreCre<<endl;
		cout<<"Number of Theoretical Credits: "<<this->NumOfPracCre<<endl;
	}
};
