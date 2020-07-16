#ifndef MONSTER_H
#define MONSTER_H
#include"config.h"
#include <QWidget>
#include<QTimer>
#include<QTime>
#include<QPixmap>
#include<QRectF>
#include<QDebug>
#include"renwu.h"
//怪物信息库
class monster1{
public:
    //生命值
    int life=NORMAL_LIFE;
    //是否死亡掉落
    bool alive=true;
    //位置
    int x;
    int y;
    //朝向, true默认朝右
    bool direction=true;
    //速度
    int speed=NORMAL_SPEED;
    //怪物的矩形边框
    QRectF m_rect;
    //怪物的外边框，进入即攻击
    QRectF out_rect;

    //攻击力
    int force=EXTRA_FORCE;

    //更新位置
    /* void position(){
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        if(life<1)return;
        else {

            int flag_x=qrand()%5;
            while(1)
            {
                if(flag_x==3){
                    direction=true;

                    if(x+speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                    else x+=speed;
                    break;
                }
                else if(flag_x==2){
                    direction=false;
                    if(x-speed<ORIGIN_X)x=ORIGIN_X;
                    else  x-=speed;
                    break;
                }
                else  if(flag_x==1){
                    direction=true;
                    if(x+2*speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                    else x+=2*speed;
                    break;
                }
                else if(flag_x==4){
                     direction=false;
                    if(x-2*speed<ORIGIN_X)x=ORIGIN_X;
                    else  x-=2*speed;
                    break;
                }
                else  if(flag_x==0)break;
              }
            int flag_y=qrand()%5;
            while (1) {
                if(flag_y==4){
                    if(y+speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                    else y+=speed;
                    break;
                }
                else if(flag_y==0){
                    if(y-speed<ORIGIN_Y)y=ORIGIN_Y;
                    else  y-=speed;
                    break;
                }
                else if(flag_y==2){
                    if(y+2*speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                    else y+=2*speed;
                    break;
                }
                else if(flag_y==3){
                    if(y-2*speed<ORIGIN_Y)y=ORIGIN_Y;
                    else  y-=2*speed;
                    break;
                }
                else  if(flag_y==1)break;
            }

            m_rect.moveTo(x,y);

        }

    }*/

};
class monster2{
public:
    //生命值
    int life=NORMAL_LIFE;
    //是否死亡掉落
    bool alive=true;
    //位置
    int x=ORIGIN_X;
    int y=ORIGIN_Y;
    //朝向
    bool direction=true;

    //怪物的矩形边框
    QRectF m_rect;
    //怪物的外边框，进入即攻击
    QRectF out_rect;
    //速度
    int speed=NORMAL_SPEED;

    //攻击力
    int force=NORMAL_FORCE;

    bool post=true;
    int temp_x,temp_y;
    //更新位置
    /*void position(){

        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

        if(post){
            temp_x=x;
            temp_y=y;
        }

        if(life<1)return;
        else {
            int flag_x=qrand()%5;
            while(1)
            {
                if(flag_x==4){
                    direction=true;
                    if(x+speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                    else x+=speed;
                    break;
                }
                else if(flag_x==1){
                     direction=false;
                    if(x-speed<ORIGIN_X)x=ORIGIN_X;
                    else  x-=speed;
                    break;
                }
                else  if(flag_x==2){
                    direction=true;
                    if(x+2*speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                    else x+=2*speed;
                    break;
                }
                else if(flag_x==3){
                     direction=false;
                    if(x-2*speed<ORIGIN_X)x=ORIGIN_X;
                    else  x-=2*speed;
                    break;
                }
                else  if(flag_x==0)break;
              }
            int flag_y=qrand()%5;
            while (1) {
                if(flag_y==1){
                    if(y+speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                    else y+=speed;
                    break;
                }
                else if(flag_y==4){
                    if(y-speed<ORIGIN_Y)y=ORIGIN_Y;
                    else  y-=speed;
                    break;
                }
                else if(flag_y==2){
                    if(y+2*speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                    else y+=2*speed;
                    break;
                }
                else if(flag_y==3){
                    if(y-2*speed<ORIGIN_Y)y=ORIGIN_Y;
                    else  y-=2*speed;
                    break;
                }
                else  if(flag_y==0)break;
            }
            m_rect.moveTo(x,y);
        }


    }*/

};
class monster3{
public:
    //生命值
    int life=NORMAL_LIFE;
    //是否死亡掉落
    bool alive=true;
    //位置
    int x=ORIGIN_X;
    int y=ORIGIN_Y;
    //朝向
    bool direction=true;

