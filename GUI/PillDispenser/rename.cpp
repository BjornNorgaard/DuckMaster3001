#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QTextEdit>
#include <QFrame>
#include <QMainWindow>
#include <QPushButton>
#include "rename.h"

Rename::Rename(QWidget *parent, ErrorWindow* err)
    : QWidget(parent)
{
    err_ = err;

    //Creating window specific information and layout
    createWidgets();
    setStyleSheets();
    setLayoutGrids();
    connections();

    //Setting layout
    setLayout(BiggestGrid);

}

void setParent(QWidget *p)
{

}

void Rename::setLayoutGrids()
{
    smallGrid->addWidget(back,0,0);
    smallGrid->addWidget(accept, 0, 1);

    grid->addWidget(LfirstName, 0, 0);
    grid->addWidget(le1, 0, 1);
    grid->addWidget(LlastName, 1, 0);
    grid->addWidget(le2, 1, 1);
    grid->addWidget(Lcpr, 2, 0);
    grid->addWidget(le3, 2, 1);
    grid->addLayout(smallGrid, 3, 1);

    BiggestGrid->addWidget(LEditUser, 0, 0);
    BiggestGrid->addLayout(grid, 1, 0);
}

//Setting the stylesheets for the various elements
void Rename::setStyleSheets()
{
    this->setStyleSheet("background: #97BDD6;");

    /*-------------------------------------*/
    /*-------------- QLabels --------------*/
    /*-------------------------------------*/

    LfirstName->setStyleSheet("color: #ffffff;"
                             "font-size: 20pt;");

    LlastName->setStyleSheet("color: #ffffff;"
                            "font-size: 20pt;");

    Lcpr->setStyleSheet("color: #ffffff;"
                       "font-size: 20pt;");

    LEditUser->setStyleSheet("color: #266873;"
                              "font-size: 30pt;");

    /*-------------------------------------*/
    /*------------ QListEdits -------------*/
    /*-------------------------------------*/

    le1->setStyleSheet("background: white;"
                       " border-radius: 7px;"
                       " border-style: solid;"
                       " border-color: black;"
                       " border-width: 1;"
                       " font-size:20pt;");

    le2->setStyleSheet("background: white;"
                       " border-radius: 7px;"
                       " border-style: solid;"
                       " border-color: black;"
                       " border-width: 1;"
                       " font-size:20pt;");

    le3->setStyleSheet("background: white;"
                       " border-radius: 7px;"
                       " border-style: solid;"
                       " border-color: black;"
                       " border-width: 1;"
                       " font-size:20pt;");

    /*-------------------------------------*/
    /*----------- QPushButtons ------------*/
    /*-------------------------------------*/

    back->setStyleSheet("background: lightgray");
    accept->setStyleSheet("background: lightgray");
}

void Rename::createWidgets()
{
    //Set background color and creating Acceptwindow popup and window definitions
    AW_ = new AcceptPopup;
    AW_->setParent(this);
    Qt::WindowFlags flags = AW_->windowFlags();
    AW_->setWindowFlags(flags | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Dialog );
    AW_->setWindowModality(Qt::WindowModal);
    AW_->move(470, 320);



    //QLabels
    LfirstName = new QLabel("Firstname:", this);
    LlastName = new QLabel("Lastname:", this);
    Lcpr = new QLabel("Cpr-Num:", this);
    LEditUser = new QLabel("Create User", this);

    //QLineEdits
    le1 = new QLineEdit();
    le2 = new QLineEdit();
    le3 = new QLineEdit();

    le1->setFixedSize(300, 50);
    le2->setFixedSize(300, 50);
    le3->setFixedSize(300, 50);

    //QPushButtons
    back = new QPushButton("Back", this);
    accept = new QPushButton("Accept", this);

    back->setFixedSize(145, 50);
    accept->setFixedSize(145, 50);

    //QGridLayouts
    BiggestGrid = new QGridLayout();
    grid = new QGridLayout();
    smallGrid = new QGridLayout();
}

void Rename::closeCurrentWindow()
{
    //Clearing lineedits
    le1->clear();
    le2->clear();
    le3->clear();

    this->close();
}

void Rename::setList(QListWidget* lw)
{
    lw_ = lw;
}

//Slot that setups and opens a new window
void Rename::openNewWindow()
{
    if(le1->text().toCaseFolded().isEmpty() || le2->text().toCaseFolded().isEmpty() || le3->text().toCaseFolded().isEmpty())
    {
        err_->setErrorType(error::NOTEXTERR);
        err_->show();
    } else {
        //Setting info
        AW_->setNames(le1->text().toCaseFolded(),le2->text().toCaseFolded(),le3->text().toCaseFolded());

        //Clearing lineedits
        le1->clear();
        le2->clear();
        le3->clear();

        //Show window
        this->close();
        AW_->show();
    }




}

//Takes a string with full personinfo
//And splits it up for use in editing name
void Rename::title(int windowType)
{
    windowType_ = windowType;

    if(windowType == ADDUSER)
    {
        LEditUser->setText("Create User");
    } else {
        LEditUser->setText("Edit User");
    }
}

void Rename::connections()
{
    connect(accept, SIGNAL(clicked()), this, SLOT(openNewWindow()));
    connect(back, SIGNAL(clicked()), this , SLOT(closeCurrentWindow()));
}

void Rename::setInfo(QString name)
{
    //Creates a list of strings for use
    //QFont f1;
    //with firstname, lastname and cpr
    QStringList list = name.split(",");

    lastName = list[0];
    firstName = list[1];
    cpr = list[2];

    firstName = firstName.simplified();
    firstName.replace( " ", "" );
    firstName = capitalize(firstName);

    lastName = lastName.simplified();
    lastName.replace( " ", "" );
    lastName = capitalize(lastName);

    cpr = cpr.simplified();
    cpr.replace( " ", "" );

    le1->setText(firstName);
    le2->setText(lastName);
    le3->setText(cpr);
}

QString Rename::capitalize(const QString &str)
{
    QString tmp = str;
    // if you want to ensure all other letters are lowercase:
    tmp = tmp.toLower();
    tmp[0] = str[0].toUpper();
    return tmp;
}

Rename::~Rename()
{
    delete AW_;
    delete LfirstName;
    delete LlastName;
    delete Lcpr;
    delete le1;
    delete le2;
    delete le3;
    delete accept;
    delete back;
    delete BiggestGrid;
    delete smallGrid;
}

