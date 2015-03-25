#include "Person.h"
#include "LLToolkit.h"
#include <string>

using namespace std;

//Struct til at indeholde info om hvilke piller hver person skal have og hvor mange, Kunne være smart hvis pille typerne
//kommer fra en database med mulige piller.
struct Pilledata {
	string Pilletype;
	int antal;
};

class User : public Person {
public:
	User(string firstName, string lastName, string cprNumber);
	virtual void addPills(string, int);
	virtual void printPills();
	virtual bool deletePills(string, int);
	virtual void getBrugerInfo(string& firstName, string& lastName, string& cprNumber);
	virtual void setBrugerInfo(string firstName, string lastName, string cprNumber);
	virtual void printUserInfo();

	//virtual ~User();

private:
	virtual void setUserLevel();
	LLToolkit<Pilledata> PilleListe_;
	Pilledata Piller_;
	Node<Pilledata>* headPtr_;
	string cprNumber_;
};