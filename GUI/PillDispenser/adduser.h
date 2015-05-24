#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include <QFont>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include "acceptpopup.h"



//Class that contains the addUser
//Window interface
class AddUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = 0);
    void setList(QListWidget* lw);

private slots:
    void closeCurrentWindow();
    void acceptCurrentWindow();

private:
    QListWidget *lw_;
    AcceptPopup* AW_;
    QFont f_;
    QPushButton *back;
    QPushButton *accept;
    Person* ppl;

    QLineEdit *le1;
    QLineEdit *le2;
    QLineEdit *le3;

    void setStyleSheets();
};

#endif // ADDUSER_H
