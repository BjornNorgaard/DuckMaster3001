#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFont>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <string>
#include <QListWidget>
#include "Database.hpp"
#include "rename.h"
#include "adduser.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, Database *db = new Database);

private:
    //Buttons
    void renameButton();
    void dispenseButton();
    void addUserButton();
    void removeButton();
    void changePillsButton();

    //Custom_Windows
    Rename *R;
    AddUser *add_;
    Rename *R2;

    QString personInfo_;


    Database* db_;
    QListWidget *lw;
    QListWidgetItem *lwit;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QFont fSmallButton;
    QPushButton *rename;

private slots:
    //Button clicks
    void renameButtonClicked();
    void dispenseButtonClicked();
    void addUserButtonClicked();
    void removeButtonClicked();
    void changePillsButtonClicked();
    //List click
    void setItem(QListWidgetItem*);
};

#endif // MAINWINDOW_H
