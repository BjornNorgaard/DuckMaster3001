#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QListWidget>
#include <QFont>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    QFont f1;
    vbox = new QVBoxLayout();
    hbox = new QHBoxLayout(this);
    fSmallButton.setPointSize(15);
    f1.setPointSize(23);


    QListWidget *lw = new QListWidget(this);
    /*
     * for( Every person in database )
     *     lw->addItem(Person)
     *
    */

    lw->setFont(f1);
    lw->addItem("Anders Hansen");
    lw->addItem("Birthe Fransen");
    lw->addItem("Jonas Thomson");
    lw->addItem("Daniel Johnny Pontoppidan");
    lw->addItem("Elsa Mogensen");

    dispenseButton();
    changePillsButton();
    removeButton();
    renameButton();
    addUserButton();

    vbox->setSpacing(1);
    vbox->addStretch(3);

    hbox->addWidget(lw);
    hbox->addSpacing(5);
    hbox->addLayout(vbox);

    setLayout(hbox);
}

void MainWindow::dispenseButton()
{
    QFont f("Arial Black");
    f.setBold(true);
    f.setPointSize(30);

    QPushButton *dispense = new QPushButton("Dispense", this);
    dispense->setFixedSize(300, 150);
    dispense->setFont(f);
    vbox->addWidget(dispense);

    connect(dispense, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MainWindow::changePillsButton()
{
    QPushButton *changePills = new QPushButton("Change Pills", this);
    changePills->setFixedSize(300, 70);
    changePills->setFont(fSmallButton);
    vbox->addWidget(changePills);

    connect(changePills, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MainWindow::removeButton()
{
    QPushButton *remove = new QPushButton("Remove", this);
    remove->setFixedSize(300, 70);
    remove->setFont(fSmallButton);
    vbox->addWidget(remove);

    connect(remove, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MainWindow::renameButton()
{
    QPushButton *rename = new QPushButton("Rename", this);
    rename->setFixedSize(300, 70);
    rename->setFont(fSmallButton);
    vbox->addWidget(rename);

    connect(rename, SIGNAL(clicked()), this, SLOT(renameWindowOpen()));
}

void MainWindow::renameWindowOpen()
{
    R = new Rename();
    R->show();
}

void MainWindow::addUserButton()
{
    QPushButton *add = new QPushButton("Add User", this);
    add->setFixedSize(300, 70);
    add->setFont(fSmallButton);
    vbox->addWidget(add);

    connect(add, SIGNAL(clicked()), qApp, SLOT(quit()));
}
