#include "Database.hpp"

Database::Database() {
    openDB();
}

Database::~Database() {
    closeDB();
}

static void logSQLFailure(const QSqlQuery& query) {
    const QSqlError error(query.lastQuery());
    qWarning() << "SQL Query failed" << query.lastQuery();
    qWarning() << error.number() << query.lastError().text();
}

static bool execQueryAndLogFailure(QSqlQuery& query) {
    if(!query.exec()) {
        logSQLFailure(query);
        return false;
    }
    return true;
}

static bool execQueryAndLogFailure(QSqlQuery& query, const QString& queryString) {
    if(!query.exec(queryString)) {
        logSQLFailure(query);
        return false;
    }
    return true;
}

QSqlError Database::openDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./db.sqlite");

    if (!db.open()) {
        qDebug() << "Database: Connection failed.";
        return db.lastError();
    }

    qDebug() << "Database: Connection success!";
    setupDB();

    return QSqlError();
}

void Database::closeDB() {
    QSqlQuery query;

    execQueryAndLogFailure(query, "VACUUM");
}

void Database::setupDB() {
    QSqlQuery query;

    // tables for user data
    execQueryAndLogFailure(query, "CREATE TABLE IF NOT EXISTS users(user_id INTEGER PRIMARY KEY AUTOINCREMENT, fingerprint_id BLOB, cpr TEXT, firstname TEXT, lastname TEXT, UNIQUE(cpr))");
    execQueryAndLogFailure(query, "CREATE TABLE IF NOT EXISTS groups(group_id INTEGER, name TEXT, UNIQUE(group_id, name))");
    execQueryAndLogFailure(query, "CREATE TABLE IF NOT EXISTS pills(pill_id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
    execQueryAndLogFailure(query, "CREATE TABLE IF NOT EXISTS pill_groups(pill_id INTEGER, user_id INTEGER)");
    execQueryAndLogFailure(query, "CREATE TABLE IF NOT EXISTS group_members(group_id INTEGER, user_id INTEGER, UNIQUE(user_id))");

    // user groups
    execQueryAndLogFailure(query, "INSERT OR IGNORE INTO groups(group_id, name) VALUES(1, \"User\")");
    execQueryAndLogFailure(query, "INSERT OR IGNORE INTO groups(group_id, name) VALUES(2, \"Supporter\")");
    execQueryAndLogFailure(query, "INSERT OR IGNORE INTO groups(group_id, name) VALUES(3, \"Super User\")");
}

void Database::printPersons() {
    QSqlQuery query;
    
    execQueryAndLogFailure(query, "SELECT * FROM users");
    qDebug() << "ID:" << "\t" << "Firstname(s)" << "\t" << "Lastname";
    while (query.next()) {
        qDebug() << query.value(0).toString() << "\t" << query.value(3).toString() << "\t" << query.value(4).toString();
    }

}

bool Database::createList(QListWidget*& lw) {
    QSqlQuery query;

    //Forstår ikke helt metoden
    execQueryAndLogFailure(query, "SELECT * FROM users");

    while(query.next()) {
        lw->addItem(query.value(3).toString() + " " + query.value(4).toString() + ", " + query.value(2).toString());
    }
    return true;
}

bool Database::createPerson(const QString& cpr, const QString& firstname, const QString& lastname) {
    QSqlQuery query;
    QVariant user_id;

    // search for cpr
    query.prepare("SELECT * FROM users WHERE cpr = :cpr");
    query.bindValue(":cpr", cpr);
    execQueryAndLogFailure(query);
    while (query.next()) {
        if (cpr == query.value(2).toString()) {
            qWarning() << "Database: User already exists!";
            return false;
        }
    }

    // add person to database
    query.prepare("INSERT OR IGNORE INTO users(cpr, firstname, lastname) VALUES(:cpr, :firstname, :lastname)");
    query.bindValue(":cpr", cpr);
    query.bindValue(":firstname", firstname);
    query.bindValue(":lastname", lastname);
    execQueryAndLogFailure(query);
   
    // find user_id
    query.prepare("SELECT * FROM users WHERE cpr = :cpr");
    query.bindValue(":cpr", cpr);
    execQueryAndLogFailure(query);
    while (query.next())
        user_id = query.value(0).toInt();

    // assign group
    query.prepare("INSERT OR IGNORE INTO group_members (group_id, user_id) VALUES (1, :user_id)");
    query.bindValue(":lastname", user_id);
    execQueryAndLogFailure(query);

    return true;
}

bool Database::deletePersonById(int id) {
    QSqlQuery query;

    query.prepare("DELETE FROM users WHERE user_id IS :id");
    query.bindValue(":id", id);
    execQueryAndLogFailure(query);

    return true;
}
