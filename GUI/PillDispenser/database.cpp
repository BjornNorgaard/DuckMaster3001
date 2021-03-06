#include "database.h"

Database::Database() {
    openDB();
}

Database::~Database() {
    closeDB();
}

void Database::logSQLFailure(const QSqlQuery& query) {
    const QSqlError error(query.lastQuery());
    qWarning() << "SQL Query failed" << query.lastQuery();
    qWarning() << error.number() << query.lastError().text();
}

bool Database::execQueryAndLogFailure(QSqlQuery& query) {
    if (!query.exec()) {
        logSQLFailure(query);
        return false;
    }
    return true;
}

bool Database::execQueryAndLogFailure(QSqlQuery& query, const QString& queryString) {
    if (!query.exec(queryString)) {
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
