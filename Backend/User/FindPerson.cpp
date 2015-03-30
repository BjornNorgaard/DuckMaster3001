#include <iostream>
#include "FindPerson.h"

using namespace std;

FindPerson::FindPerson() {
    //Create linkedlist by going through text file and add all previously added users
    // if no previously added users FindPerson() will create an empty node
    headPtr_ = NULL;
    tailPtr_ = NULL;
}

bool FindPerson::addPerson(string cprNumber, string firstName, string lastName, int userLevel) {
    Person *newUser;

    switch(userLevel) {
        case 1:
            newUser = new User(firstName, lastName, cprNumber);
            cout << "New user created." << endl;
            break;
        case 2:
            newUser = new Supporter(firstName, lastName);
            cout << "New supporter created." << endl;
            break;
        case 3:
            newUser = new SuperUser(firstName, lastName);
            cout << "New superuser created." << endl;
            break;
        default:
            cout << "Unknown user level.." << endl;
            break;
    }

    pTool_.headInsert(headPtr_, newUser);
    return true;
}

bool FindPerson::deletePerson(string cprNumber) {
    Node<Person*>* foundPtr;
    if (findPersonInList(cprNumber, foundPtr) == false) return false;

    delete foundPtr->info;

    if (foundPtr == headPtr_) {
        pTool_.headRemove(foundPtr);
    } else {
        pTool_.remove(foundPtr);
    }

    return true;
}

bool FindPerson::changePersonInfo(string cprNumber) {
    //findPersonInList();
    return true;
}

bool checkForTakenPills() {
    cout << "Sure." << endl;
    return true;
}

bool FindPerson::findPersonInList(string cprNumber, Node<Person*>*& nodePtr) {
    Node<Person*>* headPtr = headPtr_;
    string cpr;

    while (headPtr != NULL) {
        headPtr->info->getCPR(cpr);
        if (cpr == cprNumber) { return true; }
       
        if (headPtr->next != NULL) {
            headPtr->next->info->getCPR(cpr);
            if (cpr == cprNumber) { return true; }
        }
        
        headPtr = headPtr->next;
    }

    return false;
}

void FindPerson::printUsers() {
    Node<Person*>* headPtr = headPtr_;

    string cprNumber;
    string firstName;
    string lastName;

    cout << "Users in the system: " << endl;
    while (headPtr != NULL) {
        headPtr->info->getCPR(cprNumber);
        headPtr->info->getName(firstName, lastName);
        
        cout << cprNumber << " " << firstName << " " << lastName << endl;       

        headPtr = headPtr->next;        
    }    
}
