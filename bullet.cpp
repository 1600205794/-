#include "bullet.h"
#include<QDebug>
#include<QtMath>


Bullet::Bullet()
{
    m_posX=0;
    m_posY=0;
    m_bFree=true;
    m_speed=BULLET_SPEED;
    m_type=OLD_PISTOL;
    //m_power=BULLET_POWER[m_type][1];
    m_power=3;
    bool ret=m_pix.load(BULLET1);
    if(ret==false){
        qDebug()<<"Bullet图片加载失败";
        return;
    }
    m_rect.setWidth(m_pix.width());
    m_rect.setHeight(m_pix.height());
    m_rect.moveTo(m_posX,m_posY);

}

void Bullet::updatePosition(){

    m_posX += (double)angleX*m_speed;
    m_posY += (double)angleY*m_speed;
    m_rect.moveTo(m_posX,m_posY);

    if(m_posX<=-m_rect.width()+340||m_posX>=GAME_WIDTH+340
            ||m_posY<=-m_rect.height()||m_posY>=GAME_HEIGHT){
        m_bFree=true;
    }
}

void Bullet::updateAngle(int x,int y){
    //位置更新
    double deltaX=x-m_posX;
    double deltaY=y-m_posY;
    //比值
    angleX=(double)deltaX/qSqrt(deltaX*deltaX+deltaY*deltaY);
    angleY=(double)deltaY/qSqrt(deltaX*deltaX+deltaY*deltaY);

    //转过的角度
    m_angle=qAsin(angleY)*180/PAI;
    if(angleX<0){
        if(m_angle>0){
            m_angle=180-m_angle;
        }
        else{
            m_angle=-180-m_angle;
        }
    }

}

void Bullet::updateBullet(bool isBig, int weaponType){
    m_type=weaponType;
    if(isBig){
        m_power=BULLET_POWER[weaponType][1];
        m_pix.load(BULLET_IMGS[weaponType][1]);
    }
    else{
        m_power=BULLET_POWER[weaponType][0];
        m_pix.load(BULLET_IMGS[weaponType][0]);
    }
    m_rect.setWidth(m_pix.width());
    m_rect.setHeight(m_pix.height());
}
