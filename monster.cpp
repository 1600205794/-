#include "monster.h"
#include"config.h"
#include<QTime>
#include<QTimer>
#include<QDebug>
#include"mainscene.h"
Monster::Monster(QWidget *parent)
    : QWidget(parent)
{


}

Monster::~Monster()
{

}

/*void Monster::initscene()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //定时器初始化
    timer.setInterval(GAME_RATE);
}*/

void Monster::prepare()
{
    //清零地图
       for(int i=0;i<BOX_NUMBER;i++)
           for (int j=0;j<BOX_NUMBER;j++) {
               map[i][j]=0;
           }
       //确认要生成的怪物和箱子数
       //为随机数设初值
       qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
       onelevel=qrand()%ADDUP+LEAST;
       twolevel=qrand()%ADDUP+LEAST;
       threelevel=qrand()%ADDUP+LEAST;
       fourlevel=qrand()%ADDUP+LEAST;
       fivelevel=qrand()%ADDUP+LEAST*7;


       //第一种怪兽备案
       for(int i=0;i<ADDUP+LEAST;i++)
       {
           if(i<onelevel){
               while(1){
                   int a=qrand()%BOX_NUMBER;
                   int b=qrand()%BOX_NUMBER;
                   if(map[a][b]==0){
                       map[a][b]=1;
                       //初始化怪物坐标
                       m_1[i].x=a*PER_BOX+ORIGIN_X;
                       m_1[i].y=b*PER_BOX+ORIGIN_Y;
                       qDebug()<<"x:"<<m_1[0].x<<"y:"<<m_1[0].y;
                       //初始化矩形边框
                       m_1[i].m_rect.setWidth(PICTURE_WIDTH);
                       m_1[i].m_rect.setHeight(PICTURE_HEIGHT);
                       m_1[i].m_rect.moveTo(m_1[i].x,m_1[i].y);
                       //初始化外围边框
                       m_1[i].out_rect.setWidth((2*SHOOT_DISTANCE+1)*PER_BOX);
                       m_1[i].out_rect.setHeight((2*SHOOT_DISTANCE+1)*PER_BOX);
                       m_1[i].out_rect.moveTo(m_1[i].x-SHOOT_DISTANCE*PER_BOX,m_1[i].y-SHOOT_DISTANCE*PER_BOX);
                       break;}
                   else  continue;
               }
           }
           else{
               m_1[i].life=0;
           }
       }
       //第二种
       for(int i=0;i<ADDUP+LEAST;i++)
       {
           if(i<twolevel){
               while(1){
                   int a=qrand()%BOX_NUMBER;
                   int b=qrand()%BOX_NUMBER;
                   if(map[a][b]==0){
                       map[a][b]=2;
                       //初始化怪物坐标
                       m_2[i].x=a*PER_BOX+ORIGIN_X;
                       m_2[i].y=b*PER_BOX+ORIGIN_Y;
                       //初始化矩形边框
                       m_2[i].m_rect.setWidth(PICTURE_WIDTH);
                       m_2[i].m_rect.setHeight(PICTURE_HEIGHT);
                       m_2[i].m_rect.moveTo(m_2[i].x,m_2[i].y);
                       //初始化外围边框
                       m_2[i].out_rect.setWidth(7*PER_BOX);
                       m_2[i].out_rect.setHeight(7*PER_BOX);
                       m_2[i].out_rect.moveTo(m_2[i].x-3*PER_BOX,m_2[i].y-3*PER_BOX);
                       break;}
                   else  continue;
               }
           }
           else{
               m_2[i].life=0;
           }
       }
       //第三种
       for(int i=0;i<ADDUP+LEAST;i++)
       {
           if(i<threelevel){
               while(1){
                   int a=qrand()%BOX_NUMBER;
                   int b=qrand()%BOX_NUMBER;
                   if(map[a][b]==0){
                       map[a][b]=3;
                       //初始化怪物坐标
                       m_3[i].x=a*PER_BOX+ORIGIN_X;
                       m_3[i].y=b*PER_BOX+ORIGIN_Y;
                       //初始化矩形边框
                       m_3[i].m_rect.setWidth(PICTURE_WIDTH);
                       m_3[i].m_rect.setHeight(PICTURE_HEIGHT);
                       m_3[i].m_rect.moveTo(m_3[i].x,m_3[i].y);
                       //初始化外围边框
                       m_3[i].out_rect.setWidth(7*PER_BOX);
                       m_3[i].out_rect.setHeight(7*PER_BOX);
                       m_3[i].out_rect.moveTo(m_3[i].x-3*PER_BOX,m_3[i].y-3*PER_BOX);
                       break;}
                   else  continue;
               }
           }
           else{
               m_3[i].life=0;
           }
       }
       //第四种
       for(int i=0;i<ADDUP+LEAST;i++)
       {
           if(i<fourlevel){
               while(1){
                   int a=qrand()%BOX_NUMBER;
                   int b=qrand()%BOX_NUMBER;
                   if(map[a][b]==0){
                       map[a][b]=4;
                       //初始化怪物坐标
                       m_4[i].x=a*PER_BOX+ORIGIN_X;
                       m_4[i].y=b*PER_BOX+ORIGIN_Y;
                       //初始化矩形边框
                       m_4[i].m_rect.setWidth(PICTURE_WIDTH);
                       m_4[i].m_rect.setHeight(PICTURE_HEIGHT);
                       m_4[i].m_rect.moveTo(m_4[i].x,m_4[i].y);
                       //初始化外围边框
                       m_4[i].out_rect.setWidth(7*PER_BOX);
                       m_4[i].out_rect.setHeight(7*PER_BOX);
                       m_4[i].out_rect.moveTo(m_4[i].x-3*PER_BOX,m_4[i].y-3*PER_BOX);
                       break;}
                   else  continue;
               }
           }
           else{
               m_4[i].life=0;
           }
       }
       //第五种：箱子
       for(int i=0;i<ADDUP+LEAST*7;i++)
       {
           if(i<fivelevel){
               while(1){
                   int a=qrand()%BOX_NUMBER;
                   int b=qrand()%BOX_NUMBER;
                   if(map[a][b]==0){
                       map[a][b]=5;
                       //初始化木箱坐标
                       Box[i].x=a*PER_BOX+ORIGIN_X;
                       Box[i].y=b*PER_BOX+ORIGIN_Y-25;
                       //初始化矩形边框
                       Box[i].m_rect.setWidth(PICTURE_WIDTH);
                       Box[i].m_rect.setHeight(PICTURE_HEIGHT);
                       Box[i].m_rect.moveTo(Box[i].x,Box[i].y);
                       break;}
                   else  continue;
               }
           }
           else{
               Box[i].life=0;
           }
       }


}

