#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include "database.h"

enum {
    GRP_USER = 1,
    GPR_SUPPORTER = 2,
    GPR_SUPERUSER = 3
};

class Person {
  public:
    Person(Database& db = Database::getInstance());

    bool createPerson(const QString& cpr, const QString& firstname, const QString& lastname);
    bool deletePerson(quint16 id);

    // Find
    bool findPerson(quint16& id, const QString& cpr);
    bool findPerson(quint16& id, const QString& fingerprint, char* throwaway);
    bool findPerson(quint16& id, const QString& firstname, const QString& lastname);

    // Modify
    bool modifyCpr(quint16 id, const QString cpr);
    bool modifyFirstName(quint16 id, const QString firstname);
    bool modifyLastName(quint16 id, const QString lastname);
    bool modifyFingerprint(quint16 id, const QString fingerprint);
    bool modifyGroup(quint16 id, const quint8 group);

    // Get
    bool getCpr(quint16 id, QString& cpr);
    bool getFingerprint(quint16 id, QString& fingerprint);
    bool getFirstname(quint16 id, QString& firstname);
    bool getLastname(quint16 id, QString& lastname);
    bool getGroup(quint16 id, quint8& group);

  private:
    enum {
        SQL_USERS_USER_ID,
        SQL_USERS_FINGERPRINT_ID,
        SQL_USERS_CPR,
        SQL_USERS_FIRSTNAME,
        SQL_USERS_LASTNAME
    };

    enum {
        SQL_GROUPS_GROUP_ID,
        SQL_GROUPS_USER_ID
    };

    Database& db;
};

#endif // PERSON_H
