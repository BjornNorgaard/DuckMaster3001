#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QFrame>
#include <QMainWindow>
#include <QPushButton>
#include <QStatusBar>
#include "adduser.h"

AddUser::AddUser(QWidget *parent)
    : QWidget(parent)
{
    this->setStyleSheet("background: #97BDD6;");
    //Font Definitions
    //QFont f;
    //QFont f1;
    AW_ = new AcceptPopup;
    //f.setPointSize(25);
    //f1.setPointSize(17);

    //Label definitions and font setups
    QLabel *firstName = new QLabel("Firstname:", this);
    firstName->setStyleSheet("color: #ffffff;"
                             "font-size: 20pt;");

    QLabel *lastName = new QLabel("Lastname:", this);
    lastName->setStyleSheet("color: #ffffff;"
                            "font-size: 20pt;");

    QLabel *cpr = new QLabel("Cpr-Num:", this);
    cpr->setStyleSheet("color: #ffffff;"
                       "font-size: 20pt;");

    QLabel *CreateUser = new QLabel("Create User", this);
    CreateUser->setStyleSheet("color: #266873;"
                              "font-size: 30pt;");



    le1 = new QLineEdit(this);
    le1->setFixedSize(300, 50);
    le1->setStyleSheet("background: white;"
                       " border-radius: 7px;"
                       " border-style: solid;"
                       " border-color: black;"
                       " border-width: 1;"
                       " font-size:20pt;");

    le2 = new QLineEdit(this);
    le2->setFixedSize(300, 50);
    le2->setStyleSheet("background: white;"
                       " border-radius: 7px;"
                       " border-style: solid;"
                       " border-color: black;"
                       " border-width: 1;"
                       " font-size:20pt;");
    le3 = new QLineEdit(this);
    le3->setFixedSize(300, 50);
    le3->setStyleSheet("background: white;"
                       " border-radius: 7px;"
                       " border-style: solid;"
                       " border-color: black;"
                       " border-width: 1;"
                       " font-size:20pt;");

    back = new QPushButton("Back", this);
    back->setStyleSheet("background: white");
    back->setFixedSize(145, 50);
    connect(back, SIGNAL(clicked()), this , SLOT(closeCurrentWindow()));

    accept = new QPushButton("Accept", this);
    accept->setStyleSheet("background: white");
    accept->setFixedSize(145, 50);
    connect(accept, SIGNAL(clicked()), this, SLOT(acceptCurrentWindow()));

    QGridLayout *BiggestGrid = new QGridLayout();
    QGridLayout *grid = new QGridLayout();
    QGridLayout *smallGrid = new QGridLayout();

    smallGrid->addWidget(back,0,0);
    smallGrid->addWidget(accept, 0, 1);

    grid->addWidget(firstName, 0, 0);
    grid->addWidget(le1, 0, 1);
    grid->addWidget(lastName, 1, 0);
    grid->addWidget(le2, 1, 1);
    grid->addWidget(cpr, 2, 0);
    grid->addWidget(le3, 2, 1);
    grid->addLayout(smallGrid, 3, 1);

    BiggestGrid->addWidget(CreateUser, 0, 0);
    BiggestGrid->addLayout(grid, 1, 0);

    setLayout(BiggestGrid);
}

void AddUser::closeCurrentWindow()
{
    this->close();
}

void AddUser::acceptCurrentWindow()
{
    this->close();
    AW_->setParent(this);
    AW_->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Dialog );
    AW_->setWindowModality(Qt::WindowModal);
    AW_->move(470, 320);
    AW_->setNames(le1->text(), le2->text(), le3->text());
    AW_->setList(lw_);
    AW_->show();
}

void AddUser::setList(QListWidget* lw)
{
    lw_ = lw;
}
