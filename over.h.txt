#ifndef OVER_H
#define OVER_H

#include <QDialog>
#include<QPainter>

class Over : public QDialog
{
    Q_OBJECT
public:
    explicit Over(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:
     void back();
     void gameOver();

public slots:
};

#endif // OVER_H
