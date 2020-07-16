#include "renwu.h"
#include"config.h"
#include<QDebug>

//骑士朝向
enum{
    LEFT,RIGHT
};

renwu::renwu(int b)
{

switch(b)
{
case 1:{m_renwu.load(KNIGHTZ);initBlood=blood=KNIGHTZ_BLOOD;initShield=shield=KNIGHTZ_SHIELD;initEnergy=energy=KNIGHTZ_ENERGY;break;}
case 2:{m_renwu.load(RAGERZ);initBlood=blood=RAGERZ_BLOOD;initShield=shield=RAGERZ_SHIELD;initEnergy=energy=RAGERZ_ENERGY;break;}
case 3:{m_renwu.load(WIZARDZ);initBlood=blood=WIZARDZ_BLOOD;initShield=shield=WIZARDZ_SHIELD;initEnergy=energy=WIZARDZ_ENERGY;break;}
default:break;
}

m_x=690;//(GAME_WIDTH-m_renwu.width())*0.5;
m_y=420;//GAME_HEIGHT-m_renwu.height();

m_rect.setWidth(m_renwu.width());
m_rect.setHeight(m_renwu.height());
m_rect.moveTo(m_x,m_y);

//默认向右
m_direction=RIGHT;
}

void renwu::setPosition(int x, int y)
{
    m_x=x;
    m_y=y;
    m_rect.moveTo(m_x,m_y);
}

void renwu::hurt(int x)
{
    if(shield!=0)
    {
        if(x<shield)
    {
        shield=shield-x;
    }
    if(x>shield)
    {
        blood=blood+shield-x;
        shield=0;
    }
    }
    else if(shield==0)
    {
        blood=blood-x;
    }
    if(blood<=0)
    {//游戏结束
        m_rect.moveTo(0,0);
        m_bOver=true;
//        overscene=new Over;
//        overscene->setModal(true);
//        overscene->show();


    }
    //qDebug()<<shield;
}