/*void Monster::startup()
{

    //启动定时器
    timer.start();
    //开始布置怪物
    prepare();
    //监听定时器的信号
    connect(&timer,&QTimer::timeout,[=](){





        //绘制到屏幕中
        update();

            });

}*/

void Monster::updateposition(renwu& player)
{
    position();
    /*for(int i=0;i<onelevel;i++)
    {
        m_1[i].position();
    }
    for(int i=0;i<twolevel;i++)
    {
        m_2[i].position();
    }
    for(int i=0;i<threelevel;i++)
    {
        m_3[i].position();
    }
    for(int i=0;i<fourlevel;i++)
    {
        m_4[i].position();
    }*/
    //子弹
    shoot(player);
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_1[i].bullet_free==false){

            b_1[i].updatePosition();
        }
    }

    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_2[i].bullet_free==false){

            b_2[i].updatePosition();
        }
    }

    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_3[i].bullet_free==false){

            b_3[i].updatePosition();
        }
    }

    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_4[i].bullet_free==false){

            b_4[i].updatePosition();
        }
    }



}

/*void Monster::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

    //怪物出现

    for(int a=0;a<onelevel;a++)
    {
        if(m_1[a].life<1)continue;
        else {
            if(m_1[a].direction)monsters.load(MONSTER1Z_PATH);
            else  monsters.load(MONSTER1F_PATH);
            painter.drawPixmap(m_1[a].x,m_1[a].y,monsters);
        }
    }

    for(int a=0;a<twolevel;a++)
    {
        if(m_2[a].life<1)continue;
        else {
            if(m_2[a].direction){
                monsters.load(MONSTER2Z_PATH);
                }
            else  monsters.load(MONSTER2F_PATH);
            painter.drawPixmap(m_2[a].x,m_2[a].y,monsters);
        }

    }
    for(int a=0;a<threelevel;a++)
    {
        if(m_3[a].life<1)continue;
        else {
            if(m_3[a].direction)monsters.load(MONSTER3Z_PATH);
            else  monsters.load(MONSTER3F_PATH);
            painter.drawPixmap(m_3[a].x,m_3[a].y,monsters);
        }

    }
    for(int a=0;a<fourlevel;a++)
    {
        if(m_4[a].life<1)continue;
        else {
            if(m_4[a].direction)monsters.load(MONSTER4Z_PATH);
            else  monsters.load(MONSTER4F_PATH);
            painter.drawPixmap(m_4[a].x,m_4[a].y,monsters);
        }

    }
    monsters.load(BOX_PATH);
    for(int a=0;a<fivelevel;a++)
    {
        if(Box[a].life<1)continue;
        else {
            painter.drawPixmap(Box[a].x,Box[a].y,monsters);
        }
    }



    //绘制子弹
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_1[i].bullet_free==false){
            //加载子弹资源
            b_1[i].B_pixmap.load(MONSTER1_BULLET);
            painter.drawPixmap(b_1[i].bullet_x,b_1[i].bullet_y,b_1[i].B_pixmap);}
    }

    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_2[i].bullet_free==false){
            //加载子弹资源
            b_2[i].B_pixmap.load(MONSTER2_BULLET);
            painter.drawPixmap(b_2[i].bullet_x,b_2[i].bullet_y,b_2[i].B_pixmap);}
    }

    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_3[i].bullet_free==false){
            //加载子弹资源
            b_3[i].B_pixmap.load(MONSTER3_BULLET);
            painter.drawPixmap(b_3[i].bullet_x,b_3[i].bullet_y,b_3[i].B_pixmap);}
    }

    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_4[i].bullet_free==false){
            //加载子弹资源
            b_4[i].B_pixmap.load(MONSTER4_BULLET);
            painter.drawPixmap(b_4[i].bullet_x,b_4[i].bullet_y,b_4[i].B_pixmap);}
    }

}*/

