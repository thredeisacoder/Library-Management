#include "Student.cpp"

using namespace std;

class StudentClass : public Student
{
	private:
		char* ClassID;
		Student** ListStu;
		int NumOfStu;
	public:
		StudentClass()
		{
			this->ClassID=new char[15];
			this->ListStu=new Student*[100];
			for(int i=0;i<99;i++)
			{
				this->ListStu[i]=new Student;
			}
			this->NumOfStu=0;
		}
		StudentClass(char* ClassID,Student** ListStu,int NumOfStu)
		{
			this->ClassID=ClassID;
			this->ListStu=ListStu;
			this->NumOfStu=NumOfStu;
		}
		~StudentClass()
		{
			delete this->ClassID;
			for(int i=0;i<n;i++)
			{
				delete this->ListStu[i];
			}
			delete this->ListStu;
			delete this->NumOfStu;
		}
		
		
}
