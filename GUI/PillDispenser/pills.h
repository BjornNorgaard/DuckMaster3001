#ifndef PILLS_H
#define PILLS_H

#include <QString>
#include "database.h"

class Pills {
  public:
    Pills();
    ~Pills();

    bool addPills(quint16 id, QString& name);
    bool delPills(quint16 id);
    bool assignPills(quint16 userid, quint16 pillid, quint8 pillamount);
    bool removePills(quint16 userid, quint16 pillid);

  private:
    enum {
        SQL_PILL_GROUPS_PILL_ID,
        SQL_PILL_GROUPS_USER_ID,
        SQL_PILL_GROUPS_AMOUNT
    }

    enum {
        SQL_PILLS_PILL_ID,
        SQL_PILLS_NAME
    }
};

#endif
