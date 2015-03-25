#ifndef PERSON_H_
#define PERSON_H_

#include<string>

using namespace std;

class Person {
protected:
	Person(string firstName = "NaN", string lastName = "NaN");
public:
	virtual void getBrugerInfo(string&, string&);
	virtual void setBrugerInfo(string, string);
	virtual void setUserLevel(int);
	virtual bool addPills(string, int) = 0;
<<<<<<< HEAD
	virtual void printPills() = 0;
=======
>>>>>>> ac2d1101ad4debd1080a216349c3b1923685222f
	virtual bool deletePills(string, int) = 0;
	virtual void printPills() = 0;
	int getUserLevel();
	virtual void printUserInfo();
	//virtual ~Person();

private:
	int userLevel_;
	string firstName_;
	string lastName_;
};

#endif // PERSON_H_
