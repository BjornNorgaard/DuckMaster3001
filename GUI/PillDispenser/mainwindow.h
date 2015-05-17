#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFont>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <string>
#include <QListWidget>
#include "database.h"
#include "errorwindow.h"
#include "rename.h"

class Database;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, Database *db = new Database);
    ~MainWindow();

private:
    //Buttons
    void renameButton();
    void dispenseButton();
    void addUserButton();
    void removeButton();
    void changePillsButton();

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
    Database* db_;
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
