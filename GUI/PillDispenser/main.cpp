#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;

    window.move(1024, 600);
    window.resize(1024, 600);
    window.setWindowTitle("Layouts");
    window.show();

    return app.exec();
}
