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
    this->close();
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

    WhatHappened->setStyleSheet("color: #266873;"
                                "font-size: 20pt;"
                                "text-decoration: underline;");

    WhatHappenedText->setStyleSheet("color: #ffffff;"
                                    "font-size: 20pt;");
    WhatHappenedText->setFixedWidth(500);
    WhatHappenedText->setWordWrap(true);

    HowToFix->setStyleSheet("color: #266873;"
                            "font-size: 20pt;"
                            "text-decoration: underline;");

    HowToFixText->setStyleSheet("color: #ffffff;"
                                "font-size: 20pt;");
    HowToFixText->setFixedWidth(500);
    HowToFixText->setWordWrap(true);

    /*-------------------------------------*/
    /*----------- QPushButtons ------------*/
    /*-------------------------------------*/

    Understand->setStyleSheet("background: lightgray");
    Understand->setFixedSize(200, 75);
}

void ErrorWindow::setErrorType(int errType)
{
    switch(errType)
    {
    case error::REMOVEERR:
        removeError();
        break;

    case error::RENAME:
        renameError();
        break;

    case error::DISPENSEERR:
        dispenseError();
        break;

    case error::INVALIDERR:
        invalidNameError();
        break;

    case error::NOUSERERR:
        noUserSelectedError();
        break;

    case error::USEREXIST:
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
    connect(Understand, SIGNAL(clicked()), this, SLOT(closeCurrentWindow()));
}

/*-----------------------------------*/
/*---------- Error Types ------------*/
/*-----------------------------------*/

void ErrorWindow::removeError()
{
    WhatHappenedText->setText("Create User");
    HowToFixText->setText("Create User");
}

void ErrorWindow::renameError()
{
    WhatHappenedText->setText("Create User");
    HowToFixText->setText("Create User");
}

void ErrorWindow::dispenseError()
{
    WhatHappenedText->setText("No user selected from the list on the left side of the buttons");
    HowToFixText->setText("Select user on the list and then click on your desired button");
}

void ErrorWindow::invalidNameError()
{
    WhatHappenedText->setText("Create User");
    HowToFixText->setText("Create User");
}

void ErrorWindow::noUserSelectedError()
{
    WhatHappenedText->setText("No user selected from the list on the left side of the buttons");
    HowToFixText->setText("Select user on the list and then click on your desired button");
}

void ErrorWindow::userExistError()
{
    WhatHappenedText->setText("Create User");
    HowToFixText->setText("Create User");
}

