#include "Supporter.h"

Supporter::Supporter(string firstName, string lastName) : Person(firstName, lastName) {
   Person::setUserLevel(2);
}

void Supporter::getBrugerInfo(string& firstName, string& lastName) {
   Person::getBrugerInfo(firstName, lastName);
}

void Supporter::setBrugerInfo(string firstName, string lastName) {
   Person::setBrugerInfo(firstName, lastName);
}

int Supporter::getUserLevel() {
   return Person::getUserLevel();
}
