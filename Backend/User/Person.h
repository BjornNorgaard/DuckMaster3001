#ifndef PERSON_H_
#define PERSON_H_

#include<string>

using namespace std;

class Person {
protected:
	Person(string firstName = "NaN", string lastName = "NaN");
public:
	virtual void getBrugerInfo(string&, string&);
	virtual void setBrugerInfo(string, string);
	virtual void setUserLevel(int);
	virtual void addPills(string, int) = 0;
	virtual void printPills() = 0;
	virtual bool deletePills(string, int) = 0;
	int getUserLevel();
	virtual void printUserInfo() = 0;
	//virtual ~Person();

private:
	int userLevel_;
	string firstName_;
	string lastName_;
};

#endif // PERSON_H_