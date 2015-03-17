#include "Person.h"
#include "LLToolkit.h"

//Struct til at indeholde info om hvilke piller hver person skal have og hvor mange
struct Pilledata {
	string Pilletype;
	int antal;
};

class User : public Person {
public:
	User( string firstName, string lastName, string cprNummer );
	bool addPiller(string, int);
	bool getPiller(string&, int&);
	bool deletePiller(string, int);
	virtual int getBrugerinfo();
	virtual void setBrugerinfo(string firstName, string lastName, string cprNummer);
	void printUserInfo();
	virtual ~User();
private:
	LLToolkit<Pilledata> PilleListe;
	string cprNummer;
};