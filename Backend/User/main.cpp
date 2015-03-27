#include <iostream>
#include <ncurses.h>
#include "FindPerson.h"
#include "SuperUser.h"
#include "Person.h"
#include "User.h"

using namespace std;

int main() {

	FindPerson findP;
	string firstName;
	string lastName;
	string cpr;
	int userLevel = 0;


	char ch;

	do{
		cout << endl << "Enter a Number" << endl << endl;

		cout << "Press 1 for a list of current users" << endl;
		cout << "Press 2 To choose a user to dispense pills for" << endl;
		cout << "Press 3 to choose a user and change his info (more info will follow after keypress)" << endl;
		cout << "Press 4 to add a user" << endl;

		ch = getch();

		switch (ch){
		case '1':
			system("cls");
			
			findP.printUsers();

			cout << endl << endl;
			break;
		case '2':
			system("cls");			

			cout << "Vaelg nu bruger du vil dispense piller for" << endl;

			break;
		case '3':
			system("cls");

			cout << "Vaelg nu bruger hvis informationer skal ændres" << endl << endl;
			break;
		case '4':
			system("cls");
			cout << "Write credentials of a new user below, write firstname then press enter" << endl;
			getline(cin, firstName);
			
			cout << endl << "Now write lastname" << endl;
			getline(cin, lastName);

			cout << endl << "Now state userlevel (1 for normal user, 2 for supporter or 3 for superuser)" << endl;
			scanf("%d", &userLevel);

			if (userLevel == 1) {
				cout << endl << "Write normal users CPR-number for database" << endl;
				cout << endl << endl << cpr << endl;
				getline(cin, cpr);

				findP.addPerson(cpr, firstName, lastName, userLevel);
			}
			else {
				findP.addPerson("000000000", firstName, lastName, userLevel);
			}

			

			break;
		case '5':
			system("cls");
			cout << "This is number 5" << endl;
			break;
		case '6':
			system("cls");
			cout << "This is number 6" << endl;
			break;
		}
		
	} while (1);

	/*
	Person *ptr[4] = {
		new User("Anders", "Carlsen", "2201034231"),
		new SuperUser("Martin", "Carpentier"),
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
	*/
}
