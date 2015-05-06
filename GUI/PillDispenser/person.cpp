#include "Person.hpp"

Person::Person() {
}

Person::~Person() {
}

bool Person::createPerson(QString& cpr, QString& firstname, QString& lastname) {
    QSqlQuery query;

    query.prepare("INSERT INTO users (cpr, firstname, lastname) VALUES (:cpr, :firstname, :lastname)");
    query.bindValue(":cpr", cpr);
    query.bindValue(":firstname", firstname);
    query.bindValue(":lastname", lastname);

    execQueryAndLogFailure(query, "hmm");

    return true;
}

bool Person::deletePerson(int id) {

}

