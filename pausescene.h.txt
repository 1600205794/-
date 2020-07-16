#ifndef PAUSESCENE_H
#define PAUSESCENE_H

#include <QDialog>
#include<QPainter>



class Pausescene : public QDialog
{
    Q_OBJECT
public:
    explicit Pausescene(QWidget *parent = nullptr);
     void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // PAUSESCENE_H
