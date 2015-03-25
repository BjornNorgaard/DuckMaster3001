#ifndef SUPERUSER_H_
#define SUPERUSER_H_

#include"Person.h"

class SuperUser : public Person {
public:
	SuperUser(string firstName, string lastName);
	virtual void setBrugerInfo(string, string);
	virtual void getBrugerInfo(string&, string&);
	virtual bool addPills(string, int);
	virtual bool deletePills(string, int);
	virtual void printPills();
	//virtual ~SuperUser();
private:
	virtual void setUserLevel();
};

#endif // _SUPERUSER_H_
