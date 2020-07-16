#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include"choosecharactor.h"
#include<over.h>
#include<mapscene.h>


namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();
    //重写paintEvent事件 画背景图
    void paintEvent(QPaintEvent *);

    Choosecharactor *chooseScene;
    //Mapscene *map;

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
