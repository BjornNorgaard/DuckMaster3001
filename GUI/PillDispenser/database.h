#ifndef DATABASE_HPP_
#define DATABASE_HPP_

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QListWidget>
#include <QString>
#include <QVariant>

class Database : public QObject {
public:
    Database();
    ~Database();

    static QSqlError openDB();
    static void closeDB();
    static void setupDB();

    static void printPersons();
    static bool createPerson(const QString& cpr, const QString& firstname, const QString& lastname);
    static bool deletePersonById(int id);
    static bool createList(QListWidget*& lw);

private:


};

#endif //DATABASE_HPP_
