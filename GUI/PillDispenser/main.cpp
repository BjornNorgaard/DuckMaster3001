#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;

    window.move(100, 50);
    window.resize(1024, 600);
    window.setWindowTitle("Layouts");
    window.show();

    return app.exec();
}
