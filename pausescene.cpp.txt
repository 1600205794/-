#include "pausescene.h"
#include<QTimer>
#include<mypushbutton.h>
#include"config.h"

Pausescene::Pausescene(QWidget *parent) : QDialog (parent)
{
    this->setFixedSize(406,257);
    this->setWindowTitle("元气骑士");
    setWindowIcon(QIcon("C:/ginger knight/player/warrior1.png"));

    //返回按钮
    MyPushButton *rturn= new MyPushButton("C:/resourse/kaishianniu.png");
    rturn->setParent(this);
    rturn->move(120,150);


    connect(rturn,&MyPushButton::clicked,[=](){
        rturn->zoom1();
        QTimer::singleShot(200,this,[=](){
            m_bPause=false;
            this->close();
        });
    });
}

void Pausescene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("C:/resourse/zantingjiemian.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
