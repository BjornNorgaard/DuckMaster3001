#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(string firstName, string lastName) {
   setBrugerInfo(firstName, lastName);
}

void Person::getBrugerInfo(string& firstName, string& lastName) {
   firstName = firstName_;
   lastName = lastName_;
}

void Person::setBrugerInfo(string firstName, string lastName) {
   if ( firstName == "NaN" ) {
      cout << "Firstname is empty, please try to write it again" << endl;
      return;
   }
   if ( lastName == "NaN" ) {
      cout << "Lastname is empty, please try to write it again" << endl;
      return;
   }

   firstName_ = firstName;
   lastName_ = lastName;
}

void Person::setUserLevel(int userLevel) {
   if (userLevel == 1) {
      cout << "SYSTEM: Creating a user" << endl;
      userLevel_ = userLevel;
   }
   else if (userLevel == 2) {
      cout << "SYSTEM: Creating a super user" << endl;
      userLevel_ = userLevel;
   }
   else if (userLevel == 3) {
      cout << "SYSTEM: Creating a supporter" << endl;
      userLevel_ = userLevel;
   }
   else {
      cout << "SYSTEM WARNING: User not within acceptable range, please try again" << endl;
   }
}

int Person::getUserLevel() {
   return userLevel_;
}

void Person::printUserInfo() {
   cout << "User is a " << (userLevel_ == 1 ? "normal user" : "") << (userLevel_ == 2 ? "super user" : "") << (userLevel_ == 3 ? "supporter" : "") << endl;
   cout << "and hes/ her name is " << firstName_ << " " << lastName_ << endl;
}
