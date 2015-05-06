#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <QString>

#include "Database.hpp"

class Person {
public:
    Person();
    ~Person();

    bool createPerson(QString const& cpr, QString const& firstname, QString const& lastname);
    bool deletePerson(int id);
private:
};

#endif // PERSON_HPP
