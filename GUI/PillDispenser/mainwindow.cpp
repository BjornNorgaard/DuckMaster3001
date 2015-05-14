#include <QApplication>
#include <QMessageBox>
#include <QListWidget>
#include <QFont>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Database *db) :
    QWidget(parent)
{
    //Window Definitions
    R = new Rename(this);
    err_ = new ErrorWindow(this);


    db_ = db;
    lwit = NULL;


    this->setStyleSheet("background: #97BDD6;");
    QFont f1;
    vbox = new QVBoxLayout();
    hbox = new QHBoxLayout(this);
    fSmallButton.setPointSize(15);
    f1.setPointSize(23);

    lw = new QListWidget(this);

    lw->setStyleSheet("background-color: white");
    db->createList(lw);
    lw->sortItems(Qt::AscendingOrder);

    lw->setFont(f1);
    personInfo_ = "NaN,NaN,000000-0000";

    dispenseButton();
    changePillsButton();
    removeButton();
    renameButton();
    addUserButton();

    this->setStyleSheet("QPushButton{ color: blue}:");

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
    delete db_;
    delete lw;
    delete lwit;
    delete vbox;
    delete hbox;
}

//Unselects the list on click
void MainWindow::unselect()
{
    lw = NULL;
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
    dispense->setStyleSheet("background-color: lightGray;"
                            "padding:5px;");


    connect(dispense, SIGNAL(clicked()), this, SLOT(dispenseButtonClicked()));

}


//Send message to user equal to
//Pills having to be dispensed
//for current selected user
void MainWindow::dispenseButtonClicked()
{
    if(lwit == NULL)
    {
        err_->setErrorType(error::NOUSERERR);
        err_->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::Dialog );
        err_->setWindowModality(Qt::WindowModal);
        err_->move(400, 300);
        err_->show();

        //Open Window telling user
        //to choose a user
    } else {
        lw->selectionModel()->reset();

        delete lwit;
        lwit = NULL;
    }
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
        lw->selectionModel()->reset();

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
    if(lwit == NULL)
    {
        err_->setErrorType(error::NOUSERERR);

        //Open Window telling user
        //to choose a user
    } else {
        //lw->selectionModel()->reset();

        R->setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Dialog );
        R->setWindowModality(Qt::WindowModal);
        R->move(400, 300);
        R->setInfo(personInfo_);
        R->title(RENAMEUSER);
        R->show();
    }

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
    R->setWindowFlags( Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Dialog );
    R->setWindowModality(Qt::WindowModal);
    R->setList(lw);
    R->move(400, 300);
    R->title(ADDUSER);
    R->show();
    //add_->activateWindow();
}
