#include "mapscene.h"
#include<mypushbutton.h>
#include<QTimer>
#include<QDialog>
#include<QPainter>
#include<QMouseEvent>
#include<QDebug>
#include<QPointF>
#include<QSound>
#include<QRect>
#include"mainscene.h"

bool m_bOver=false;
bool m_bPause=false;

enum{
    LEFT,RIGHT
};

Mapscene::Mapscene(int charct,QWidget *parent) : QWidget(parent)
{
    Monster monster;
    m_qs=renwu(charct);
    initScene();
    startGame();



    this->setFixedSize(1280,920);
    this->setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon("C:/ginger knight/player/warrior1.png"));


    //暂停
    MyPushButton *pause=new MyPushButton("C:/resourse/zanting.png");
    pause->setParent(this);
    pause->move(20,30);
    //实例化暂停界面
    pausescene=new Pausescene;
    pausescene->setModal(true);

    //暂停信号
    connect(pause,&MyPushButton::clicked,[=](){
        pause->zoom1();
        QTimer::singleShot(200,this,[=](){

            pausescene->show();
            m_bPause=true;

        });
    });

    //over界面
    overScene=new Over;
    overScene->setModal(true);
    connect(overScene,&Over::gameOver,[=](){
        this->close();
    });
    connect(overScene,&Over::back,[=](){

        this->close();
        MainScene *main=new MainScene();
        main->show();
    });


}

void Mapscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("C:/resourse/bingditu.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load("C:/resourse/xuetiao.png");
    painter.drawPixmap(10,300,250,200,pix);



    if(m_qs.blood<1)return;
    painter.drawImage(m_qs.m_x,m_qs.m_y,m_qs.m_renwu);

    //枪口旋转
    painter.translate(m_weapon.m_posX,m_weapon.m_posY);
    painter.rotate(m_weapon.m_angle);
    painter.drawPixmap(0,0,m_weapon.m_pix);
    painter.resetTransform();

    //画旋转后的子弹
    for(int i=0;i<BULLET_NUM;i++){
        if(m_weapon.m_bullets[i].m_bFree==false){
            //画出旋转效果
            painter.translate(m_weapon.m_bullets[i].m_posX,m_weapon.m_bullets[i].m_posY);
            painter.rotate(m_weapon.m_bullets[i].m_angle);
            painter.drawPixmap(0,0,m_weapon.m_bullets[i].m_pix);
            painter.resetTransform();

        }
    }
    //绘制怪物
    for(int a=0;a<monster.onelevel;a++)
    {
        if(monster.m_1[a].life<1)continue;
        else {
            if(monster.m_1[a].direction)monster.monsters.load(MONSTER1Z_PATH);
            else  monster.monsters.load(MONSTER1F_PATH);
            painter.drawPixmap(monster.m_1[a].x,monster.m_1[a].y,monster.monsters);
        }
    }

    for(int a=0;a<monster.twolevel;a++)
    {
        if(monster.m_2[a].life<1)continue;
        else {
            if(monster.m_2[a].direction){
                monster.monsters.load(MONSTER2Z_PATH);
                }
            else  monster.monsters.load(MONSTER2F_PATH);
            painter.drawPixmap(monster.m_2[a].x,monster.m_2[a].y,monster.monsters);
        }

    }
    for(int a=0;a<monster.threelevel;a++)
    {
        if(monster.m_3[a].life<1)continue;
        else {
            if(monster.m_3[a].direction)monster.monsters.load(MONSTER3Z_PATH);
            else  monster.monsters.load(MONSTER3F_PATH);
            painter.drawPixmap(monster.m_3[a].x,monster.m_3[a].y,monster.monsters);
        }

    }
    for(int a=0;a<monster.fourlevel;a++)
    {
        if(monster.m_4[a].life<1)continue;
        else {
            if(monster.m_4[a].direction)monster.monsters.load(MONSTER4Z_PATH);
            else  monster.monsters.load(MONSTER4F_PATH);
            painter.drawPixmap(monster.m_4[a].x,monster.m_4[a].y,monster.monsters);
        }

    }
    monster.monsters.load(BOX_PATH);
    for(int a=0;a<monster.fivelevel;a++)
    {
        if(monster.Box[a].life<1)continue;
        else {
            painter.drawPixmap(monster.Box[a].x,monster.Box[a].y,monster.monsters);
        }
    }



    //绘制子弹
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(monster.b_1[i].bullet_free==false){
            //加载子弹资源
            monster.b_1[i].B_pixmap.load(MONSTER1_BULLET);
            painter.drawPixmap(monster.b_1[i].bullet_x,monster.b_1[i].bullet_y,monster.b_1[i].B_pixmap);}
    }

    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(monster.b_2[i].bullet_free==false){
            //加载子弹资源
            monster.b_2[i].B_pixmap.load(MONSTER2_BULLET);
            painter.drawPixmap(monster.b_2[i].bullet_x,monster.b_2[i].bullet_y,monster.b_2[i].B_pixmap);}
    }

    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(monster.b_3[i].bullet_free==false){
            //加载子弹资源
            monster.b_3[i].B_pixmap.load(MONSTER3_BULLET);
            painter.drawPixmap(monster.b_3[i].bullet_x,monster.b_3[i].bullet_y,monster.b_3[i].B_pixmap);}
    }

    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
        if(monster.b_4[i].bullet_free==false){
            //加载子弹资源
            monster.b_4[i].B_pixmap.load(MONSTER4_BULLET);
            painter.drawPixmap(monster.b_4[i].bullet_x,monster.b_4[i].bullet_y,monster.b_4[i].B_pixmap);}
    }


    //血条
    QRect bloodBg(90,350,120,10);
    painter.drawRect(bloodBg);

    QBrush brush1(QColor(178,34,34));
    painter.setBrush(brush1);
    painter.drawRect(90,350,120*m_qs.blood/m_qs.initBlood,10);
    painter.setBrush(Qt::NoBrush);

    //能量条
    QRect energyBg(90,390,120,10);
    painter.drawRect(energyBg);

    QBrush brush2(QColor(100,149,237));
    painter.setBrush(brush2);
    painter.drawRect(90,390,120*m_qs.energy/m_qs.initEnergy,10);
    painter.setBrush(Qt::NoBrush);

    //护盾
    QRect shieldBg(90,430,120,10);
    painter.drawRect(shieldBg);

    QBrush brush3(QColor(169,169,169));
    painter.setBrush(brush3);
    painter.drawRect(90,430,120*m_qs.shield/m_qs.initShield,10);
    painter.setBrush(Qt::NoBrush);


    //qDebug()<<m_qs.shield;
    //qDebug()<<m_qs.blood;

}

Mapscene::~Mapscene()
{

}


void Mapscene::initScene(){

    //setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    m_bigRecorder=0;
    m_blueRecorder=0;
    m_bPause=false;
}


void Mapscene::startGame(){
    m_timer.start(GAME_RATE);
    //背景音乐
    QSound::play(SOUND_BACKGROUND);
    //开始布置怪物
    monster.prepare();
    connect(&m_timer,&QTimer::timeout,[=](){
        if(m_bPause==false &
                m_bMapStart==true){
            //更新各元素（bullets weapon monsters）坐标
            updatePosition();
            monster.updateposition(m_qs);
            //碰撞检测
            bulletCollision();
            //更新绘图
            update();
            if(m_bOver==true){
                overScene->show();
                m_bOver=false;
            }
        }

    });


}

