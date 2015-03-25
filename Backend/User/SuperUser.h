#include"Person.h"

class SuperUser : public Person {
public:
	SuperUser(string firstName, string lastName, string jobTitel);
	virtual void setBrugerInfo(string, string, string);
	virtual void getBrugerInfo(string&, string&, string&);
	virtual void addPills();
	virtual void printPills();
	virtual bool deletePills();
	//virtual ~SuperUser();
private:
	virtual void setUserLevel();
	string jobTitel_;
};