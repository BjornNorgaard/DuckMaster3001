#include <QApplication>
#include <QPalette>
#include "mainwindow.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Database *db = new Database;

    db->createPerson("123456-7890", "Ole", "Nielsen");
    db->createPerson("232323-2323", "Per", "Eriksen");
    db->createPerson("220192-1697", "Martin", "Carpentier");

    MainWindow window(0, db);
    QPalette Pal(QApplication::palette());

    // set l background
    //Pal.setColor(QPalette::Background, Qt::darkBlue);
    window.setAutoFillBackground(true);
    window.setPalette(Pal);
    window.move(100, 50);
    window.resize(1024, 600);
    //window.showFullScreen();
    window.setWindowTitle("Layouts");
    window.show();

    return app.exec();
}
