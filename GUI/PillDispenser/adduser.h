#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include <QFont>
#include <QPushButton>
#include "acceptpopup.h"


//Class that contains the addUser
//Window interface
class AddUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = 0);

private slots:
    void closeCurrentWindow();
    void acceptCurrentWindow();

private:
    AcceptPopup* AW_;
    QFont f_;
    QPushButton *back;
    QPushButton *accept;
};

#endif // ADDUSER_H
