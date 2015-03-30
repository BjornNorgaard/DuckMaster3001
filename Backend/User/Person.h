#ifndef PERSON_H_
#define PERSON_H_

#include <string>

using namespace std;

class Person {
protected:
    Person(string cprNumber = "000000-0000", string firstName = "NaN", string lastName = "NaN");
public:
    virtual void getName(string&, string&);
    virtual void setName(string, string);
    virtual void getCPR(string&);
    virtual void setCPR(string);
    virtual void setUserLevel(int);
    virtual bool addPills(string, int) = 0;
    virtual bool deletePills(string, int) = 0;
    virtual void printPills() = 0;
    int getUserLevel();
    virtual void printUserInfo();
    //~Person();
private:
    int userLevel_;
    string firstName_;
    string lastName_;
    string cprNumber_;
};

#endif // PERSON_H_
