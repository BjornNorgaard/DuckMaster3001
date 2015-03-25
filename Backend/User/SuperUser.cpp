#include<iostream>
#include"SuperUser.h"

using namespace std;

//Mangler: check af jobtitel.

SuperUser::SuperUser(string firstName, string lastName) 
: Supporter(firstName, lastName) 
{
	Person::setUserLevel(3);
}

void SuperUser::setBrugerInfo(string firstName, string lastName) {
	Supporter::setBrugerInfo(firstName, lastName);
}

void SuperUser::getBrugerInfo(string& firstName, string& lastName) {
	Supporter::getBrugerInfo(&firstName, &lastName);
}

void SuperUser::setUserLevel() {
	Supporter::setUserLevel(2);
}


void SuperUser::addPills(string pillName, int amount){
	cout << "SYSTEM: SuperUser kan ikke bruge piller" << endl;
}

void SuperUser::printPills() {
	cout << "SYSTEM: SuperUser har ingen piller" << endl;
}

bool SuperUser::deletePills(string pillType, int amount) {
	cout << "SYSTEM: SuperUser kan ikke bruge piller" << endl;
	return false;
}
