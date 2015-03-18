#include"User.h"
#include"Person.h"
#include <iostream>

using namespace std;

int main() {

	Person *ptr[4] = {
		new User("Anders", "Carlsen", "2201034231"),
		new User("Martin", "Carpentier", "2201921697"),
		new User("Ole", "Pedersen", "1352316054"),
		new User("Niels", "Nielsen", "3243235423")
	};
	
	cout << endl;
	ptr[0]->printUserInfo();
	ptr[0]->addPills("Panodil", 3);
	ptr[0]->addPills("D-Vitamin", 2);
	ptr[0]->printPills();
	cout << endl << "Sletter nu 2 panodiler og tester om de er slettet" << endl;
	ptr[0]->deletePills("Panodil", 2);
	ptr[0]->printPills();

	cout << endl << "Sletter nu alle D-Vitaminer og tjekker om de er slettet" << endl;
	ptr[0]->deletePills("D-Vitamin", 2);
	ptr[0]->printPills();
}