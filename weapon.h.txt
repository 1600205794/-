#ifndef WEAPON_H
#define WEAPON_H
#include"bullet.h"
#include<QPixmap>


class Weapon
{
public:
    Weapon(int type=OLD_PISTOL);
    void shoot(int,int,bool isBig=false);
    //位置追踪骑士
    void setPosition(int,int);

    //武器种类
    int m_type;

    //弹匣
    Bullet m_bullets[BULLET_NUM];
    //坐标
    int m_posX;
    int m_posY;
    //枪口旋转角度
    int m_angle;

    QPixmap m_pix;

    //是否是大招状态
    bool m_bBig;

};

#endif // WEAPON_H

