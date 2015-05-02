#ifndef RENAME_H
#define RENAME_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include "acceptpopup.h"

class Rename : public QWidget
{
    Q_OBJECT

public:
    explicit Rename(QWidget *parent = 0);
    void setInfo(QString);
    void setParent(QWidget *p);

    ~Rename();

private slots:
    void closeCurrentWindow();
    void openNewWindow();

private:
    QFont f_;
    QPushButton *back;
    QPushButton *accept;
    AcceptPopup *AW_;


    //Text edit line pointers
    QLineEdit *le1;
    QLineEdit *le2;
    QLineEdit *le3;

    //Qstrings
    const QString info;
    QString firstName;
    QString lastName;
    QString cpr;

    //Methods
    QString capitalize(const QString &str);
};

#endif // RENAME_H
