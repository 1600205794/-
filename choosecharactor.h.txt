#ifndef CHOOSECHARACTOR_H
#define CHOOSECHARACTOR_H

#include <QMainWindow>
#include <QWidget>
#include<QPainter>
#include"mapscene.h"
#include<QPixmap>
#include<QRectF>
#include<QKeyEvent>
#include<QImage>
#include"over.h"
#include"renwu.h"
#include"config.h"



class Choosecharactor : public QMainWindow
{
    Q_OBJECT
public:
    explicit Choosecharactor(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    int charct=1;
    Mapscene *mapscene;


signals:

public slots:
};



#endif // CHOOSECHARACTOR_H
