#include <iostream>
#include <conio.h>
#include "FindPerson.h"
#include"SuperUser.h"
#include"Person.h"
#include"User.h"

using namespace std;

int main() {

	FindPerson fp();

	char ch;

	do{
		cout << "Enter a Number" << endl << endl;

		cout << "Press 1 for a list of current users" << endl;
		cout << "Press 2 To choose a user to dispense pills for" << endl;
		cout << "Press 3 to choose a user and change his info (more info will follow after keypress)" << endl;

		ch = getch();

		switch (ch){
		case '1':
			system("cls");
			fp.printUser();
			cout << endl << endl;

			break;
		case '2':
			system("cls");			

			fp.printUser();

			cout << endl << endl << "Vaelg nu bruger du vil dispense piller for" << endl;

			break;
		case '3':
			system("cls");
			
			fp.printUser();

			cout << endl << endl << "Vaelg nu bruger hvis informationer skal ændres" << endl;

			

			cout << 

			break;
		case '4':
			system("cls");
			cout << "This is number 4" << endl;
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