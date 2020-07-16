#include "weapon.h"
#include<QDebug>

Weapon::Weapon(int type)
{
    bool ret =m_pix.load(WEAPON1);
    if(ret==false){
        qDebug()<<"weapon图片加载失败";
        return;
    }
    m_type=type;
    m_posX=m_posY=0;
    m_bBig=false;
    m_angle=0;
}

void Weapon::shoot(int x,int y, bool isBig){
    m_bBig=isBig;
    for(int i=0;i<BULLET_NUM;i++){
        if(m_bullets[i].m_bFree){
            m_bullets[i].m_bFree=false;
            //每次shoot都重新修改子弹的值
            m_bullets[i].updateBullet(isBig, m_type);
            //子弹从武器射出 位置改变
            m_bullets[i].m_posX=m_posX;
            m_bullets[i].m_posY=m_posY;
            m_bullets[i].updateAngle(x,y);
            m_angle=m_bullets[i].m_angle;
            break;
        }
    }
    qDebug()<<m_type;
}

void Weapon::setPosition(int x,int y){
    m_posX=x;
    m_posY=y;
}
