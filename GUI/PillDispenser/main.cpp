#include <QApplication>
#include <QPalette>
#include <QWidget>
#include <QStyle>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "idle.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Database *db = new Database;

    db->createPerson("123456-7890", "Ole", "Nielsen");
    db->createPerson("232323-2323", "Per", "Eriksen");
    db->createPerson("220192-1697", "Martin", "Carpentier");

    //MainWindow window(0, db);
    Idle window(0);
    window.resize(1024, 600);

    window.setGeometry(
     QStyle::alignedRect(
     Qt::LeftToRight,
     Qt::AlignCenter,
     window.size(),
     qApp->desktop()->availableGeometry()
     ));


    //window.move(100, 50);

    //window.showFullScreen();
    window.setWindowTitle("Layouts");
    window.show();

    return app.exec();
}