    //怪物的矩形边框
    QRectF m_rect;
    //怪物的外边框，进入即攻击
    QRectF out_rect;
    //速度
    int speed=FAST_SPEED;

    //攻击力
    int force=EXTRA_FORCE;

    bool post=true;
    int temp_x,temp_y;
    //更新位置
    /*void position(){

      qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

      if(post){
          temp_x=x;
          temp_y=y;
      }

      if(life<1)return;
      else {
          int flag_x=qrand()%5;
          while(1)
          {
              if(flag_x==4){
                  direction=true;
                  if(x+speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                  else x+=speed;
                  break;
              }
              else if(flag_x==0){
                   direction=false;
                  if(x-speed<ORIGIN_X)x=ORIGIN_X;
                  else  x-=speed;
                  break;
              }
              else  if(flag_x==1){
                  direction=true;
                  if(x+2*speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                  else x+=2*speed;
                  break;
              }
              else if(flag_x==3){
                   direction=false;
                  if(x-2*speed<ORIGIN_X)x=ORIGIN_X;
                  else  x-=2*speed;
                  break;
              }
              else  if(flag_x==2)break;
            }
          int flag_y=qrand()%5;
          while (1) {
              if(flag_y==0){
                  if(y+speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                  else y+=speed;
                  break;
              }
              else if(flag_y==1){
                  if(y-speed<ORIGIN_Y)y=ORIGIN_Y;
                  else  y-=speed;
                  break;
              }
              else if(flag_y==2){
                  if(y+2*speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                  else y+=2*speed;
                  break;
              }
              else if(flag_y==3){
                  if(y-2*speed<ORIGIN_Y)y=ORIGIN_Y;
                  else  y-=2*speed;
                  break;
              }
              else  if(flag_y==4)break;
          }
          m_rect.moveTo(x,y);
      }


    }*/

};
class monster4{
public:
    //生命值
    int life=EXTRA_LIFE;
    //是否死亡掉落
    bool alive=true;
    //位置
    int x=ORIGIN_X;
    int y=ORIGIN_Y;
    //朝向
    bool direction=true;

    //怪物的矩形边框
    QRectF m_rect;
    //怪物的外边框，进入即攻击
    QRectF out_rect;
    //速度
    int speed=FAST_SPEED;

    //攻击力
    int force=EXTRA_FORCE;

    bool post=true;
    int temp_x;
    int temp_y;
    //更新位置
    /*void position(){

        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

        if(post){
            temp_x=x;
            temp_y=y;
        }

        if(life<1)return;
        else {
            int flag_x=qrand()%5;
            while(1)
            {
                if(flag_x==0){
                    direction=true;
                    if(x+speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                    else x+=speed;
                    break;
                }
                else if(flag_x==1){
                     direction=false;
                    if(x-speed<ORIGIN_X)x=ORIGIN_X;
                    else  x-=speed;
                    break;
                }
                else  if(flag_x==2){
                    direction=true;
                    if(x+2*speed>ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH)x=ORIGIN_X+GAME_WIDTH-PICTURE_WIDTH;
                    else x+=2*speed;
                    break;
                }
                else if(flag_x==4){
                     direction=false;
                    if(x-2*speed<ORIGIN_X)x=ORIGIN_X;
                    else  x-=2*speed;
                    break;
                }
                else  if(flag_x==3)break;
              }
            int flag_y=qrand()%5;
            while (1) {
                if(flag_y==1){
                    if(y+speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                    else y+=speed;
                    break;
                }
                else if(flag_y==0){
                    if(y-speed<ORIGIN_Y)y=ORIGIN_Y;
                    else  y-=speed;
                    break;
                }
                else if(flag_y==3){
                    if(y+2*speed>ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT)y=ORIGIN_Y+GAME_HEIGHT-PICTURE_HEIGHT;
                    else y+=2*speed;
                    break;
                }
                else if(flag_y==2){
                    if(y-2*speed<ORIGIN_Y)y=ORIGIN_Y;
                    else  y-=2*speed;
                    break;
                }
                else  if(flag_y==4)break;
            }
            m_rect.moveTo(x,y);
        }


    }*/

};
class box{
public:
    //生命值
    int life=NORMAL_LIFE;
    //是否死亡掉落
    bool alive=true;
    //位置
    int x=ORIGIN_X;
    int y=ORIGIN_Y;
    //怪物的矩形边框
    QRectF m_rect;
    //速度
    int speed=NULL;
    //攻击频率
    int at_frequency=NULL;
    //攻击力
    int force=NULL;

};

