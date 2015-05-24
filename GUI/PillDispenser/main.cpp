#include <QApplication>
#include <QPalette>
#include <QWidget>
#include <QStyle>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "idle.h"
#include "database.h"
#include "person.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Person *ppl = new Person;
    


    MainWindow window(0);
    //Idle window(0);
    window.resize(1024, 600);

    /*window.setGeometry(
     QStyle::alignedRect(
     Qt::LeftToRight,
     Qt::AlignCenter,
     window.size(),
     qApp->desktop()->availableGeometry()
     ));*/


    //window.move(100, 50);

    //window.showFullScreen();
    window.setWindowTitle("Layouts");
    window.show();

    return app.exec();
}
