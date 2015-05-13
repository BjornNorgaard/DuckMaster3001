#ifndef IDLE_H
#define IDLE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class Idle : public QWidget
{
    Q_OBJECT
public:
    explicit Idle(QWidget *parent = 0);
    //~Idle();

signals:

public slots:

private:
    //Creating window specific information and layout
    void createWidgets();
    void setStyleSheets();
    void setLayoutGrids();
    void connections();

    //QLabels
    QLabel *title;
    QLabel *welcome;
    QLabel *info;

    //QVBoxLayout
    QVBoxLayout *grid;
};

#endif // IDLE_H
