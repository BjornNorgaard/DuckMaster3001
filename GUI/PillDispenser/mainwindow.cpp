#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QMessageBox>
#include <QListWidget>
#include <QFont>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Database *db) :
    QWidget(parent)
{
    //Window Definitions
    db_ = db;
    lwit = NULL;
    R = new Rename();
    add_ = new AddUser();


    this->setStyleSheet("background: #000000;");
    QFont f1;
    vbox = new QVBoxLayout();
    hbox = new QHBoxLayout(this);
    fSmallButton.setPointSize(15);
    f1.setPointSize(23);


    lw = new QListWidget(this);

    lw->setStyleSheet("background");
    db->createList(lw);
    lw->sortItems(Qt::AscendingOrder);
    this->setStyleSheet("QComboBox { background-color: blue; }");

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

MainWindow::~MainWindow()
{
    //ButtonDefinitions
    delete remove;
    delete rename;
    delete changePills;
    delete add;
    delete dispense;

    //Custom_Windows
    delete R;
    delete add_;
    delete db_;
    delete lw;
    delete lwit;
    delete vbox;
    delete hbox;
}

//Sets the variable fokus on the currently
//marked item on the list
void MainWindow::setItem(QListWidgetItem* item)
{
   personInfo_ = item->text().toCaseFolded();
   lwit = item;
}

void MainWindow::dispenseButton()
{
    QFont f("Arial Black");
    f.setBold(true);
    f.setPointSize(30);

    dispense = new QPushButton("Dispense", this);
    dispense->setFixedSize(300, 150);
    dispense->setFont(f);
    vbox->addWidget(dispense);
    dispense->setStyleSheet("background-color: lightGray;");


    connect(dispense, SIGNAL(clicked()), this, SLOT(dispenseButtonClicked()));

}

void MainWindow::dispenseButtonClicked()
{
    //Send message to user equal to
    //Pills having to be dispensed
    //for current selected user
}

void MainWindow::changePillsButton()
{
    changePills = new QPushButton("Change Pills", this);
    changePills->setFixedSize(300, 70);
    changePills->setFont(fSmallButton);
    vbox->addWidget(changePills);
    changePills->setStyleSheet("background-color: lightGray;");

    connect(changePills, SIGNAL(clicked()), this, SLOT(changePillsButtonClicked()));
}

void MainWindow::changePillsButtonClicked()
{

}

void MainWindow::removeButton()
{
    remove = new QPushButton("Remove", this);
    remove->setFixedSize(300, 70);
    remove->setFont(fSmallButton);
    vbox->addWidget(remove);
    remove->setStyleSheet("background-color: lightGray;");

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
    rename->setStyleSheet("background-color: lightGray;");

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
    add = new QPushButton("Add User", this);
    add->setFixedSize(300, 70);
    add->setFont(fSmallButton);
    vbox->addWidget(add);
    add->setStyleSheet("background-color: lightGray;");

    connect(add, SIGNAL(clicked()), this, SLOT(addUserButtonClicked()));
}

void MainWindow::addUserButtonClicked()
{
    add_->setWindowFlags( Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Dialog );
    add_->setWindowModality(Qt::WindowModal);
    add_->setList(lw);
    add_->move(400, 300);
    add_->show();
    //add_->activateWindow();
}