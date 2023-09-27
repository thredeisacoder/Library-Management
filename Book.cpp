#pragma once

class Book{
public:
    string BookID;
    int BookStatus;

	Book(){
	}
	Book(string BookID,int BookStatus)
	{
		this->BookID=BookID;
		this->BookStatus=BookStatus;
	}
};
