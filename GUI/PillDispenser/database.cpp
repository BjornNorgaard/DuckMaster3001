#include "database.h"

Database::Database() {
    openDB();
}

Database::~Database() {
    closeDB();
}

/*
 * Database::logSQLFailure()
 * Description  :
 * Precondition :
 * Postcondition:
 */
void Database::logSQLFailure(const QSqlQuery& query) {
    const QSqlError error(query.lastQuery());
    qWarning() << "SQL Query failed" << query.lastQuery();
    qWarning() << error.number() << query.lastError().text();
}

/*
 * Database::execQueryAndLogFailure()
 * Description  :
 * Precondition :
 * Postcondition:
 */
bool Database::execQueryAndLogFailure(QSqlQuery& query) {
    if (!query.exec()) {
        logSQLFailure(query);
        return false;
    }
    return true;
}

/*
 * Database::execQueryAndLogFailure()
 * Description  :
 * Precondition :
 * Postcondition:
 */
bool Database::execQueryAndLogFailure(QSqlQuery& query, const QString& queryString) {
    if (!query.exec(queryString)) {
        logSQLFailure(query);
        return false;
    }
    return true;
}

/*
 * Database::openDB()
 * Description  : Opens database connection.
 * Precondition :
 * Postcondition:
 */
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

/*
 * Database::closeDB()
 * Description  : Closes database connection.
 * Precondition :
 * Postcondition:
 */
void Database::closeDB() {
    QSqlQuery query;

    execQueryAndLogFailure(query, "VACUUM");
}

/*
 * Database::setupDB()
 * Description  : Sets up the database even if it exists. 
 * Precondition :
 * Postcondition:
 */
void Database::setupDB() {
    QSqlQuery query;

    // tables for user data
    execQueryAndLogFailure(query, "CREATE TABLE IF NOT EXISTS users(user_id INTEGER PRIMARY KEY AUTOINCREMENT, fingerprint_id BLOB, cpr TEXT, firstname TEXT, lastname TEXT, UNIQUE(cpr))");
    execQueryAndLogFailure(query, "CREATE TABLE IF NOT EXISTS groups(group_id INTEGER, name TEXT, UNIQUE(group_id, name))");
    execQueryAndLogFailure(query, "CREATE TABLE IF NOT EXISTS pills(pill_id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
    execQueryAndLogFailure(query, "CREATE TABLE IF NOT EXISTS pill_groups(pill_id INTEGER, user_id INTEGER, amount INTEGER)");
    execQueryAndLogFailure(query, "CREATE TABLE IF NOT EXISTS group_members(group_id INTEGER, user_id INTEGER, UNIQUE(user_id))");

    // user groups
    execQueryAndLogFailure(query, "INSERT OR IGNORE INTO groups(group_id, name) VALUES(1, \"User\")");
    execQueryAndLogFailure(query, "INSERT OR IGNORE INTO groups(group_id, name) VALUES(2, \"Supporter\")");
    execQueryAndLogFailure(query, "INSERT OR IGNORE INTO groups(group_id, name) VALUES(3, \"Super User\")");
}

bool Database::isEmpty() {
    QSqlQuery query;

    execQueryAndLogFailure(query, "SELECT * FROM users");
    while (query.next()) {
        return false;
    }

    return true;
}

bool Database::createList(QListWidget*& lw) {
    QSqlQuery query;

    //Forstår ikke helt metoden
    execQueryAndLogFailure(query, "SELECT * FROM users");

    while (query.next()) {
        lw->addItem(query.value(4).toString() + ", " + query.value(3).toString() + ", " + query.value(2).toString());
    }
    return true;
}
