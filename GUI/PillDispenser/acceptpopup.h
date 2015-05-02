#ifndef ACCEPTPOPUP_H
#define ACCEPTPOPUP_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

enum chooseWindow {
    deleteUser,
    editUser,
    createUser
};

class AcceptPopup : public QWidget
{
    Q_OBJECT
public:
    explicit AcceptPopup(QWidget *parent = 0, chooseWindow ch = deleteUser);
    void setParent(QWidget *p);
    void setNames(const QString, const QString, const QString);
    QString capitalize(const QString &str);
    void setList(QListWidget* lw);
    void setFunctionality(chooseWindow);
    ~AcceptPopup();

private:
    QWidget* parent_;
    QListWidget* lw_;
    QPushButton* back;
    QPushButton* accept;

    QLabel *actualName;
    QLabel *actualLastName;
    QLabel *actualCpr;

    chooseWindow ch;

signals:

private slots:
    void closeCurrentWindow();
    void acceptCurrentWindow();
};

#endif // ACCEPTPOPUP_H
