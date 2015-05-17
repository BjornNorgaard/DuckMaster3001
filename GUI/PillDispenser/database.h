#ifdef DATABASE_H
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

    static QSqlError openDB();
    static void closeDB();
    static void setupDB();

    static void logSQLFailure(const QSqlQuery& query);
    static bool execQueryAndLogFailure(QSqlQuery& query);
    static bool execQueryAndLogFailure(QSqlQuery& query, const QString& queryString);

    bool createList(QListWidget*& lw);

  private:
    Database();
};

#endif //DATABASE_H
