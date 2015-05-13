#ifndef RENAME_H
#define RENAME_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include "errorwindow.h"
#include "acceptpopup.h"

enum {
    ADDUSER,
    RENAMEUSER
};

class ErrorWindow;

class Rename : public QWidget
{
    Q_OBJECT

public:
    explicit Rename(QWidget *parent = 0, ErrorWindow *err = 0);

    void setInfo(QString);
    void setParent(QWidget *p);
    void setList(QListWidget* lw);
    void title(int i);

    ~Rename();

private slots:
    void closeCurrentWindow();
    void openNewWindow();

private:
    QLabel *LEditUser;
    QLabel *Lcpr;
    QLabel *LlastName;
    QLabel *LfirstName;

    QFont f_;
    QPushButton *back;
    QPushButton *accept;
    AcceptPopup *AW_;
    QGridLayout *BiggestGrid;
    QGridLayout *grid;
    QGridLayout *smallGrid;
    QListWidget *lw_;
    ErrorWindow *err_;
    int windowType_;

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
    void createWidgets();
    void setStyleSheets();
    void setLayoutGrids();
    void connections();

};

#endif // RENAME_H
