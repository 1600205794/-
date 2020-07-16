#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<mypushbutton.h>
#include<QTimer>
#include<over.h>
#include<mapscene.h>
#include<QSound>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    setFixedSize(1280,920);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon("C:/ginger knight/player/warrior1.png"));
    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
         QSound::play("F:/res/anniu.wav");
        this->close();
    });

    //开始按钮
    MyPushButton * startBtn=new MyPushButton("C:/resourse/kaishianniu.png");
    QSound::play(SOUND_BACKGROUND);
    startBtn->setParent(this);
    startBtn->move(350,700);

    //实例化选择角色场景
    chooseScene=new Choosecharactor;
    //map= new Mapscene;

    connect(startBtn,&MyPushButton::clicked,[=](){
        startBtn->zoom1();
 QSound::play("F:/res/fangjian.wav");
        //延时进入角色选择场景
        QTimer::singleShot(400,this,[=](){
            this->hide();
            chooseScene->show();
        });



    });
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("C:/resourse/fengmian.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
