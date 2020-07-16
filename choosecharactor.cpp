#include "choosecharactor.h"
#include<QPainter>
#include<mypushbutton.h>
#include<QTimer>
#include<QSound>

bool m_bMapStart=false;
Choosecharactor::Choosecharactor(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1280,920);
    this->setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon("C:/ginger knight/player/warrior1.png"));


    //右箭头
    MyPushButton * arpb1=new MyPushButton("C:/resourse/jiantou.png");
    arpb1->setParent(this);
    arpb1->move(1125,400);
    arpb1->show();
    MyPushButton * arpb2=new MyPushButton("C:/resourse/jiantou.png");
    arpb2->setParent(this);
    arpb2->move(1125,400);
    arpb2->hide();

    //左箭头
    MyPushButton * zarpb1=new MyPushButton("C:/resourse/zuojiantou.png");
    zarpb1->setParent(this);
    zarpb1->move(10,400);
    zarpb1->show();
    MyPushButton * zarpb2=new MyPushButton("C:/resourse/zuojiantou.png");
    zarpb2->setParent(this);
    zarpb2->move(10,400);
    zarpb2->hide();

    //骑士
    MyPushButton * knight= new MyPushButton("C:/resourse/qishi.png");
    knight->setParent(this);
    knight->move(180,50);
    //游侠
    MyPushButton *ranger=new MyPushButton("C:/resourse/youxia.png");
    ranger->setParent(this);
    ranger->move(180,50);
    ranger->hide();
    //法师
    MyPushButton *mage=new MyPushButton("C:/resourse/fashi.png");
    mage->setParent(this);
    mage->move(180,50);
    mage->hide();
    //继续按钮
    MyPushButton *button=new MyPushButton("C:/resourse/kaishianniu.png");
    button->setParent(this);
    button->move(1050,800);


    //设置右箭头信号
    connect(arpb1,&MyPushButton::clicked,[=](){
        if(charct==1)
        {
        QSound::play("F:/res/anniu.wav");
        knight->hide();
        ranger->show();
        arpb1->hide();
        arpb2->show();
        charct=2;
        }
    });
    connect(arpb2,&MyPushButton::clicked,[=](){
        if(charct==2)
        {
          QSound::play("F:/res/anniu.wav");
        knight->hide();
        ranger->hide();
        mage->show();
        arpb2->hide();
        arpb1->show();
        charct=3;
        }
    });

    //设置左箭头信号
    connect(zarpb1,&MyPushButton::clicked,[=](){
        if(charct==2)
        {
             QSound::play("F:/res/anniu.wav");
         ranger->hide();
         knight->show();
         arpb2->hide();
         arpb1->show();
         charct=1;
        }
        if(charct==3)
        {
             QSound::play("F:/res/anniu.wav");
         mage->hide();
         ranger->show();
         zarpb1->hide();
         zarpb2->show();
         charct=2;
        }
    });
    connect(zarpb2,&MyPushButton::clicked,[=](){
         QSound::play("F:/res/anniu.wav");
        ranger->hide();
        knight->show();
        zarpb2->hide();
        zarpb1->show();
        charct=1;
    });

    //继续按钮信号
    connect(button,&MyPushButton::clicked,[=](){
        button->zoom1();
        //延时进入地图场景
        QTimer::singleShot(200,this,[=](){
            this->hide();
            //实例化地图场景
            mapscene=new Mapscene(charct);
            mapscene->show();
            m_bMapStart=true;
        });
    });


}
void Choosecharactor::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("C:/resourse/juesexuanze.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
