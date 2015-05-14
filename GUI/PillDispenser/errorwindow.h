#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include "rename.h"

namespace error
{
    enum
    {
        REMOVEERR,
        RENAME,
        DISPENSEERR,
        INVALIDERR,
        NOUSERERR,
        USEREXIST
    };
}

class ErrorWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ErrorWindow(QWidget *parent = 0);
    void setErrorType(int errorType = 0);
    ~ErrorWindow();


signals:

private slots:
    void closeCurrentWindow();

private:
    //Widgets
    QLabel* title;
    QLabel* errorText;
    QLabel* errNum;
    QLabel* Spacer;
    QLabel* WhatHappened;
    QLabel* WhatHappenedText;
    QLabel* Spacer2;
    QLabel* HowToFix;
    QLabel* HowToFixText;
    QPushButton* Understand;

    QGridLayout* smallGrid;
    QGridLayout* bigGrid;

    //Construction functions
    void createWidgets();
    void setStyleSheets();
    void setLayoutGrids();
    void connections();

    //ErrorWindows to create
    void removeError();
    void renameError();
    void dispenseError();
    void invalidNameError();
    void noUserSelectedError();
    void userExistError();
};

#endif // ERRORWINDOW_H
