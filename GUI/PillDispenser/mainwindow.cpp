#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QListWidget>
#include <QFont>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Database *db) :
    QWidget(parent)
{
    //Window Definitions
    db_ = db;
    lwit = NULL;
    R = new Rename(this);
    R2 = new Rename;
    add_ = new AddUser(this);

    QFont f1;
    vbox = new QVBoxLayout();
    hbox = new QHBoxLayout(this);
    fSmallButton.setPointSize(15);
    f1.setPointSize(23);


    lw = new QListWidget(this);
    db->createList(lw);
    lw->sortItems(Qt::AscendingOrder);

    lw->setFont(f1);
    personInfo_ = "NaN,NaN,000000-0000";

    dispenseButton();
    changePillsButton();
    removeButton();
    renameButton();
    addUserButton();

    vbox->setSpacing(1);
    vbox->addStretch(3);

    connect(lw, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(setItem(QListWidgetItem*)));

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

    connect(dispense, SIGNAL(clicked()), this, SLOT(dispenseButtonClicked()));

}

//Sets the variable fokus on the currently
//marked item on the list
void MainWindow::setItem(QListWidgetItem* item)
{
   personInfo_ = item->text().toCaseFolded();
   lwit = item;
}

void MainWindow::dispenseButtonClicked()
{
    //Send message to user equal to
    //Pills having to be dispensed
    //for current selected user
}

void MainWindow::changePillsButton()
{
    QPushButton *changePills = new QPushButton("Change Pills", this);
    changePills->setFixedSize(300, 70);
    changePills->setFont(fSmallButton);
    vbox->addWidget(changePills);

    connect(changePills, SIGNAL(clicked()), this, SLOT(changePillsButtonClicked()));
}

void MainWindow::changePillsButtonClicked()
{

}

void MainWindow::removeButton()
{
    QPushButton *remove = new QPushButton("Remove", this);
    remove->setFixedSize(300, 70);
    remove->setFont(fSmallButton);
    vbox->addWidget(remove);

    connect(remove, SIGNAL(clicked()), this, SLOT(removeButtonClicked()));
}

void MainWindow::removeButtonClicked()
{
    if(lwit == NULL)
    {
        //Open Window telling user
        //to choose a user
    } else {
        delete lwit;
        lwit = NULL;
    }

    //Add code for deleting user from Data
    //base (could be from a different
    //object/ class
}

void MainWindow::renameButton()
{
    rename = new QPushButton("Rename", this);
    rename->setFixedSize(300, 70);
    rename->setFont(fSmallButton);
    vbox->addWidget(rename);

    connect(rename, SIGNAL(clicked()), this, SLOT(renameButtonClicked()));
}

void MainWindow::renameButtonClicked()
{
    R->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Dialog );
    R->setWindowModality(Qt::WindowModal);
    R->move(400, 300);
    R->setInfo(personInfo_);
    R->show();
}

void MainWindow::addUserButton()
{
    QPushButton *add = new QPushButton("Add User", this);
    add->setFixedSize(300, 70);
    add->setFont(fSmallButton);
    vbox->addWidget(add);

    connect(add, SIGNAL(clicked()), this, SLOT(addUserButtonClicked()));
}

void MainWindow::addUserButtonClicked()
{
    Qt::WindowFlags flags = add_->windowFlags();
    add_->setWindowFlags(flags | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Dialog );
    add_->setWindowModality(Qt::WindowModal);
    add_->move(400, 300);
    add_->show();
    //add_->activateWindow();
}
