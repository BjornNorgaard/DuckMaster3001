#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QTextEdit>
#include <QFrame>
#include <QMainWindow>
#include <QPushButton>
#include <QStatusBar>
#include "rename.h"

Rename::Rename(QWidget *parent)
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
    connect(accept, SIGNAL(clicked()), this , SLOT(openNewWindow()));

    QGridLayout *smallGrid = new QGridLayout();
    QGridLayout *mainGrid = new QGridLayout();

    smallGrid->addWidget(back, 0, 0);
    smallGrid->addWidget(accept, 0, 1);

    mainGrid->addWidget(name, 0, 0);
    mainGrid->addWidget(le1, 0, 1);
    mainGrid->addWidget(age, 1, 0);
    mainGrid->addWidget(le2, 1, 1);
    mainGrid->addWidget(occupation, 2, 0);
    mainGrid->addWidget(le3, 2, 1);
    mainGrid->addLayout(smallGrid,3,1);


    setLayout(mainGrid);

}

void Rename::closeCurrentWindow()
{
    this->close();
}

void setParent(QWidget *p)
{

}

void Rename::openNewWindow()
{
    this->close();
    AW_->setParent(this);
    Qt::WindowFlags flags = AW_->windowFlags();
    AW_->setWindowFlags(flags | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Dialog );
    AW_->setWindowModality(Qt::WindowModal);
    AW_->move(470, 320);
    AW_->setNames(le1->text().toCaseFolded(),le2->text().toCaseFolded(),le3->text().toCaseFolded());
    AW_->show();
}

//Takes a string with full personinfo
//And splits it up for use
void Rename::setInfo(QString name)
{
    //Creates a list of strings for use
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

}

