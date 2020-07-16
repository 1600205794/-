#ifndef BULLET_H
#define BULLET_H
#include"config.h"
#include<QPixmap>
#include<QRectF>
enum{
OLD_PISTOL,WEAPON_TYPE
};

class Bullet
{
public:
    Bullet();
    void updatePosition();
    void updateAngle(int,int);
    void updateBullet(bool isBig=false, int weaponType=OLD_PISTOL);

    //子弹坐标
    double m_posX;
    double m_posY;

    //旋转角度
    int m_angle;

    //是否空闲
    bool m_bFree;

    //子弹速度
    int m_speed;

    //谁的子弹 用于碰撞检测 哪方掉血
    int m_whose;

    //种类
    int m_type;

    //子弹的伤害值
    int m_power;

    QPixmap m_pix;
    QRectF m_rect;

private:
    double angleX;
    double angleY;

};

#endif // BULLET_H
