#include"monster.h"
#include"config.h"
#include<QtMath>
#include<QDebug>
monster1_bullet::monster1_bullet()
{
    //子弹速度
    bullet_speed=MONSTER_BULLET_SPEED;
    //子弹坐标
    bullet_x=ORIGIN_X;
    bullet_y=ORIGIN_Y;
    //子弹状态,true表示空闲
    bullet_free=true;
    //子弹边框
    bullet_rect.setWidth(BULLET_WIDTH);
    bullet_rect.setHeight(BULLET_HEIGHT);
    bullet_rect.moveTo(bullet_x,bullet_y);

}
void monster1_bullet::updatePosition()
{
    bullet_x += static_cast<double>(angleX*bullet_speed);
    bullet_y += static_cast<double>(angleY*bullet_speed);
    bullet_rect.moveTo(bullet_x,bullet_y);

    if(bullet_x<=ORIGIN_X||bullet_x>=GAME_WIDTH+ORIGIN_X-BULLET_WIDTH
            ||bullet_y<=ORIGIN_Y||bullet_y>=GAME_HEIGHT+ORIGIN_Y-BULLET_HEIGHT){
        bullet_free=true;
    }

}
void monster1_bullet::updateAngle(int yuanqi_x,int yuanqi_y,int x,int y){
    double deltaX,deltaY;
    int knight_x=yuanqi_x+0.5*KNIGHT_WIDTH;
    int knight_y=yuanqi_y+0.5*KNIGHT_HEIGHT;
    //位置更新
    deltaX=knight_x-x;
    deltaY=knight_y-y;

    angleX=deltaX/qSqrt(deltaX*deltaX+deltaY*deltaY);
    angleY=deltaY/qSqrt(deltaX*deltaX+deltaY*deltaY);

}

monster2_bullet::monster2_bullet()
{
    //子弹速度
    bullet_speed=MONSTER_BULLET_SPEED;
    //子弹坐标
    bullet_x=ORIGIN_X;
    bullet_y=ORIGIN_Y;
    //子弹状态,true表示空闲
    bullet_free=true;
    //子弹边框
    bullet_rect.setWidth(BULLET_WIDTH);
    bullet_rect.setHeight(BULLET_HEIGHT);
    bullet_rect.moveTo(bullet_x,bullet_y);
}
void monster2_bullet::updatePosition()
{
    bullet_x += static_cast<double>(angleX*bullet_speed);
    bullet_y += static_cast<double>(angleY*bullet_speed);
    bullet_rect.moveTo(bullet_x,bullet_y);

    if(bullet_x<=ORIGIN_X||bullet_x>=GAME_WIDTH+ORIGIN_X-BULLET_WIDTH
            ||bullet_y<=ORIGIN_Y||bullet_y>=GAME_HEIGHT+ORIGIN_Y-BULLET_HEIGHT){
        bullet_free=true;
    }

}
void monster2_bullet::updateAngle(int yuanqi_x,int yuanqi_y,int x,int y){
    double deltaX,deltaY;
    int knight_x=yuanqi_x+0.5*KNIGHT_WIDTH;
    int knight_y=yuanqi_y+0.5*KNIGHT_HEIGHT;
    //位置更新
    deltaX=knight_x-x;
    deltaY=knight_y-y;

    angleX=deltaX/qSqrt(deltaX*deltaX+deltaY*deltaY);
    angleY=deltaY/qSqrt(deltaX*deltaX+deltaY*deltaY);

}


monster3_bullet::monster3_bullet()
{
    //子弹速度
    bullet_speed=MONSTER_BULLET_SPEED;
    //子弹坐标
    bullet_x=ORIGIN_X;
    bullet_y=ORIGIN_Y;
    //子弹状态,true表示空闲
    bullet_free=true;
    //子弹边框
    bullet_rect.setWidth(BULLET_WIDTH);
    bullet_rect.setHeight(BULLET_HEIGHT);
    bullet_rect.moveTo(bullet_x,bullet_y);
}
void monster3_bullet::updatePosition()
{
    bullet_x += static_cast<double>(angleX*bullet_speed);
    bullet_y += static_cast<double>(angleY*bullet_speed);
    bullet_rect.moveTo(bullet_x,bullet_y);

    if(bullet_x<=ORIGIN_X||bullet_x>=GAME_WIDTH+ORIGIN_X-BULLET_WIDTH
            ||bullet_y<=ORIGIN_Y||bullet_y>=GAME_HEIGHT+ORIGIN_Y-BULLET_HEIGHT){
        bullet_free=true;
    }

}
void monster3_bullet::updateAngle(int yuanqi_x,int yuanqi_y,int x,int y){
    double deltaX,deltaY;
    int knight_x=yuanqi_x+0.5*KNIGHT_WIDTH;
    int knight_y=yuanqi_y+0.5*KNIGHT_HEIGHT;
    //位置更新
    deltaX=knight_x-x;
    deltaY=knight_y-y;

    angleX=deltaX/qSqrt(deltaX*deltaX+deltaY*deltaY);
    angleY=deltaY/qSqrt(deltaX*deltaX+deltaY*deltaY);

}

monster4_bullet::monster4_bullet()
{
    //子弹速度
    bullet_speed=MONSTER_BULLET_SPEED;
    //子弹坐标
    bullet_x=ORIGIN_X;
    bullet_y=ORIGIN_Y;
    //子弹状态,true表示空闲
    bullet_free=true;
    //子弹边框
    bullet_rect.setWidth(BULLET_WIDTH);
    bullet_rect.setHeight(BULLET_HEIGHT);
    bullet_rect.moveTo(bullet_x,bullet_y);
}
void monster4_bullet::updatePosition()
{
    bullet_x += static_cast<double>(angleX*bullet_speed);
    bullet_y += static_cast<double>(angleY*bullet_speed);
    bullet_rect.moveTo(bullet_x,bullet_y);

    if(bullet_x<=ORIGIN_X||bullet_x>=GAME_WIDTH+ORIGIN_X-BULLET_WIDTH
            ||bullet_y<=ORIGIN_Y||bullet_y>=GAME_HEIGHT+ORIGIN_Y-BULLET_HEIGHT){
        bullet_free=true;
    }

}
void monster4_bullet::updateAngle(int yuanqi_x,int yuanqi_y,int x,int y){
    double deltaX,deltaY;
    int knight_x=yuanqi_x+0.5*KNIGHT_WIDTH;
    int knight_y=yuanqi_y+0.5*KNIGHT_HEIGHT;
    //位置更新
    deltaX=knight_x-x;
    deltaY=knight_y-y;

    angleX=deltaX/qSqrt(deltaX*deltaX+deltaY*deltaY);
    angleY=deltaY/qSqrt(deltaX*deltaX+deltaY*deltaY);

}
