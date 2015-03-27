#include <iostream>
#include "Person.h"
#include "User.h"

using namespace std;

//Mangler: Check af CPR-Nummer

User::User(string cprNumber, string firstName, string lastName)
    : Person(firstName, lastName){

        headPtr_ = NULL;
        setUserLevel();
        setName(cprNumber, firstName, lastName);
    }

void User::setUserLevel() {
    Person::setUserLevel(1);
}

bool User::addPills(string pillName, int amount)
{
    if (amount >= 1 && amount < 10)
    {
        Pilledata p1;
        p1.antal = amount;
        p1.Pilletype = pillName;

        PilleListe_.headInsert(headPtr_, p1);
        return true;
    }
    return false;
}

bool User::deletePills(string pillType, int amount) {

    //Tjekker om pillen er på første plads i vores linked list
    if (headPtr_->info.Pilletype == pillType) {
        PilleListe_.headRemove(headPtr_);
        cout << "SYSTEM: Pillen " << headPtr_->info.Pilletype << " bliver slettet fra brugerens pilleprofil" << endl;
    }


    //hvis ikke kører den resten igennem
    Node<Pilledata>* tmpPtr = headPtr_;
    Node<Pilledata>* prevPtr = headPtr_;

    while (tmpPtr != NULL) {
        if (tmpPtr->info.Pilletype == pillType) {
            if (tmpPtr->info.antal <= amount) {
                PilleListe_.remove(prevPtr);
                cout << "SYSTEM: Pillen " << tmpPtr->info.Pilletype << " bliver slettet fra brugerens pilleprofil" << endl;
                return true;
            }
            else {
                tmpPtr->info.antal = tmpPtr->info.antal - amount;
                cout << "SYSTEM: Brugeren skal nu kun have " << tmpPtr->info.antal << " af pillen " << tmpPtr->info.Pilletype << endl;
                return true;
            }
        }
        prevPtr = tmpPtr;
        tmpPtr = tmpPtr->next;
    }
    return false;
}

void User::printPills() {
    Node<Pilledata>* tmpPtr = headPtr_;

    while (tmpPtr != NULL)
    {
        cout << "User needs " << tmpPtr->info.antal << " " << tmpPtr->info.Pilletype << endl;
        tmpPtr = tmpPtr->next;
    }
}

void User::getName(string& firstName, string& lastName, string& cprNumber) {
	Person::getName(firstName, lastName);
	Person::getCPR(cprNumber);
}

void User::setName(string firstName, string lastName, string cprNumber) {
	Person::setName(firstName, lastName);
	Person::setCPR((cprNumber.size() == 10 ? cprNumber : "0000000000"));
}


void User::printUserInfo() {
    Person::printUserInfo();
}
