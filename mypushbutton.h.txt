#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>


class MyPushButton : public QPushButton
{
    Q_OBJECT
public:

    //构造函数 参数1 正常显示的图片路径 参数2 按下后显示的图片路径
    MyPushButton(QString normalImg, QString pressImg="");
    QString normalImgpath;
    QString pressImgpath;

    //弹跳特效
    void zoom1();

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
