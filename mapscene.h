#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QWidget>
#include<QPainter>
#include<pausescene.h>
#include<over.h>
#include"weapon.h"
#include<QTimer>
#include"renwu.h"
#include"monster.h"
#include<QSound>


class Mapscene : public QWidget
{
    Q_OBJECT
public:
    Mapscene(int charct,QWidget *parent = 0);
    ~Mapscene();
    void paintEvent(QPaintEvent *);
    Pausescene *pausescene;
    Over *overScene;
    //主场景绘制
        void initScene();

        //鼠标事件 用于子弹发射
        void mousePressEvent(QMouseEvent *e);

        //更新
        void updatePosition();

        //开始游戏
        void startGame();

        //键盘事件
        void keyPressEvent(QKeyEvent *event);

        //碰撞检测
        void monsterCollision();
        void bulletCollision();

        //weapon对象
        Weapon m_weapon;

        //计时器
        QTimer m_timer;

        //大招持续时间
        int m_bigRecorder;

        //蓝量加一的时间
        int m_blueRecorder;

        //骑士
        renwu m_qs;

        //怪兽
        Monster monster;


signals:


public slots:
};

#endif // MAPSCENE_H
