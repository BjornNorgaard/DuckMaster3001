#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include <QFont>
#include <QPushButton>

class AddUser : public QWidget
{
    Q_OBJECT

public:
    AddUser(QWidget *parent = 0);

private slots:
    void closeCurrentWindow();

private:
    QFont f_;
    QPushButton *back;
    QPushButton *accept;
};

#endif // ADDUSER_H
