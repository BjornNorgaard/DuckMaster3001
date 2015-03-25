#ifndef SUPERUSER_H_
#define SUPERUSER_H_

#include "Supporter.h"

class SuperUser : public Supporter {
public:
	SuperUser(string firstName, string lastName);
	virtual void setBrugerInfo(string, string);
	virtual void getBrugerInfo(string&, string&);
	virtual bool addPills(string, int);
	virtual bool deletePills(string, int);
	virtual void printPills();
	//virtual ~SuperUser();
private:
	
};

#endif // SUPERUSER_H_
