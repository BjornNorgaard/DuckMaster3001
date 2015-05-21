#include "pills.h"

Pills::Pills() : this->db(db) {}

/*
 * Pills::addPills()
 * Description  : Adds a pill to the database.
 * Precondition :
 * Postcondition:
 */
bool Pills::addPills(QString& name) {
    QSqlQuery query;

    query.prepare("INSERT OR IGNORE INTO pills (name) VALUES (:name)");
    query.bindValue(":name", name);
    return db.execQueryAndLogFailure(query);
}

/*
 * Pills::delPills()
 * Description  : Deletes a 'pill_id' from the database.
 * Precondition :
 * Postcondition:
 */
bool Pills::delPills(quint16 pillid) {
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

/*
 * Pills::assignPills()
 * Description  : Assigns an amount 'pill_amount' of 'pill_id' to 'user_id'.
 * Precondition :
 * Postcondition:
 */
bool Pills::assignPills(quint16 user_id, quint16 pill_id, quint8 pill_amount) {
    QSqlQuery query;

    query.prepare("INSERT OR IGNORE INTO pill_groups (pill_id, user_id, amount) VALUES (:pill_id, :user_id, :amount)");
    query.bindValue(":pill_id", pill_id);
    query.bindValue(":user_id", user_id);
    query.bindValue(":amount", pill_amount);

    return db.execQueryAndLogFailure(query);
}

/*
 * Pills::removePills()
 * Description  : Removes a 'pill_id' from 'user_id'.
 * Precondition :
 * Postcondition:
 */
bool Pills::removePills(quint16 userid, quint16 pillid) {
    QSqlQuery query;

    query.prepare("DELETE FROM pill_groups WHERE user_id = :user_id, pill_id = :pill_id");
    query.bindValue(":user_id", userid);
    query.bindValue(":pill_id", pillid);

    return db.execQueryAndLogFailure(query);
}
