#include "person.h"

Person::Person() : this->db(db) {}

bool Person::createPerson(const QString& cpr, const QString& firstname, const QString& lastname) {
    QSqlQuery query;
    quint16 id;

    if (findPerson(id, cpr)) {
        qDebug() << "User already exists in database!";
        return false;
    }

    // Add person to database
    query.prepare("INSERT OR IGNORE INTO users (cpr, firstname, lastname) VALUES (:cpr, :firstname, :lastname)");
    query.bindValue(":cpr", cpr);
    query.bindValue(":firstname", firstname);
    query.bindValue(":lastname", lastname);
    db.execQueryAndLogFailure(query);

    if (!findPerson(id, cpr)) {
        qDebug() << "User wasn't added to database!";
        return false;
    }

    // Assign group
    modifyGroup(id, GRP_USER);

    return true;
}

bool Person::deletePerson(quint16 id) {
    QSqlQuery query;

    query.prepare("DELETE FROM users WHERE user_id = :id");
    query.bindValue(":id", id);

    return db.execQueryAndLogFailure(query);
}

bool Person::findPerson(quint16& id, const QString& cpr) {
    QSqlQuery query;

    query.prepare("SELECT * FROM users WHERE cpr = :cpr");
    query.bindValue(":cpr", cpr);
    db.execQueryAndLogFailure(query);
    while (query.next()) {
        if (cpr == query.value(SQL_USERS_CPR).toString()) {
            id = query.value(SQL_USERS_USER_ID).toUInt();
            return true;
        }
    }

    return false;
}

bool Person::findPerson(quint16& id, const QString& fingerprint, char* throwaway) {
    QSqlQuery query;

    query.prepare("SELECT * FROM users WHERE fingerprint = :fingerprint");
    query.bindValue(":fingerprint", fingerprint);
    db.execQueryAndLogFailure(query);
    while (query.next()) {
        if (fingerprint == query.value(SQL_USERS_FINGERPRINT_ID).toString()) {
            id = query.value(SQL_USERS_USER_ID).toUInt();
            return true;
        }
    }

    return false;
}

bool Person::findPerson(quint16& id, const QString& firstname, const QString& lastname) {
    QSqlQuery query;

    query.prepare("SELECT * FROM users WHERE :firstname AND :lastname");
    query.bindValue(":firstname", firstname);
    query.bindValue(":lastname", lastname);

    db.execQueryAndLogFailure(query);
    while (query.next()) {
        if (firstname == query.value(SQL_USERS_FIRSTNAME).toString() && lastname == query.value(SQL_USERS_LASTNAME).toString()) {
            id = query.value(SQL_USERS_USER_ID).toUInt();
            return true;
        }
    }

    return false;
}

bool Person::modifyCpr(quint16 id, const QString cpr) {
    QSqlQuery query;

    query.prepare("UPDATE OR IGNORE users SET cpr = :cpr WHERE user_id = :id");
    query.bindValue(":cpr", cpr);
    query.bindValue(":id", id);

    return db.execQueryAndLogFailure(query);
}

bool Person::modifyFirstName(quint16 id, const QString firstname) {
    QSqlQuery query;

    query.prepare("UPDATE OR IGNORE users SET firstname = :firstname WHERE user_id = :id");
    query.bindValue(":firstname", firstname);
    query.bindValue(":id", id);

    return db.execQueryAndLogFailure(query);
}

bool Person::modifyLastName(quint16 id, const QString lastname) {
    QSqlQuery query;

    query.prepare("UPDATE OR IGNORE users SET lastname = :lastname WHERE user_id = :id");
    query.bindValue(":lastname", lastname);
    query.bindValue(":id", id);

    return db.execQueryAndLogFailure(query);
}

bool Person::modifyFingerprint(quint16 id, const QString fingerprint) {
    QSqlQuery query;

    query.prepare("UPDATE or IGNORE users SET fingerprint_id = :fingerprint WHERE user_id = :id");
    query.bindValue(":fingerprint", fingerprint);
    query.bindValue(":id", id);

    return db.execQueryAndLogFailure(query);
}

bool Person::modifyGroup(quint16 id, const quint8 group) {
    QSqlQuery query;

    query.prepare("INSERT OR IGNORE INTO group_members (group_id, user_id) VALUES (:group_id, :user_id)");
    query.bindValue(":group_id", group);
    query.bindValue(":user_id", id);
    return db.execQueryAndLogFailure(query);
}

bool Person::getCpr(quint16 id, QString& cpr) {
    QSqlQuery query;

    query.prepare("SELECT * FROM users WHERE user_id = :id");
    query.bindValue(":id", id);
    db.execQueryAndLogFailure(query);
    while (query.next()) {
        cpr = query.value(SQL_USERS_CPR).toString();
        return true;
    }

    return false;
}

bool Person::getFingerprint(quint16 id, QString& fingerprint) {
    QSqlQuery query;

    query.prepare("SELECT * FROM users WHERE user_id = :id");
    query.bindValue(":id", id);
    db.execQueryAndLogFailure(query);
    while (query.next()) {
        fingerprint = query.value(SQL_USERS_FINGERPRINT_ID).toString();
        return true;
    }

    return false;
}

bool Person::getFirstname(quint16 id, QString& firstname) {
    QSqlQuery query;

    query.prepare("SELECT * FROM users WHERE user_id = :id");
    query.bindValue(":id", id);
    db.execQueryAndLogFailure(query);
    while (query.next()) {
        firstname = query.value(SQL_USERS_FIRSTNAME).toString();
        return true;
    }

    return false;
}

bool Person::getLastname(quint16 id, QString& lastname) {
    QSqlQuery query;

    query.prepare("SELECT * FROM users WHERE user_id = :id");
    query.bindValue(":id", id);
    db.execQueryAndLogFailure(query);
    while (query.next()) {
        lastname = query.value(SQL_USERS_LASTNAME).toString();
        return true;
    }

    return false;
}

bool Person::getGroup(quint16 id, quint8& group) {
    QSqlQuery query;

    query.prepare("SELECT * FROM groups WHERE user_id = :id");
    query.bindValue(":id", id);
    db.execQueryAndLogFailure(query);
    while (query.next()) {
        group = query.value(SQL_GROUPS_GROUP_ID).toUInt();
        return true;
    }

    return false;
}
