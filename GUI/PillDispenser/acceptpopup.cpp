#include "acceptpopup.h"

AcceptPopup::AcceptPopup(QWidget *parent, int choose, Person* ppl) : QWidget(parent), ppl_(ppl)
{

    createWidgets();
    setStyleSheets();
    setLayoutGrids();
    connections();

    //Choose main layout
    setLayout(mainGrid);

}

void AcceptPopup::createWidgets()
{
    //Creating Labels for text
    sure = new QLabel("Are You Sure?", this);
    firstName = new QLabel("Firstname    ", this);
    lastName = new QLabel("Lastname    ", this);
    cpr = new QLabel("Cpr  ", this);
    actualName = new QLabel("Firstname here", this);
    actualLastName = new QLabel("Lastname here", this);
    actualCpr = new QLabel("Cpr here", this);
    spacing = new QLabel("", this);

    //Creating buttons
    back = new QPushButton("No", this);
    accept = new QPushButton("Yes", this);

    //Adding 3 grids for layout customization
    bottomGrid = new QGridLayout();
    buttonGrid = new QGridLayout();
    topGrid = new QGridLayout();
    mainGrid = new QGridLayout();
}

void AcceptPopup::setStyleSheets()
{
    this->setStyleSheet("background: #97BDD6;");

    //Creating custom fonts
    QFont f;
    QFont f1;
    QFont f2;


    f1.setPointSize(17);
    f2.setPointSize(15);


    //Setting Label Fonts
    actualName->setFont(f2);
    actualLastName->setFont(f2);
    actualCpr->setFont(f2);

    //Stylesheets
    sure->setStyleSheet("color: #266873;"
                        "font-size: 30pt;"
                         "font: Cantarell;");

    firstName->setStyleSheet("color: #FFFFFF;"
                         "font-size: 25px;"
                         "font: Cantarell;");

    lastName->setStyleSheet("color: #FFFFFF;"
                         "font-size: 25px;"
                         "font: Cantarell;");

    cpr->setStyleSheet("color: #FFFFFF;"
                         "font-size: 25px;"
                         "font: Cantarell;");

    /*-------------------------------------*/
    /*----------- QPushButtons ------------*/
    /*-------------------------------------*/

    //QPushButtons
    back->setStyleSheet("background: lightgray");
    back->setFont(f1);
    accept->setStyleSheet("background: lightgray");
    accept->setFont(f1);
    back->setFixedSize(145, 50);
    accept->setFixedSize(145, 50);

    //Layout definitions
    mainGrid->setSpacing(9);
    topGrid->setSpacing(10);
}

void AcceptPopup::setLayoutGrids()
{
    //Setting up layouts
    topGrid->addWidget(sure, 0, 0);
    topGrid->addWidget(spacing, 1, 0);

    buttonGrid->addWidget(back, 0, 0);
    buttonGrid->addWidget(accept, 0, 1);

    bottomGrid->addWidget(firstName, 1, 0);
    bottomGrid->addWidget(actualName, 1, 1);
    bottomGrid->addWidget(lastName, 2, 0);
    bottomGrid->addWidget(actualLastName, 2, 1);
    bottomGrid->addWidget(cpr, 3, 0);
    bottomGrid->addWidget(actualCpr, 3, 1);
    bottomGrid->addWidget(spacing, 4, 0);
    bottomGrid->addLayout(buttonGrid,5,1);

    mainGrid->addLayout(topGrid, 0, 0);
    mainGrid->addLayout(bottomGrid, 1, 0);


}

void AcceptPopup::connections()
{
    //Making buttons do actions on clicks
    connect(back, SIGNAL(clicked()), this , SLOT(closeCurrentWindow()));
    connect(accept, SIGNAL(clicked()), this, SLOT(acceptCurrentWindow()));
}

void AcceptPopup::setList(QListWidget* lw)
{
    lw_ = lw;
}

void AcceptPopup::setParent(QWidget *p)
{
    parent_ = p;
}

void AcceptPopup::acceptCurrentWindow()
{
    Person obj;
    this->close();
    //obj.createPerson(actualCpr->text(), actualName->text(), actualLastName->text());
    //ppl_->createPerson(actualCpr->text(), actualName->text(), actualLastName->text());
    //lw_->addItem(actualLastName->text() + ", " + actualName->text() + ", " + actualCpr->text());

    if(type_ == editUser)
    {
        delete lw_->selectedItems().takeFirst();

        //Adds edited user to list
        lw_->addItem(actualLastName->text() + ", " + actualName->text() + ", " + actualCpr->text());

        //modifies name in database
        ppl_->modifyFirstName(id, actualName->text());
        ppl_->modifyLastName(id, actualLastName->text());
        ppl_->modifyCpr(id, actualCpr->text());

    } else if(type_ == createUser) {
        if(ppl_->createPerson(actualCpr->text(), actualName->text(), actualLastName->text()))
            lw_->addItem(actualLastName->text() + ", " + actualName->text() + ", " + actualCpr->text());
    }

    lw_->sortItems(Qt::AscendingOrder);
}

void AcceptPopup::closeCurrentWindow()
{
    this->close();
    parent_->show();
}

void AcceptPopup::setNames(QString fn, QString ln, QString cpr)
{

    actualLastName->clear();
    actualLastName->setText(capitalize(ln));
    actualName->clear();
    actualName->setText(capitalize(fn));
    actualCpr->clear();
    actualCpr->setText(capitalize(cpr));

    ppl_->findPerson(id, cpr);
}

QString AcceptPopup::capitalize(const QString &str)
{
    QString tmp = str;
    // if you want to ensure all other letters are lowercase:
    tmp = tmp.toLower();
    tmp[0] = str[0].toUpper();
    return tmp;
}

void AcceptPopup::setType(QString type)
{
    if(type == "Edit User")
        type_ = editUser;
    else if(type  == "Create User")
        type_ = createUser;
    else
        type_ = deleteUser;
}

AcceptPopup::~AcceptPopup()
{

}


