#ifndef ACCEPTWINDOW_H
#define ACCEPTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "AddUser.h"

class AcceptWindow : public QWidget
{
Q_OBJECT
public:
    explicit AcceptWindow(QWidget *parent = 0);
    void setParent(QWidget *p);
    //void setParent(AddUser *p);
    ~AcceptWindow();

private:
    QWidget *p;
    QPushButton* back;
    QPushButton* accept;

signals:

private slots:
    void closeCurrentWindow();
    void acceptCurrentWindow();
};

#endif // ACCEPTWINDOW_H
