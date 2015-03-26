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
    bool addPerson(string firstName, string lastName, int userLevel);
    bool deletePerson();
    bool changePersonInfo();
    bool checkForTakenPills();
    void printUsers();
private:
    //LLToolkit<Person> PersonList_;
    LLToolkit<Person>* pTools_;
    Node<Person>* headPtr_;
    Node<Person>* tailPtr_;
    bool findPersonInList();
};

#endif // FINDPERSON_H_
