#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QListWidget>
#include <QString>
#include <QVariant>

class Database : public QObject {
  public:
    ~Database();

    QSqlError openDB();
    void closeDB();
    void setupDB();
    bool isEmpty();

    void logSQLFailure(const QSqlQuery& query);
    bool execQueryAndLogFailure(QSqlQuery& query);
    bool execQueryAndLogFailure(QSqlQuery& query, const QString& queryString);

    static Database& getInstance() {
        static Database db;
        return db;
    }

  private:
    Database();
};

#endif //DATABASE_H
