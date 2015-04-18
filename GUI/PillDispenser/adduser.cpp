#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QTextEdit>
#include <QFrame>
#include <QMainWindow>
#include <QPushButton>
#include <QStatusBar>
#include "AddUser.h"

AddUser::AddUser(QWidget *parent)
    : QWidget(parent)
{
    //Font Definitions
    QFont f;
    QFont f1;
    f.setPointSize(25);
    f1.setPointSize(17);

    //Label definitions and font setups
    QLabel *name = new QLabel("Firstname:", this);
    name->setFont(f1);
    QLabel *age = new QLabel("Lastname:", this);
    age->setFont(f1);
    QLabel *occupation = new QLabel("Cpr-Number"
                                  ":", this);
    occupation->setFont(f1);

    QLineEdit *le1 = new QLineEdit(this);
    le1->setFixedSize(300, 50);
    le1->setFont(f);
    QLineEdit *le2 = new QLineEdit(this);
    le2->setFixedSize(300, 50);
    le2->setFont(f);
    QLineEdit *le3 = new QLineEdit(this);
    le3->setFixedSize(300, 50);
    le3->setFont(f);

    back = new QPushButton("Back", this);
    connect(back, SIGNAL(clicked()), this , SLOT(closeCurrentWindow()));

    accept = new QPushButton("Accept", this);

    QGridLayout *grid = new QGridLayout();

    grid->addWidget(name, 0, 0);
    grid->addWidget(le1, 0, 1);
    grid->addWidget(age, 1, 0);
    grid->addWidget(le2, 1, 1);
    grid->addWidget(occupation, 2, 0);
    grid->addWidget(le3, 2, 1);
    grid->addWidget(back, 3,0);
    grid->addWidget(accept,3,1);
    setLayout(grid);

}

void AddUser::closeCurrentWindow()
{
    this->close();
}
