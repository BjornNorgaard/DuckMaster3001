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
    //Font Definitions
    QFont f;
    QFont f1;
    AW_ = new AcceptPopup;
    f.setPointSize(25);
    f1.setPointSize(17);

    //Label definitions and font setups
    QLabel *name = new QLabel("Firstname:", this);
    name->setFont(f1);
    QLabel *age = new QLabel("Lastname:", this);
    age->setFont(f1);
    QLabel *occupation = new QLabel("Cpr-Number"
                                  ":", this);
    QLabel *CreateUser = new QLabel("Create User", this);
    CreateUser->setStyleSheet("color: darkBlue; font: cantarel 35px;");

    occupation->setFont(f1);

    le1 = new QLineEdit(this);
    le1->setFixedSize(300, 50);
    le1->setFont(f);
    le2 = new QLineEdit(this);
    le2->setFixedSize(300, 50);
    le2->setFont(f);
    le3 = new QLineEdit(this);
    le3->setFixedSize(300, 50);
    le3->setFont(f);

    back = new QPushButton("Back", this);
    connect(back, SIGNAL(clicked()), this , SLOT(closeCurrentWindow()));

    accept = new QPushButton("Accept", this);
    connect(accept, SIGNAL(clicked()), this, SLOT(acceptCurrentWindow()));

    QGridLayout *BiggestGrid = new QGridLayout();
    QGridLayout *grid = new QGridLayout();
    QGridLayout *smallGrid = new QGridLayout();

    smallGrid->addWidget(back,0,0);
    smallGrid->addWidget(accept, 0, 1);

    grid->addWidget(name, 0, 0);
    grid->addWidget(le1, 0, 1);
    grid->addWidget(age, 1, 0);
    grid->addWidget(le2, 1, 1);
    grid->addWidget(occupation, 2, 0);
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
