#include <iostream>
#include "FindPerson.h"

using namespace std;

FindPerson::FindPerson() {
    //Create linkedlist by going through text file and add all previously added users
    // if no previously added users FindPerson() will create an empty node
    headPtr_ = NULL;
    tailPtr_ = NULL;
}

bool FindPerson::addPerson(string CPR, string firstName, string lastName, int userLevel) {
    Person *newUser;

    switch(userLevel) {
        case 1:
            newUser = new User(firstName, lastName, CPR);
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
    delete newUser;
    return true;
}

bool FindPerson::deletePerson() {

}

bool FindPerson::changePersonInfo() {

}

bool checkForTakenPills() {

}

bool FindPerson::findPersonInList() {
    //Searches and finds person in list and returns pointer to the node with the person in it
    //through call by reference, also returns true.
}

void printUsers() {
}