//怪物子弹库
class monster1_bullet:public monster1
{
public:
    monster1_bullet();

    void updateAngle(int,int,int,int);

    //更新子弹坐标
    void updatePosition();


    //子弹资源对象
    QPixmap B_pixmap;

    //子弹坐标
    int bullet_x;
    int bullet_y;

    double angleX;
    double angleY;

    //子弹状态
    bool bullet_free;

    //子弹矩形框
    QRectF bullet_rect;

    //子弹速度
    int bullet_speed;
    //子弹攻击力
    int bullet_force=force;

};
class monster2_bullet:public monster2
{
public:
    monster2_bullet();

    void updateAngle(int,int,int,int);

    //更新子弹坐标
    void updatePosition();


    //子弹资源对象
    QPixmap B_pixmap;

    //子弹坐标
    int bullet_x;
    int bullet_y;

    double angleX;
    double angleY;

    //子弹状态
    bool bullet_free;

    //子弹矩形框
    QRectF bullet_rect;

    //子弹速度
    int bullet_speed;
    //子弹攻击力
    int bullet_force=force;

};
class monster3_bullet:public monster3
{
public:
    monster3_bullet();

    void updateAngle(int,int,int,int);

    //更新子弹坐标
    void updatePosition();


    //子弹资源对象
    QPixmap B_pixmap;

    //子弹坐标
    int bullet_x;
    int bullet_y;

    double angleX;
    double angleY;

    //子弹状态
    bool bullet_free;

    //子弹矩形框
    QRectF bullet_rect;

    //子弹速度
    int bullet_speed;
    //子弹攻击力
    int bullet_force=force;

};
class monster4_bullet:public monster4
{
public:
    monster4_bullet();

    void updateAngle(int,int,int,int);

    //更新子弹坐标
    void updatePosition();


    //子弹资源对象
    QPixmap B_pixmap;

    //子弹坐标
    int bullet_x;
    int bullet_y;

    double angleX;
    double angleY;

    //子弹状态
    bool bullet_free;

    //子弹矩形框
    QRectF bullet_rect;

    //子弹速度
    int bullet_speed;
    //子弹攻击力
    int bullet_force=force;

};

class Monster : public QWidget
{
    Q_OBJECT
public:
    //生成网格
    int map[BOX_NUMBER][BOX_NUMBER];
    //onelevel表示第一种怪物，以此类推,fivelevel表示箱子数
    int onelevel;
    int twolevel;
    int threelevel;
    int fourlevel;
    int fivelevel;
    //先创建怪物对象，最多八个
    monster1 m_1[ADDUP+LEAST];
    monster2 m_2[ADDUP+LEAST];
    monster3 m_3[ADDUP+LEAST];
    monster4 m_4[ADDUP+LEAST];
    box Box[ADDUP+LEAST*7];

    //创建子弹对象
    monster1_bullet b_1[MONSTER_BULLET_NUM];
    monster2_bullet b_2[MONSTER_BULLET_NUM];
    monster3_bullet b_3[MONSTER_BULLET_NUM];
    monster4_bullet b_4[MONSTER_BULLET_NUM];


    //发射间隔记录
    int bullet_recorder;

    Monster(QWidget *parent = 0);
    ~Monster();


    //预先备案
    void prepare();
    //启动游戏
    void startup();
    //更新坐标
    void updateposition(renwu& player);

    //定时器
    QTimer timer;

    QPixmap monsters;

    //攻击
    void shoot(renwu& player);

    void position();

};

#endif // MONSTER_H
