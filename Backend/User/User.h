#include "Person.h"
#include "LLToolkit.h"
#include <string>

using namespace std;

//Struct til at indeholde info om hvilke piller hver person skal have og hvor mange
struct Pilledata {
	string Pilletype;
	int antal;
};

class User : public Person {
public:
	User(string firstName, string lastName, string cprNumber);
	void addPills(string, int);
	void printPills();
	bool deletePills(string, int);
	virtual void getBrugerInfo(string& firstName, string& lastName, string& cprNumber);
	virtual void setBrugerInfo(string firstName, string lastName, string cprNumber);
	virtual void printUserInfo();
	//virtual ~User();


private:
	virtual void setUserLevel();
	LLToolkit<Pilledata> PilleListe_;
	Pilledata Piller_;
	Node<Pilledata>* headPtr_;
	Node<Pilledata>* tailPtr_;
	string cprNumber_;
};