/*void Monster::collisionDetection()
{
//子弹与骑士相撞
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_1[i].bullet_free==false){
            if(b_1[i].bullet_rect.intersects(yuanqi.m_rect)){
                yuanqi.life-=b_1[i].bullet_force;
                b_1[i].bullet_free=true;
            }
        }
    }
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_2[i].bullet_free==false){
            if(b_2[i].bullet_rect.intersects(yuanqi.m_rect)){
                yuanqi.life-=b_2[i].bullet_force;
                b_2[i].bullet_free=true;
            }
        }
    }
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_3[i].bullet_free==false){
            if(b_3[i].bullet_rect.intersects(yuanqi.m_rect)){
                yuanqi.life-=b_3[i].bullet_force;
                b_3[i].bullet_free=true;
            }
        }
    }
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(b_4[i].bullet_free==false){
            if(b_4[i].bullet_rect.intersects(yuanqi.m_rect)){
                yuanqi.life-=b_4[i].bullet_force;
                b_4[i].bullet_free=true;
            }
        }
    }



}*/

void Monster::shoot(renwu& player)
{
    //累加时间间隔记录变量
    bullet_recorder++;

    if(bullet_recorder<BULLET_INTERVAL)return;
    bullet_recorder=0;
    //若达到发射时间发射子弹
    for(int i=0;i<onelevel;i++)
    {
        if(m_1[i].life<1)continue;
        //若骑士进入怪物攻击范围
        if(m_1[i].out_rect.intersects(player.m_rect))
        {
            for(int j=0;j<MONSTER_BULLET_NUM;j++)
            {   //如果是空闲子弹，进行发射

                if(b_1[j].bullet_free){
                    b_1[j].bullet_free=false;
                    //设置子弹坐标
                    b_1[j].bullet_x=m_1[i].x+0.5*PICTURE_WIDTH;
                    b_1[j].bullet_y=m_1[i].y+0.5*PICTURE_HEIGHT;

                    b_1[j].updateAngle(player.m_x,player.m_y,m_1[i].x,m_1[i].y);

                    break;
                }
            }
        }
    }

    for(int i=0;i<twolevel;i++)
    {
        if(m_2[i].life<1)continue;
        //若骑士进入怪物攻击范围
        if(m_2[i].out_rect.intersects(player.m_rect))
        {
            for(int j=0;j<MONSTER_BULLET_NUM;j++)
            {   //如果是空闲子弹，进行发射

                if(b_2[j].bullet_free){
                    b_2[j].bullet_free=false;
                    //设置子弹坐标
                    b_2[j].bullet_x=m_2[i].x+0.5*PICTURE_WIDTH;
                    b_2[j].bullet_y=m_2[i].y+0.5*PICTURE_HEIGHT;

                    b_2[j].updateAngle(player.m_x,player.m_y,m_2[i].x,m_2[i].y);

                    break;
                }
            }
        }
    }

    for(int i=0;i<threelevel;i++)
    {
        if(m_3[i].life<1)continue;
        //若骑士进入怪物攻击范围
        if(m_3[i].out_rect.intersects(player.m_rect))
        {
            for(int j=0;j<MONSTER_BULLET_NUM;j++)
            {   //如果是空闲子弹，进行发射

                if(b_3[j].bullet_free){
                    b_3[j].bullet_free=false;
                    //设置子弹坐标
                    b_3[j].bullet_x=m_3[i].x+0.5*PICTURE_WIDTH;
                    b_3[j].bullet_y=m_3[i].y+0.5*PICTURE_HEIGHT;

                    b_3[j].updateAngle(player.m_x,player.m_y,m_3[i].x,m_3[i].y);

                    break;
                }
            }
        }
    }

    for(int i=0;i<fourlevel;i++)
    {
        if(m_4[i].life<1)continue;
        //若骑士进入怪物攻击范围
        if(m_4[i].out_rect.intersects(player.m_rect))
        {
            for(int j=0;j<MONSTER_BULLET_NUM;j++)
            {   //如果是空闲子弹，进行发射

                if(b_4[j].bullet_free){
                    b_4[j].bullet_free=false;
                    //设置子弹坐标
                    b_4[j].bullet_x=m_4[i].x+0.5*PICTURE_WIDTH;
                    b_4[j].bullet_y=m_4[i].y+0.5*PICTURE_HEIGHT;

                    b_4[j].updateAngle(player.m_x,player.m_y,m_4[i].x,m_4[i].y);

                    break;
                }
            }
        }
    }



}

