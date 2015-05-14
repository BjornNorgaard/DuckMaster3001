#include <QApplication>
#include "mainwindow.h"
#include "database.h"
#include "person.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Database *db = new Database;
    Person *ppl = new Person;
    db->openDB();
    
    ppl->createPerson("123456-7890", "Ole", "Nielsen");
    ppl->createPerson("232323-2323", "Per", "Eriksen");
    ppl->createPerson("220192-1697", "Martin", "Carpentier");

    ppl->modifyCpr(3, "021093-2332");
    ppl->modifyFirstName(3, "Matin");
    ppl->modifyLastName(3, "Ged");

    MainWindow window(0, db);

    window.move(100, 50);
    window.resize(1024, 600);
    //window.showFullScreen();
    window.setWindowTitle("Layouts");
    window.show();

    return app.exec();
}
