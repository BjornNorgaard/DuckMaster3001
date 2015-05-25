#include <QApplication>
#include <QPalette>
#include <QWidget>
#include <QStyle>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "idle.h"
#include "database.h"
#include "person.h"
//#include "setupwindow.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //SetupWindow window;
    MainWindow window(0);
    //Idle window(0);

    /*window.setGeometry(
     QStyle::alignedRect(
     Qt::LeftToRight,
     Qt::AlignCenter,
     window.size(),
     qApp->desktop()->availableGeometry()
     ));*/


    //window.move(100, 50);

    window.showFullScreen();
    window.resize(1024, 600);
    window.setWindowTitle("Layouts");
    //window.show();

    return app.exec();
}
