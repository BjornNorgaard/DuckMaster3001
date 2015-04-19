#ifndef ACCEPTPOPUP_H
#define ACCEPTPOPUP_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class AcceptPopup : public QWidget
{
    Q_OBJECT
public:
    explicit AcceptPopup(QWidget *parent = 0);
    void setParent(QWidget *p);
    void setNames(const QString, const QString, const QString);
    QString capitalize(const QString &str);
    ~AcceptPopup();

private:
    QWidget* parent_;
    QPushButton* back;
    QPushButton* accept;

    QLabel *actualName;
    QLabel *actualLastName;
    QLabel *actualCpr;

signals:

private slots:
    void closeCurrentWindow();
    void acceptCurrentWindow();
};

#endif // ACCEPTPOPUP_H
