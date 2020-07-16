#ifndef RENWU_H
#define RENWU_H
#include<QPixmap>
#include<QRectF>
#include<QKeyEvent>
#include<QImage>
#include"over.h"

class renwu
{
public:
    renwu(int b=1);
    QImage m_renwu;
    int m_x;
    int m_y;
    QRectF m_rect;
    void setPosition(int x,int y);
    void hurt(int x);
    //int b=1;
    int initBlood;
    int blood;//血量
    int initShield;
    int shield;//盾
    int initEnergy;
    int energy;//蓝条
    //int baoji;//暴击
    int m_direction;//朝向 LEFT/RIGHT
    Over *overscene;
};

#endif // RENWU_H
