<<<<<<< HEAD
#ifndef PERSON_H_
#define PERSON_H_

class Person {
public:

private:
};

#endif // PERSON_H_
=======
#pragma once
#include <string>

using namespace std;



class Person {
public:
	//Constructor
	Person(string firstName, string lastName, int Adgangsniveau);

	//Returnerer adgangsniveau
	virtual int getAdgangsniveau() = 0;

	//Sætter adgangsniveau, 1 for bruger, 2 for SuperUser og 3 for supporter
	virtual void setAdgangsniveau( int = 1 ) = 0;

	//Returnerer brugerinformationer ved call by reference
	virtual int getBrugerinfo(string &name, string &cpr) = 0;

	//Sætter bruger informationer
	virtual void setBrugerinfo(string firstName, string lastName) = 0;

	//Virtual destructor
	virtual ~Person();

private:
	int Adgangsniveau_;
	string firstName_;
	string lastName_;
};




>>>>>>> master
