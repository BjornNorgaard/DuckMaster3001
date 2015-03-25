#include "FindPerson.h"

FindPerson::FindPerson() {
   //Create linkedlist by going through text file and add all previously added users
   // if no previously added users FindPerson() will create an empty node
   headPtr_ = NULL;
   tailPtr_ = NULL;
}

bool FindPerson::addPerson(string firstName, string lastName, int userLevel) {

   switch(userLevel) {
      case 1:
         break;
      case 2:
         break;
      case 3:
         break;
      default:
         break;
   }

   PersonList_.headInsert(headPtr_, *newUser);
   return true;
}

bool FindPerson::deletePerson() {

}

bool FindPerson::changePersonInfo() {

}

bool checkForTakenPills() {

}

bool FindPerson::findPersonInList() {
   //Searches and finds person in list and returns pointer to the node with the person in it
   //through call by reference, also returns true.
}

void printUsers() {

}
