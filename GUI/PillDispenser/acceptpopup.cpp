#include "acceptpopup.h"

AcceptPopup::AcceptPopup(QWidget *parent, chooseWindow ch) : QWidget(parent)
{
    //Creating custom fonts
    QFont f("Arial Black");
    QFont f1;
    QFont f2;

    f.setPointSize(25);
    f1.setPointSize(17);
    f2.setPointSize(15);

    //Creating Labels for text
    QLabel *sure = new QLabel("Are You Sure?", this);
    QLabel *firstName = new QLabel("Firstname:    ", this);
    QLabel *lastName = new QLabel("Lastname:    ", this);
    QLabel *cpr = new QLabel("Cpr:  ", this);
    actualName = new QLabel("Firstname here", this);
    actualLastName = new QLabel("Lastname here", this);
    actualCpr = new QLabel("Cpr here", this);

    //Setting Label Fonts
    sure->setFont(f);
    firstName->setFont(f1);
    lastName->setFont(f1);
    cpr->setFont(f1);
    actualName->setFont(f2);
    actualLastName->setFont(f2);
    actualCpr->setFont(f2);

    //Creating buttons
    back = new QPushButton("No", this);
    accept = new QPushButton("Yes", this);

    //Making buttons do actions on clicks
    connect(back, SIGNAL(clicked()), this , SLOT(closeCurrentWindow()));
    connect(accept, SIGNAL(clicked()), this, SLOT(acceptCurrentWindow()));


    //Adding 3 grids for layout customization
    QGridLayout *bottomGrid = new QGridLayout();
    QGridLayout *topGrid = new QGridLayout();
    QGridLayout *mainGrid = new QGridLayout();

    //Layout definitions
    mainGrid->setSpacing(4);

    //Setting up layouts
    topGrid->addWidget(sure, 0, 0);
    bottomGrid->addWidget(firstName, 1, 0);
    bottomGrid->addWidget(actualName, 1, 1);
    bottomGrid->addWidget(lastName, 2, 0);
    bottomGrid->addWidget(actualLastName, 2, 1);
    bottomGrid->addWidget(cpr, 3, 0);
    bottomGrid->addWidget(actualCpr, 3, 1);
    bottomGrid->addWidget(back, 4,0);
    bottomGrid->addWidget(accept,4,1);
    mainGrid->addLayout(topGrid, 0, 0);
    mainGrid->addLayout(bottomGrid, 1, 0);

    //Choose main layout
    setLayout(mainGrid);
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
    this->close();
    lw_->addItem(actualLastName->text() + ", " + actualName->text() + ", " + actualCpr->text());
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
}

QString AcceptPopup::capitalize(const QString &str)
{
    QString tmp = str;
    // if you want to ensure all other letters are lowercase:
    tmp = tmp.toLower();
    tmp[0] = str[0].toUpper();
    return tmp;
}

AcceptPopup::~AcceptPopup()
{

}


