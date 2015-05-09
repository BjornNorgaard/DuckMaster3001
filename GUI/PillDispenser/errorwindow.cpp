#include "errorwindow.h"

ErrorWindow::ErrorWindow(QWidget *parent) : QWidget(parent)
{
    createWidgets();
    setStyleSheets();
    setLayoutGrids();
    connections();

    setLayout(bigGrid);
}

ErrorWindow::~ErrorWindow()
{
    //QLabels
    delete title;
    delete errorText;
    delete WhatHappened;
    delete WhatHappenedText;
    delete HowToFix;
    delete HowToFixText;
    delete Spacer;
    delete Spacer2;

    //PushButton
    delete Understand;
}

void ErrorWindow::closeCurrentWindow()
{

}

void ErrorWindow::createWidgets()
{
    //QLabels
    title = new QLabel("An Error Happened", this);
    errNum = new QLabel("", this);
    errorText = new QLabel("Don't Worry, just follow the steps below", this);
    WhatHappened = new QLabel("What happened", this);
    WhatHappenedText = new QLabel("cake", this);
    HowToFix = new QLabel("How do i fix it?", this);
    HowToFixText = new QLabel("cake", this);
    Spacer = new QLabel(" ", this);
    Spacer2 = new QLabel(" ", this);

    //PushButton
    Understand = new QPushButton("I Understand", this);
    Understand->setFixedSize(200, 75);

    //Layouts
    smallGrid = new QGridLayout();
    bigGrid = new QGridLayout();
}

void ErrorWindow::setStyleSheets()
{
    this->setStyleSheet("background: #97BDD6;");

    /*-------------------------------------*/
    /*-------------- QLabels --------------*/
    /*-------------------------------------*/

    title->setStyleSheet("color: #266873;"
                              "font-size: 30pt;");

    errorText->setStyleSheet("color: #ffffff;"
                             "font-size: 20pt;");

    WhatHappened->setStyleSheet("color: #ffffff;"
                                "font-size: 20pt;"
                                "text-decoration: underline;");

    WhatHappenedText->setStyleSheet("color: #ffffff;"
                                    "font-size: 20pt;");

    HowToFix->setStyleSheet("color: #ffffff;"
                            "font-size: 20pt;"
                            "text-decoration: underline;");

    HowToFixText->setStyleSheet("color: #ffffff;"
                                "font-size: 20pt;");


    /*-------------------------------------*/
    /*----------- QPushButtons ------------*/
    /*-------------------------------------*/

    Understand->setStyleSheet("background: lightgray");

}

void ErrorWindow::setErrorType(int errType)
{
    switch(errType)
    {
    case REMOVEERR:
        removeError();
        break;

    case RENAME:
        renameError();
        break;

    case DISPENSEERR:
        dispenseError();
        break;

    case INVALIDERR:
        invalidNameError();
        break;

    case NOUSERERR:
        noUserSelectedError();
        break;

    case USEREXIST:
        userExistError();
        break;
    }
}

void ErrorWindow::setLayoutGrids()
{
    smallGrid->addWidget(title, 0, 0);
    smallGrid->addWidget(errNum, 0, 1);
    bigGrid->addLayout(smallGrid, 0, 0);
    bigGrid->addWidget(errorText, 1, 0);
    bigGrid->addWidget(Spacer, 2, 0);

    bigGrid->addWidget(WhatHappened, 3, 0 );
    bigGrid->addWidget(WhatHappenedText, 4, 0);
    bigGrid->addWidget(Spacer2, 5, 0);

    bigGrid->addWidget(HowToFix, 6, 0);
    bigGrid->addWidget(HowToFixText, 7, 0);

    bigGrid->addWidget(Understand, 8, 0, Qt::AlignRight);
}

void ErrorWindow::connections()
{

}

/*-----------------------------------*/
/*---------- Error Types ------------*/
/*-----------------------------------*/

void ErrorWindow::removeError()
{

}

void ErrorWindow::renameError()
{

}

void ErrorWindow::dispenseError()
{

}

void ErrorWindow::invalidNameError()
{

}

void ErrorWindow::noUserSelectedError()
{

}

void ErrorWindow::userExistError()
{

}

