#ifndef SUPERUSER_H_
#define SUPERUSER_H_

#include"Supporter.h"

class SuperUser : public Supporter {
public:
	SuperUser(string firstName, string lastName);
	virtual void setBrugerInfo(string, string);
	virtual void getBrugerInfo(string&, string&);
	virtual bool addPills(string, int);
<<<<<<< HEAD
	virtual void printPills();
=======
>>>>>>> ac2d1101ad4debd1080a216349c3b1923685222f
	virtual bool deletePills(string, int);
	virtual void printPills();
	//virtual ~SuperUser();
private:
	
};

#endif // _SUPERUSER_H_
