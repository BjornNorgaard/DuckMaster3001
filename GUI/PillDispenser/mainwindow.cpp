#include <QApplication>
#include <QMessageBox>
#include <QListWidget>
#include <QFont>
#include <QStyle>
#include <QDesktopWidget>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    lwit = NULL;
    personInfo_ = "NaN,NaN,000000-0000";

    createWidgets();
    setStyleSheets();
    setLayoutGrids();
    connections();

    ppl.createList(lw);
    lw->sortItems(Qt::AscendingOrder);

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
    delete lw;
    delete lwit;
    delete vbox;
    delete hbox;
}

void MainWindow::createWidgets()
{
    //Window Definitions
    err_ = new ErrorWindow(this);
    R = new Rename(this, err_, &ppl);

    //ListWidgets
    lw = new QListWidget(this);

    //QPushButtons
    dispense = new QPushButton("Dispense", this);
    changePills = new QPushButton("Change Pills", this);
    rename = new QPushButton("Rename", this);
    remove = new QPushButton("Remove", this);
    add = new QPushButton("Add User", this);

    //Layouts
    vbox = new QVBoxLayout();
    hbox = new QHBoxLayout();


}

void MainWindow::setStyleSheets()
{
    this->setStyleSheet("background: #97BDD6;");

    //Window Styles
    R->setWindowFlags( Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Dialog );
    R->setWindowModality(Qt::WindowModal);
    R->move(250, 100);
    R->title(ADDUSER);

    //Center rename window
    /*R->setGeometry(
     QStyle::alignedRect(
     Qt::LeftToRight,
     Qt::AlignCenter,
     R->size(),
     qApp->desktop()->availableGeometry()
     ));*/


    err_->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::Dialog );
    err_->setWindowModality(Qt::WindowModal);
    err_->resize(500, 450);
    err_->move(250, 50);

    //Center window on screen
    /*err_->setGeometry(
     QStyle::alignedRect(
     Qt::LeftToRight,
     Qt::AlignCenter,
     err_->size(),
     qApp->desktop()->availableGeometry()
     ));*/

    //QFont
    QFont f("Arial Black");
    QFont f1;
    f1.setPointSize(23);
    fSmallButton.setPointSize(15);


    //QPushButtons
    dispense->setStyleSheet("background-color: lightGray;"
                            "padding:5px;");
    f.setBold(true);
    f.setPointSize(30);
    dispense->setFixedSize(300, 150);
    dispense->setFont(f);

    changePills->setStyleSheet("background-color: lightGray;");
    changePills->setFixedSize(300, 70);
    changePills->setFont(fSmallButton);

    remove->setStyleSheet("background-color: lightGray;");
    remove->setFixedSize(300, 70);
    remove->setFont(fSmallButton);

    rename->setStyleSheet("background-color: lightGray;");
    rename->setFixedSize(300, 70);
    rename->setFont(fSmallButton);

    add->setStyleSheet("background-color: lightGray;");
    add->setFixedSize(300, 70);
    add->setFont(fSmallButton);

    //QListWidget
    lw->setStyleSheet("background-color: white");
    lw->setFont(f1);
}

void MainWindow::setLayoutGrids()
{
    vbox->addWidget(dispense);
    vbox->addWidget(changePills);
    vbox->addWidget(remove);
    vbox->addWidget(rename);
    vbox->addWidget(add);
    vbox->setSpacing(1);
    vbox->addStretch(3);
    hbox->addWidget(lw);
    hbox->addSpacing(5);
    hbox->addLayout(vbox);
}

void MainWindow::connections()
{
    connect(dispense, SIGNAL(clicked()), this, SLOT(dispenseButtonClicked()));
    connect(changePills, SIGNAL(clicked()), this, SLOT(changePillsButtonClicked()));
    connect(remove, SIGNAL(clicked()), this, SLOT(removeButtonClicked()));
    connect(rename, SIGNAL(clicked()), this, SLOT(renameButtonClicked()));
    connect(add, SIGNAL(clicked()), this, SLOT(addUserButtonClicked()));
    connect(lw, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(setItem(QListWidgetItem*)));
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

/*-----------------------------------*/
/*------------- Slots ---------------*/
/*-----------------------------------*/

void MainWindow::addUserButtonClicked()
{
    R->setList(lw);
    R->title(ADDUSER);
    R->show();
}

void MainWindow::renameButtonClicked()
{
    if(lwit == NULL)
    {
        err_->setErrorType(error::NOUSERERR);
        err_->show();
        //Open Window telling user
        //to choose a user
    } else {
        //lw->selectionModel()->reset();

        R->setInfo(personInfo_);
        R->title(RENAMEUSER);
        R->show();
    }

}

void MainWindow::removeButtonClicked()
{

    if(lwit == NULL)
    {
        err_->setErrorType(error::NOUSERERR);
        err_->show();
        //Open Window telling user
        //to choose a user
    } else {
        quint16 id;
        ppl.findPerson(id, getCpr(personInfo_));

        lw->selectionModel()->reset();
        ppl.deletePerson(id);

        delete lwit;
        lwit = NULL;
    }

    //Add code for deleting user from Data
    //base (could be from a different
    //object/ class
}

void MainWindow::changePillsButtonClicked()
{

}

//Send message to user equal to
//Pills having to be dispensed
//for current selected user
void MainWindow::dispenseButtonClicked()
{
    if(lwit == NULL)
    {
        err_->setErrorType(error::NOUSERERR);
        err_->show();

        //Open Window telling user
        //to choose a user
    } else {
        lw->selectionModel()->reset();

        pkol_.dispensePill(1, 2);
    }
}

QString MainWindow::getCpr(QString name)
{
    QString cpr;

    //Creates a list of strings for use
    //QFont f1;
    //with firstname, lastname and cpr
    QStringList list = name.split(",");
    cpr = list[2];
    cpr = cpr.simplified();
    cpr.replace( " ", "" );

    return cpr;
}
