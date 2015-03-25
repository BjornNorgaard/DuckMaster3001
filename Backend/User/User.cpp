#include "Person.h"
#include "User.h"
#include <iostream>

//Mangler: Check af CPR-Nummer


User::User(string firstName, string lastName, string cprNumber) 
    : Person(firstName, lastName){
	
	headPtr_ = NULL;
	setUserLevel();
	setBrugerInfo(firstName, lastName, cprNumber);
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

void User::getBrugerInfo(string& firstName, string& lastName, string& cprNumber) {
	Person::getBrugerInfo(firstName, lastName);
	cprNumber = cprNumber_;
}

void User::setBrugerInfo(string firstName, string lastName, string cprNumber) {
	Person::setBrugerInfo(firstName, lastName);
	cprNumber_ = (cprNumber.size() == 10 ? cprNumber : "0000000000");
}

void User::printUserInfo() {
	Person::printUserInfo();
	cout << "Users cpr number is " << cprNumber_ << endl;
}
