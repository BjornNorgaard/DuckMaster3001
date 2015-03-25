#include"SuperUser.h"
#include<iostream>

using namespace std;

//Mangler: check af jobtitel.

SuperUser::SuperUser(string firstName, string lastName, string jobTitel) {
	setBrugerInfo(firstName, lastName, jobTitel);
	setUserLevel();
}

void SuperUser::setBrugerInfo(string firstName, string lastName, string jobTitel) {
	Person::setBrugerInfo(firstName, lastName);
	jobTitel_ = jobTitel;
}

void SuperUser::getBrugerInfo(string& firstName, string& lastName, string& jobTitel) {
	Person::getBrugerInfo(firstName, lastName);
	jobTitel_ = jobTitel;
}

void SuperUser::setUserLevel() {
	Person::setUserLevel(2);
}

void SuperUser::addPills(){
	cout << "SYSTEM: SuperUser kan ikke bruge piller" << endl;
}

void SuperUser::printPills() {
	cout << "SYSTEM: SuperUser har ingen piller" << endl;
}

bool SuperUser::deletePills() {
	cout << "SYSTEM: SuperUser kan ikke bruge piller" << endl;
	return false;
}