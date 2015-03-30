#ifndef SUPPORTER_H_
#define SUPPORTER_H_

#include "Person.h"

class Supporter : public Person {
public:
    Supporter(string firstName, string lastName);
    //virtual ~Supporter();
    virtual void getBrugerInfo(string&, string&);
    virtual void setBrugerInfo(string, string);
    virtual void setUserLevel(int);
    virtual bool addPills(string, int);
    virtual bool deletePills(string, int);
    virtual void printPills();
    int getUserLevel();
    virtual void printUserInfo();
private:

};

#endif // SUPPORTER_H_
