#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QWidget>

//ErrorType enums
enum {
    removeErr = 0,
    renameErr = 1,
    dispenseErr = 2,
    invalidNameErr = 3
};

class ErrorWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ErrorWindow(QWidget *parent = 0);
    ~ErrorWindow();

signals:

public slots:
};

#endif // ERRORWINDOW_H
