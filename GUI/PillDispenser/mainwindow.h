#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFont>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include "Database.hpp"
#include "rename.h"
#include "AddUser.h"

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

    Database* db_;
    QListWidget *lw;
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
};

#endif // MAINWINDOW_H
