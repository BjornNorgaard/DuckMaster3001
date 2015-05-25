#ifndef ACCEPTPOPUP_H
#define ACCEPTPOPUP_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "person.h"

enum {
    deleteUser,
    editUser,
    createUser
};

class AcceptPopup : public QWidget
{
    Q_OBJECT
public:
    explicit AcceptPopup(QWidget *parent = 0, int choose = 0, Person* ppl = 0);
    void setParent(QWidget *p);
    void setNames(const QString, const QString, const QString);
    QString capitalize(const QString &str);
    void setList(QListWidget* lw);
    void setFunctionality(int func);
    void setType(QString type);
    ~AcceptPopup();

private:
    QWidget* parent_;
    QListWidget* lw_;
    QPushButton* back;
    QPushButton* accept;

    QLabel *spacing;
    QLabel *sure;
    QLabel *firstName;
    QLabel *lastName;
    QLabel *cpr;
    QLabel *actualName;
    QLabel *actualLastName;
    QLabel *actualCpr;

    Person* ppl_;

    //Adding 3 grids for layout customization
    QGridLayout *bottomGrid;
    QGridLayout *topGrid;
    QGridLayout *mainGrid;
    QGridLayout *buttonGrid;

    int type_;
    quint16 id;

    void createWidgets();
    void setStyleSheets();
    void setLayoutGrids();
    void connections();

signals:

private slots:
    void closeCurrentWindow();
    void acceptCurrentWindow();
};

#endif // ACCEPTPOPUP_H