void Monster::position()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    //monster1
    for(int i=0;i<onelevel;i++)
        {
            if(m_1[i].life<1)return;
            int temp_x=m_1[i].x;
            int temp_y=m_1[i].y;
            int flag_x=qrand()%5;
            while(1){
                if(flag_x==3){
                    m_1[i].direction=true;
                    if(m_1[i].x+m_1[i].speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)m_1[i].x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                    else m_1[i].x+=m_1[i].speed;
                    break;
                }
                else if(flag_x==2){
                    m_1[i].direction=false;
                    if(m_1[i].x-m_1[i].speed<ORIGIN_X)m_1[i].x=ORIGIN_X;
                    else  m_1[i].x-=m_1[i].speed;
                    break;
                }
                else  if(flag_x==1){
                    m_1[i].direction=true;
                    if(m_1[i].x+2*m_1[i].speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)m_1[i].x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                    else m_1[i].x+=2*m_1[i].speed;
                    break;
                }
                else if(flag_x==4){
                     m_1[i].direction=false;
                    if(m_1[i].x-2*m_1[i].speed<ORIGIN_X)m_1[i].x=ORIGIN_X;
                    else  m_1[i].x-=2*m_1[i].speed;
                    break;
                }
                else  if(flag_x==0)break;
              }
            int flag_y=qrand()%5;
            while (1) {
                if(flag_y==4){
                    if(m_1[i].y+m_1[i].speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)m_1[i].y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                    else m_1[i].y+=m_1[i].speed;
                    break;
                }
                else if(flag_y==0){
                    if(m_1[i].y-m_1[i].speed<ORIGIN_Y)m_1[i].y=ORIGIN_Y;
                    else  m_1[i].y-=m_1[i].speed;
                    break;
                }
                else if(flag_y==2){
                    if(m_1[i].y+2*m_1[i].speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)m_1[i].y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                    else m_1[i].y+=2*m_1[i].speed;
                    break;
                }
                else if(flag_y==3){
                    if(m_1[i].y-2*m_1[i].speed<ORIGIN_Y)m_1[i].y=ORIGIN_Y;
                    else  m_1[i].y-=2*m_1[i].speed;
                    break;
                }
                else  if(flag_y==1)break;
            }

            m_1[i].m_rect.moveTo(m_1[i].x,m_1[i].y);
           for(int a=0;a<fivelevel;a++)
           {
               if(Box[a].life<1)continue;
               if(m_1[i].m_rect.intersects(Box[a].m_rect)){
                   m_1[i].x=temp_x;
                   m_1[i].y=temp_y;
                   m_1[i].m_rect.moveTo(m_1[i].x,m_1[i].y);
                   break;
               }
           }
        }

    for(int i=0;i<twolevel;i++)
    {
        if(m_2[i].life<1)return;
        int temp_x=m_2[i].x;
        int temp_y=m_2[i].y;
        int flag_x=qrand()%5;
        while(1){
            if(flag_x==3){
                m_2[i].direction=true;
                if(m_2[i].x+m_2[i].speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)m_2[i].x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                else m_2[i].x+=m_2[i].speed;
                break;
            }
            else if(flag_x==2){
                m_2[i].direction=false;
                if(m_2[i].x-m_2[i].speed<ORIGIN_X)m_2[i].x=ORIGIN_X;
                else  m_2[i].x-=m_2[i].speed;
                break;
            }
            else  if(flag_x==1){
                m_2[i].direction=true;
                if(m_2[i].x+2*m_2[i].speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)m_2[i].x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                else m_2[i].x+=2*m_2[i].speed;
                break;
            }
            else if(flag_x==4){
                 m_2[i].direction=false;
                if(m_2[i].x-2*m_2[i].speed<ORIGIN_X)m_2[i].x=ORIGIN_X;
                else  m_2[i].x-=2*m_2[i].speed;
                break;
            }
            else  if(flag_x==0)break;
          }
        int flag_y=qrand()%5;
        while (1) {
            if(flag_y==4){
                if(m_2[i].y+m_2[i].speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)m_2[i].y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                else m_2[i].y+=m_2[i].speed;
                break;
            }
            else if(flag_y==0){
                if(m_2[i].y-m_2[i].speed<ORIGIN_Y)m_2[i].y=ORIGIN_Y;
                else  m_2[i].y-=m_2[i].speed;
                break;
            }
            else if(flag_y==2){
                if(m_2[i].y+2*m_2[i].speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)m_2[i].y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                else m_2[i].y+=2*m_2[i].speed;
                break;
            }
            else if(flag_y==3){
                if(m_2[i].y-2*m_2[i].speed<ORIGIN_Y)m_2[i].y=ORIGIN_Y;
                else  m_2[i].y-=2*m_2[i].speed;
                break;
            }
            else  if(flag_y==1)break;
        }

        m_2[i].m_rect.moveTo(m_2[i].x,m_2[i].y);
       for(int a=0;a<fivelevel;a++)
       {
           if(Box[a].life<1)continue;
           if(m_2[i].m_rect.intersects(Box[a].m_rect)){
               m_2[i].x=temp_x;
               m_2[i].y=temp_y;
               m_2[i].m_rect.moveTo(m_2[i].x,m_2[i].y);
               break;
           }
       }
    }

    for(int i=0;i<threelevel;i++)
    {
        if(m_3[i].life<1)return;
        int temp_x=m_3[i].x;
        int temp_y=m_3[i].y;
        int flag_x=qrand()%5;
        while(1){
            if(flag_x==3){
                m_3[i].direction=true;
                if(m_3[i].x+m_3[i].speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)m_3[i].x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                else m_3[i].x+=m_3[i].speed;
                break;
            }
            else if(flag_x==2){
                m_3[i].direction=false;
                if(m_3[i].x-m_3[i].speed<ORIGIN_X)m_3[i].x=ORIGIN_X;
                else  m_3[i].x-=m_3[i].speed;
                break;
            }
            else  if(flag_x==1){
                m_3[i].direction=true;
                if(m_3[i].x+2*m_3[i].speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)m_3[i].x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                else m_3[i].x+=2*m_3[i].speed;
                break;
            }
            else if(flag_x==4){
                 m_3[i].direction=false;
                if(m_3[i].x-2*m_3[i].speed<ORIGIN_X)m_3[i].x=ORIGIN_X;
                else  m_3[i].x-=2*m_3[i].speed;
                break;
            }
            else  if(flag_x==0)break;
          }
        int flag_y=qrand()%5;
        while (1) {
            if(flag_y==4){
                if(m_3[i].y+m_3[i].speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)m_3[i].y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                else m_3[i].y+=m_3[i].speed;
                break;
            }
            else if(flag_y==0){
                if(m_3[i].y-m_3[i].speed<ORIGIN_Y)m_3[i].y=ORIGIN_Y;
                else  m_3[i].y-=m_3[i].speed;
                break;
            }
            else if(flag_y==2){
                if(m_3[i].y+2*m_3[i].speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)m_3[i].y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                else m_3[i].y+=2*m_3[i].speed;
                break;
            }
            else if(flag_y==3){
                if(m_3[i].y-2*m_3[i].speed<ORIGIN_Y)m_3[i].y=ORIGIN_Y;
                else  m_3[i].y-=2*m_3[i].speed;
                break;
            }
            else  if(flag_y==1)break;
        }

        m_3[i].m_rect.moveTo(m_3[i].x,m_3[i].y);
       for(int a=0;a<fivelevel;a++)
       {
           if(Box[a].life<1)continue;
           if(m_3[i].m_rect.intersects(Box[a].m_rect)){
               m_3[i].x=temp_x;
               m_3[i].y=temp_y;
               m_3[i].m_rect.moveTo(m_3[i].x,m_3[i].y);
               break;
           }
       }
    }

    for(int i=0;i<fourlevel;i++)
    {
        if(m_4[i].life<1)return;
        int temp_x=m_4[i].x;
        int temp_y=m_4[i].y;
        int flag_x=qrand()%5;
        while(1){
            if(flag_x==3){
                m_4[i].direction=true;
                if(m_4[i].x+m_4[i].speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)m_4[i].x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                else m_4[i].x+=m_4[i].speed;
                break;
            }
            else if(flag_x==2){
                m_4[i].direction=false;
                if(m_4[i].x-m_4[i].speed<ORIGIN_X)m_4[i].x=ORIGIN_X;
                else  m_4[i].x-=m_4[i].speed;
                break;
            }
            else  if(flag_x==1){
                m_4[i].direction=true;
                if(m_4[i].x+2*m_4[i].speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)m_4[i].x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                else m_4[i].x+=2*m_4[i].speed;
                break;
            }
            else if(flag_x==4){
                 m_4[i].direction=false;
                if(m_4[i].x-2*m_4[i].speed<ORIGIN_X)m_4[i].x=ORIGIN_X;
                else  m_4[i].x-=2*m_4[i].speed;
                break;
            }
            else  if(flag_x==0)break;
          }
        int flag_y=qrand()%5;
        while (1) {
            if(flag_y==4){
                if(m_4[i].y+m_4[i].speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)m_4[i].y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                else m_4[i].y+=m_4[i].speed;
                break;
            }
            else if(flag_y==0){
                if(m_4[i].y-m_4[i].speed<ORIGIN_Y)m_4[i].y=ORIGIN_Y;
                else  m_4[i].y-=m_4[i].speed;
                break;
            }
            else if(flag_y==2){
                if(m_4[i].y+2*m_4[i].speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)m_4[i].y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                else m_4[i].y+=2*m_4[i].speed;
                break;
            }
            else if(flag_y==3){
                if(m_4[i].y-2*m_4[i].speed<ORIGIN_Y)m_4[i].y=ORIGIN_Y;
                else  m_4[i].y-=2*m_4[i].speed;
                break;
            }
            else  if(flag_y==1)break;
        }

        m_4[i].m_rect.moveTo(m_4[i].x,m_4[i].y);
       for(int a=0;a<fivelevel;a++)
       {
           if(Box[a].life<1)continue;
           if(m_4[i].m_rect.intersects(Box[a].m_rect)){
               m_4[i].x=temp_x;
               m_4[i].y=temp_y;
               m_4[i].m_rect.moveTo(m_4[i].x,m_4[i].y);
               break;
           }
       }
    }

}

