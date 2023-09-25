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
		Subject(char* SID,char* SName,char* NumOfTheoreCre,char* NumOfPracCre)
		{
			this->SID=SID; 
			this->SName=SName;
			this->NumOfTheoreCre=NumOfTheoreCre;
			this->NumOfPracCre=NumOfPracCre;
		}
		~Subject()
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
		void SetNumOfTheoreCre(char* NumOfTheoreCre)
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
		cout<<"Subject ID: "<<GetSID()<<endl;
		cout<<"Subject Name: "<<GetFirstName()<<endl;
		cout<<"Number of Theoretical Credits: "<<GetNumOfTheoreCre()<<endl;
		cout<<"Number of Theoretical Credits: "<<GetNumOfPracCre()<<endl;
	}
};
