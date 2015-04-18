#ifndef RENAME_H
#define RENAME_H

#include <QMainWindow>
#include <QPushButton>

class Rename : public QWidget
{
    Q_OBJECT

public:
    explicit Rename(QWidget *parent = 0);
    ~Rename();

private slots:
    void closeCurrentWindow();

private:
    QFont f_;
    QPushButton *back;
    QPushButton *accept;

};

#endif // RENAME_H