void Mapscene::updatePosition(){
    //大招持续时间
    if(m_weapon.m_bBig){
        if(++m_bigRecorder>=BIG_DURATION){
            m_weapon.m_bBig=false;
            m_bigRecorder=0;

        }
    }
    //更新武器坐标（跟踪骑士）
    m_weapon.setPosition(m_qs.m_x+RENWU_WIDTH*0.7,m_qs.m_y+RENWU_HEIGHT*0.5);
    //更新子弹坐标
    for (int i=0;i<BULLET_NUM;i++) {
        if(m_weapon.m_bullets[i].m_bFree==false){
            m_weapon.m_bullets[i].updatePosition();
        }
    }

    //蓝量每5秒自动加一 护盾每五秒加10
    if(++m_blueRecorder>=BLUE_PLUS){
        m_blueRecorder=0;
        if(m_qs.energy<m_qs.initEnergy){
            m_qs.energy++;
        }
        if(m_qs.shield<m_qs.initShield){
            m_qs.shield+=1;
        }
    }

}


void Mapscene::mousePressEvent(QMouseEvent *e){

    if(e->button()==Qt::LeftButton & !m_weapon.m_bBig){
        m_weapon.shoot(e->x(),e->y());
         QSound::play("F:/res/zidan.wav");
    }
    else{
        m_weapon.shoot(e->x(),e->y(),true);
         QSound::play("F:/res/zidan.wav");
    }
    if(m_qs.energy>0)
        m_qs.energy--;
    //蓝量为零时 不能发射子弹
    if(m_qs.energy<=0){
        for(int i=0;i<BULLET_NUM;i++){
            m_weapon.m_bullets[i].m_bFree=true;
        }
    }
}


