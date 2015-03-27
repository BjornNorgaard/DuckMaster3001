#include <iostream>
#include "Supporter.h"

using namespace std;

Supporter::Supporter(string firstName, string lastName) : Person(firstName, lastName) {
    Person::setUserLevel(2);
}

void Supporter::getBrugerInfo(string& firstName, string& lastName) {
    Person::getName(firstName, lastName);
}

void Supporter::setBrugerInfo(string firstName, string lastName) {
    Person::setName(firstName, lastName);
}


bool Supporter::addPills(string, int) {
    return false;
}

void Supporter::setUserLevel(int userLevel) {
	Person::setUserLevel(userLevel);
}

bool Supporter::deletePills(string, int) {
    return false;
}

void Supporter::printPills() {

}

void Supporter::printUserInfo() {
    cout << "Not implemented yet..." << endl;
}

int Supporter::getUserLevel() {
    return Person::getUserLevel();
}
