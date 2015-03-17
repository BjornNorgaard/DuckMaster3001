#ifndef FINDPERSON_H_
#define FINDPERSON_H_

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

#endif // FINDPERSON_H_