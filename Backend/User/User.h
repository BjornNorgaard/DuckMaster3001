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
    User(string cprNumber, string firstName, string lastName);
    virtual bool addPills(string, int);
    virtual void printPills();
    virtual bool deletePills(string, int);
    virtual void getBrugerInfo(string& cprNumber, string& firstName, string& lastName);
    virtual void setBrugerInfo(string cprNumber, string firstName, string lastName);
    virtual void printUserInfo();
    //virtual ~User();
private:
    virtual void setUserLevel();
    LLToolkit<Pilledata> PilleListe_;
    Pilledata Piller_;
    Node<Pilledata>* headPtr_;
};
