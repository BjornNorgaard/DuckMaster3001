#include "idle.h"

Idle::Idle(QWidget *parent) : QWidget(parent)
{
    createWidgets();
    setStyleSheets();
    setLayoutGrids();
    connections();

    setLayout(grid);
}

/*Idle::~Idle()
{
    delete title;
}*/

void Idle::createWidgets()
{
    title = new QLabel("PillDispenser3001", this);
    welcome = new QLabel("Welcome!", this);
    info = new QLabel("Please put your finger on the fingerprint scanner to use the machine", this);

    //Layout
    grid = new QVBoxLayout;
}

void Idle::setStyleSheets()
{
    this->setStyleSheet("background: #97BDD6;");

    //QLabels
    title->setStyleSheet("color: #266873;"
                         "font-size: 100px;"
                         "font: Cantarell;");
    title->setContentsMargins(20, 0, 0, 0);

    welcome->setStyleSheet("color: #ffffff;"
                           "font-size: 55px;"
                           "font: italic Cantarell;");
    welcome->setContentsMargins(20, 0, 0, -40);

    info->setStyleSheet("color: #ffffff;"
                        "font-size: 40px;"
                        "font: Cantarell;");
    info->setContentsMargins(20, -100, 0, 0);
    info->setFixedWidth(800);
    info->setWordWrap(true);


}

void Idle::setLayoutGrids()
{
    grid->addWidget(title);
    grid->addWidget(welcome);
    grid->addWidget(info);
}

void Idle::connections()
{

}
