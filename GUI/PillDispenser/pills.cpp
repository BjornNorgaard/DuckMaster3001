#include "pills.h"

Pills::Pills(Database& database) : db(database) {}

bool Pills::addPill(QString& name) {
    QSqlQuery query;

    query.prepare("INSERT OR IGNORE INTO pills (name) VALUES (:name)");
    query.bindValue(":name", name);
    return db.execQueryAndLogFailure(query);
}

bool Pills::delPill(quint16 pillid) {
    QSqlQuery query;

    query.prepare("DELETE FROM pills WHERE pill_id = :pillid");
    query.bindValue(":pillid", pillid);
    if (!db.execQueryAndLogFailure(query))
        return false;

    query.prepare("SELECT * FROM pill_groups WHERE pill_id = :pillid");
    query.bindValue(":pillid", pillid);
    if (!db.execQueryAndLogFailure(query))
        return false;

    while (query.next()) {
        query.prepare("DELETE FROM pills_groups WHERE user_id = :user_id)");
        query.bindValue(":user_id", query.value(SQL_PILL_GROUPS_USER_ID));
        db.execQueryAndLogFailure(query);
    }
    return true;
}

bool Pills::getPill(quint16& id, QString& name) const {
    QSqlQuery query;

    query.prepare("SELECT * FROM pills WHERE name = :name");
    query.bindValue(":name", name);
    db.execQueryAndLogFailure(query);
    while (query.next()) {
        id = query.value(SQL_PILLS_PILL_ID).toUInt();
        return true;
    }

    return false;
}

bool Pills::assignPills(quint16 user_id, quint16 pill_id, quint8 pill_amount) {
    QSqlQuery query;

    query.prepare("INSERT OR IGNORE INTO pill_groups (pill_id, user_id, amount) VALUES (:pill_id, :user_id, :amount)");
    query.bindValue(":pill_id", pill_id);
    query.bindValue(":user_id", user_id);
    query.bindValue(":amount", pill_amount);

    return db.execQueryAndLogFailure(query);
}

bool Pills::removePills(quint16 userid, quint16 pillid) {
    QSqlQuery query;

    query.prepare("DELETE FROM pill_groups WHERE user_id = :user_id, pill_id = :pill_id");
    query.bindValue(":user_id", userid);
    query.bindValue(":pill_id", pillid);

    return db.execQueryAndLogFailure(query);
}
