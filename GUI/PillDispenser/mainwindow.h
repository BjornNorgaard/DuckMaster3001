#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFont>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <string>
#include <QListWidget>
#include "person.h"
#include "errorwindow.h"
#include "rename.h"
#include "acceptpopup.h"
#include "protokol.h"

class Database;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //Buttons
    void renameButton();
    void dispenseButton();
    void addUserButton();
    void removeButton();
    void changePillsButton();
    QString getCpr(QString name);

    void createWidgets();
    void setStyleSheets();
    void setLayoutGrids();
    void connections();

    //ButtonDefinitions
    QPushButton *remove;
    QPushButton *rename;
    QPushButton *changePills;
    QPushButton *add;
    QPushButton *dispense;

    //Custom_Windows
    Rename *R;
    QString personInfo_;
    Person ppl;
    Protokol pkol_;
    AcceptPopup* AP_;
    ErrorWindow* err_;
    QListWidget *lw;
    QListWidgetItem *lwit;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QFont fSmallButton;


private slots:
    //Button clicks
    void renameButtonClicked();
    void dispenseButtonClicked();
    void addUserButtonClicked();
    void removeButtonClicked();
    void changePillsButtonClicked();
    //List click
    void setItem(QListWidgetItem*);
    void unselect();
};

#endif // MAINWINDOW_H
