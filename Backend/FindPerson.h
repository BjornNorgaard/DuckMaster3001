#pragma once

#include "LLToolkit.h"
#include "Person.h"

class FindPerson {
public:
	FindPerson();
	bool addPerson();
	bool deletePerson();
	bool changePersonInfo();
	bool checkForTakenPills();

private:
	LLToolkit<Person> PersonList;
	Node<Person>* headPtr;
	Node<Person>* tailPtr;
	bool findPersonInList();
};