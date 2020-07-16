#include "over.h"
#include<QTimer>
#include<mypushbutton.h>

Over::Over(QWidget *parent) : QDialog (parent)
{
    this->setFixedSize(406,257);
    this->setWindowTitle("元气骑士");
    setWindowIcon(QIcon("C:/ginger knight/player/warrior1.png"));


    //重新开始
    MyPushButton *returnmain=new MyPushButton("C:/resourse/chongxinkaishi.png");
    returnmain->setParent(this);
    returnmain->move(100,150);
    connect(returnmain,&MyPushButton::clicked,[=](){
        this->close();
        emit this->back();
    });
    //退出游戏
    MyPushButton *exit=new MyPushButton("C:/resourse/xiaoguanbi.png");
    exit->setParent(this);
    exit->move(250,150);
    connect(exit,&QPushButton::clicked,[=](){
        exit->zoom1();
        QTimer::singleShot(200,this,[=](){

            this->close();
            emit this->gameOver();

        });
    });
}

void Over::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("C:/resourse/jieshujiemian.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