//键盘事件
void Mapscene::keyPressEvent(QKeyEvent *event){
   if(event->key()==Qt::Key_E)
   {
       m_bOver=true;
   };
    if(event->key()==Qt::Key_W)
    {
        m_qs.m_y=(m_qs.m_y-LENTH<ORIGIN_Y)?m_qs.m_y:m_qs.m_y-LENTH;
        //else  m_qs.m_y-=LENTH;

        m_qs.m_rect.moveTo(m_qs.m_x,m_qs.m_y);
        for(int j=0;j<monster.fivelevel;j++)
        {
            if(monster.Box[j].life<1)continue;
            if(m_qs.m_rect.intersects(monster.Box[j].m_rect))
            {
                m_qs.m_y=m_qs.m_y+LENTH;
                break;
            }
        }
        if ((event->modifiers() == Qt::ControlModifier) && (event->key() == Qt::Key_W))
            m_qs.m_y=m_qs.m_y-LLENTH;
        m_qs.m_rect.moveTo(m_qs.m_x,m_qs.m_y);
        for(int j=0;j<monster.fivelevel;j++)
        {
            if(monster.Box[j].life<1)continue;
            if(m_qs.m_rect.intersects(monster.Box[j].m_rect))
            {
                m_qs.m_y=m_qs.m_y+LLENTH;
                break;
            }
        }

    };
    if(event->key()==Qt::Key_S)
    {
        m_qs.m_y=(m_qs.m_y+LENTH+RENWU_HEIGHT>GAME_HEIGHT+50)?m_qs.m_y:m_qs.m_y+LENTH;
       // else  m_qs.m_y+=LENTH;

        m_qs.m_rect.moveTo(m_qs.m_x,m_qs.m_y);

        for(int j=0;j<monster.fivelevel;j++)
        {
            if(monster.Box[j].life<1)continue;
            if(m_qs.m_rect.intersects(monster.Box[j].m_rect))
            {
                m_qs.m_y=m_qs.m_y-LENTH;
                break;
            }
        }
       if ((event->modifiers() == Qt::ControlModifier) && (event->key() == Qt::Key_S))
            m_qs.m_y=m_qs.m_y+LLENTH;
        m_qs.m_rect.moveTo(m_qs.m_x,m_qs.m_y);
        for(int j=0;j<monster.fivelevel;j++)
        {
            if(monster.Box[j].life<1)continue;
            if(m_qs.m_rect.intersects(monster.Box[j].m_rect))
            {
                m_qs.m_y=m_qs.m_y-LLENTH;
                break;
            }
        }

    };
    if(event->key()==Qt::Key_A)
    {
        //如果本来是右边 换成朝向左边
        if(m_qs.m_direction==RIGHT)
        {
            m_qs.m_renwu=m_qs.m_renwu.mirrored(true,false);
            m_qs.m_direction=LEFT;
        }

         m_qs.m_x=(m_qs.m_x-LENTH<ORIGIN_X)?m_qs.m_x:m_qs.m_x-LENTH;

        m_qs.m_rect.moveTo(m_qs.m_x,m_qs.m_y);
        for(int j=0;j<monster.fivelevel;j++)
        {
            if(monster.Box[j].life<1)continue;
            if(m_qs.m_rect.intersects(monster.Box[j].m_rect))
            {
                m_qs.m_x=m_qs.m_x+LENTH;
                break;
            }
        }
        if ((event->modifiers() == Qt::ControlModifier) && (event->key() == Qt::Key_A))
            m_qs.m_x=m_qs.m_x-LLENTH;
        m_qs.m_rect.moveTo(m_qs.m_x,m_qs.m_y);
        for(int j=0;j<monster.fivelevel;j++)
        {
            if(monster.Box[j].life<1)continue;
            if(m_qs.m_rect.intersects(monster.Box[j].m_rect))
            {
                m_qs.m_x=m_qs.m_x+LLENTH;
                break;
            }
        }

    };
    if(event->key()==Qt::Key_D)
    {
        if(m_qs.m_direction==LEFT)
        {
            m_qs.m_renwu=m_qs.m_renwu.mirrored(true,false);
            m_qs.m_direction=RIGHT;
        }
        m_qs.m_x=(m_qs.m_x+LENTH+RENWU_WIDTH>GAME_WIDTH+340)?m_qs.m_x:m_qs.m_x+LENTH;

        m_qs.m_rect.moveTo(m_qs.m_x,m_qs.m_y);
        for(int j=0;j<monster.fivelevel;j++)
        {
            if(monster.Box[j].life<1)continue;
            if(m_qs.m_rect.intersects(monster.Box[j].m_rect))
            {
                m_qs.m_x=m_qs.m_x-LENTH;
                break;
            }
        }
        if ((event->modifiers() == Qt::ControlModifier) && (event->key() == Qt::Key_D))
            m_qs.m_x=m_qs.m_x+LLENTH;
        m_qs.m_rect.moveTo(m_qs.m_x,m_qs.m_y);
        for(int j=0;j<monster.fivelevel;j++)
        {
            if(monster.Box[j].life<1)continue;
            if(m_qs.m_rect.intersects(monster.Box[j].m_rect))
            {
                m_qs.m_x=m_qs.m_x-LLENTH;
                break;
            }
        }


    }

    //tab键换武器
    if(event->key()==Qt::Key_Tab){
        m_weapon.m_type = (++m_weapon.m_type)%WEAPON_TYPE;
        m_weapon.m_pix.load(WEAPON_IMGS[m_weapon.m_type]);

    }
}

//骑士与怪兽碰撞
/*void Mapscene::monsterCollision(){
    for (int i=0;i<monster.onelevel;i++)
    {
        if(monster.m_1[i].alive-1==0)continue;
        if(m_qs.m_rect.intersects(monster.m_1[i].m_rect))
        {
            hurt(monster.m_1[i].force);
        }
    }
    for (int i=0;i<monster.twolevel;i++)
    {
        if(monster.m_2[i].alive-1==0)continue;
        if(m_qs.m_rect.intersects(monster.m_2[i].m_rect))
        {
            hurt(monster.m_2[i].force);
        }
    }
    for (int i=0;i<monster.threelevel;i++)
    {
        if(monster.m_3[i].alive-1==0)continue;
        if(m_qs.m_rect.intersects(monster.m_3[i].m_rect))
        {
            hurt(monster.m_3[i].force);
        }
    }
    for (int i=0;i<monster.fourlevel;i++)
    {
        if(monster.m_4[i].alive-1==0)continue;
        if(m_qs.m_rect.intersects(monster.m_4[i].m_rect))
        {
            hurt(monster.m_4[i].force);
        }
    }
}*/

