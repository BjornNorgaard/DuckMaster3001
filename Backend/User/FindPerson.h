#ifndef FINDPERSON_H_
#define FINDPERSON_H_

#include <string>
#include "LLToolkit.h"
#include "Person.h"
#include "User.h"
#include "Supporter.h"
#include "SuperUser.h"

using namespace std;

class FindPerson {
public:
    FindPerson();
    bool addPerson(string CPR, string firstName, string lastName, int userLevel);
    bool deletePerson();
    bool changePersonInfo();
    bool checkForTakenPills();
    void printUsers();
    bool findPersonInList(Node<Person*>*& nodePtr);
private:
    LLToolkit<Person*> pTool_;
    Node<Person*>* headPtr_;
    Node<Person*>* tailPtr_;
};

#endif // FINDPERSON_H_
