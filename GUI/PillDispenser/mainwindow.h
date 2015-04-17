#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFont>
#include <QMainWindow>
#include <QVBoxLayout>
#include "rename.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    void dispenseButton();
    void addUserButton();
    void renameButton();
    void renameWindowOpen();
    void removeButton();
    void changePillsButton();
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QFont fSmallButton;
    Rename *R;
};

#endif // MAINWINDOW_H