//子弹与骑士/怪兽碰撞
void Mapscene::bulletCollision(){
    //怪物子弹与骑士碰撞
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
    {
          if(monster.b_1[i].bullet_free==false){
              if(monster.b_1[i].bullet_rect.intersects(m_qs.m_rect)){
                    m_qs.hurt(monster.b_1[i].bullet_force);
                    monster.b_1[i].bullet_free=true;
                    //QSound::play(SOUND_BACKGROUND);
                }
            }
        }
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
        {
            if(monster.b_2[i].bullet_free==false){
                if(monster.b_2[i].bullet_rect.intersects(m_qs.m_rect)){
                    m_qs.hurt(monster.b_2[i].bullet_force);
                    monster.b_2[i].bullet_free=true;
                    //QSound::play(SOUND_BACKGROUND);
                }
            }
        }
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
        {
            if(monster.b_3[i].bullet_free==false){
                if(monster.b_3[i].bullet_rect.intersects(m_qs.m_rect)){
                    m_qs.hurt(monster.b_3[i].bullet_force);
                    monster.b_3[i].bullet_free=true;
                    //QSound::play(SOUND_BACKGROUND);
                }
            }
        }
    for(int i=0;i<MONSTER_BULLET_NUM;i++)
        {
            if(monster.b_4[i].bullet_free==false){
                if(monster.b_4[i].bullet_rect.intersects(m_qs.m_rect)){
                    m_qs.hurt(monster.b_4[i].bullet_force);
                    monster.b_4[i].bullet_free=true;
                    //QSound::play(SOUND_BACKGROUND);
                }
            }
     }

    //骑士子弹与怪物碰撞
    for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_weapon.m_bullets[i].m_bFree)continue;
        //判断怪物是否存活
        for(int j=0;j<monster.onelevel;j++)
        {
            if(monster.m_1[j].life<1)continue;
            //发生碰撞
            if(m_weapon.m_bullets[i].m_rect.intersects(monster.m_1[j].m_rect)){
                monster.m_1[j].life-=m_weapon.m_bullets[i].m_power;
                m_weapon.m_bullets[i].m_bFree=true;}
        }

        for(int j=0;j<monster.twolevel;j++)
        {
            if(monster.m_2[j].life<1)continue;
            //发生碰撞
            if(m_weapon.m_bullets[i].m_rect.intersects(monster.m_2[j].m_rect)){
                monster.m_2[j].life-=m_weapon.m_bullets[i].m_power;
                 m_weapon.m_bullets[i].m_bFree=true;}
        }

        for(int j=0;j<monster.threelevel;j++)
        {
            if(monster.m_3[j].life<1)continue;
            //发生碰撞
            if(m_weapon.m_bullets[i].m_rect.intersects(monster.m_3[j].m_rect)){
                monster.m_3[j].life-=m_weapon.m_bullets[i].m_power;
                 m_weapon.m_bullets[i].m_bFree=true;}
        }

        for(int j=0;j<monster.fourlevel;j++)
        {
            if(monster.m_4[j].life<1)continue;
            //发生碰撞
            if(m_weapon.m_bullets[i].m_rect.intersects(monster.m_4[j].m_rect)){
                monster.m_4[j].life-=m_weapon.m_bullets[i].m_power;
                 m_weapon.m_bullets[i].m_bFree=true;}
        }

        for(int j=0;j<monster.fivelevel;j++)
        {
            if(monster.Box[j].life<1)continue;
            if(m_weapon.m_bullets[i].m_rect.intersects(monster.Box[j].m_rect)){
                monster.Box[j].life-=m_weapon.m_bullets[i].m_power;
                 m_weapon.m_bullets[i].m_bFree=true;}
        }



    }
}


