#include "pills.h"

Pills::Pills() {}

Pills::~Pills() {}


bool Pills::addPills(quint16 pillid, QString& name) {
    QSqlQuery query;

    query.prepare("INSERT OR IGNORE INTO pills (pill_id, name) VALUES (:pill_id, :name)");
    query.bindValue(":pill_id", pillid);
    query.bindValue(":name", name);
    return Database::execQueryAndLogFailure(query);
}


bool Pills::delPills(quint16 pillid) {
    QSqlQuery query;

    query.prepare("DELETE FROM pills WHERE pill_id = :pillid");
    query.bindValue(":pillid", pillid);
    if (!Database::execQueryAndLogFailure(query))
        return false;

    query.prepare("SELECT * FROM pill_groups WHERE pill_id = :pillid");
    query.bindValue(":pillid", pillid);
    if (!Database::execQueryAndLogFailure(query))
        return false;

    while (query.next()) {
        query.prepare("DELETE FROM pills_groups WHERE user_id = :user_id)");
        query.bindValue(":user_id", query.value(SQL_PILL_GROUPS_USER_ID));
        Database::execQueryAndLogFailure(query);
    }
    return true;
}

bool Pills::assignPills(quint16 user_id, quint16 pill_id, quint8 pill_amount) {
    QSqlQuery query;

    query.prepare("INSERT OR IGNORE INTO pill_groups (pill_id, user_id, amount) VALUES (:pill_id, :user_id, :amount)");
    query.bindValue(":pill_id", pill_id);
    query.bindValue(":user_id", user_id);
    query.bindValue(":amount", pill_amount);

    return Database::execQueryAndLogFailure(query);
}

bool Pills::removePills(quint16 userid, quint16 pillid) {
    QSqlQuery query;

    query.prepare("DELETE FROM pill_groups WHERE user_id = :user_id, pill_id = :pill_id");
    query.bindValue(":user_id", userid);
    query.bindValue(":pill_id", pillid);

    return Database::execQueryAndLogFailure(query);
}
