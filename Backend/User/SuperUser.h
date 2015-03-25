#ifndef SUPERUSER_H_
#define SUPERUSER_H_

#include"Supporter.h"

class SuperUser : public Supporter {
public:
	SuperUser(string firstName, string lastName);
	virtual void setBrugerInfo(string, string);
	virtual void getBrugerInfo(string&, string&);
	virtual bool addPills(string, int);
	virtual void printPills();
	virtual bool deletePills(string, int);
	//virtual ~SuperUser();
private:
	
};

#endif // _SUPERUSER_H_