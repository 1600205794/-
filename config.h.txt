#ifndef CONFIG_H
#define CONFIG_H
#include<QString>

/*****游戏配置数据*****/
#define GAME_WIDTH 800
#define GAME_HEIGHT 800
#define GAME_TITLE "元气骑士 v1.0"
#define PAI 3.14


//骑士数据

#define LENTH 10
#define LLENTH 20
#define RENWU_HEIGHT 70
#define RENWU_WIDTH 70

#define BULLET_SPEED 15
#define BULLET_NUM 30
#define BIG_DURATION 500
#define BLUE_PLUS 250
//人物图片路径
#define KNIGHTZ "C:/ginger knight/player/warrior1.png"
#define KNIGHTF "C:/ginger knight/player/warrior2.png"
#define WIZARDZ "C:/ginger knight/player/fashi.png"
#define WIZARDF
#define RAGERZ "C:/ginger knight/player/youxia.png"
#define RAGERF
#define WEAPON1 "C:/ginger knight/player/weapon1.png"
#define BULLET1 "C:/ginger knight/player/bullet1.png"
#define BULLET2 "C:/ginger knight/player/bullet2.png"

//人物血量蓝量护盾初始值
#define KNIGHTZ_BLOOD 20
#define KNIGHTZ_SHIELD 6
#define KNIGHTZ_ENERGY 200
#define RAGERZ_BLOOD 6
#define RAGERZ_SHIELD 4
#define RAGERZ_ENERGY 200;
#define WIZARDZ_BLOOD 600
#define WIZARDZ_SHIELD 100
#define WIZARDZ_ENERGY 260



//游戏窗口宽高,以及格子数、每个格子的像素

#define PER_BOX 40
#define BOX_NUMBER 20
#define ORIGIN_X 340
#define ORIGIN_Y 60
//屏幕刷新速度
#define GAME_RATE 20
//怪物生命值、速度 、攻击频率及攻击力
#define NORMAL_LIFE 12
#define EXTRA_LIFE 18
#define NORMAL_SPEED 1
#define FAST_SPEED 2
#define NORMAL_AFREQUENCY 2
#define FAST_AFREQUENCY 4
#define NORMAL_FORCE 3
#define EXTRA_FORCE 5

//怪物数量底线和上升空间
#define LEAST 3
#define ADDUP 1
//怪物图片存储路径
#define MONSTER1Z_PATH "C:/ginger knight/monster/monster1Z.png"
#define MONSTER1F_PATH "C:/ginger knight/monster/monster1F.png"
#define MONSTER2Z_PATH "C:/ginger knight/monster/monster2Z.png"
#define MONSTER2F_PATH "C:/ginger knight/monster/monster2F.png"
#define MONSTER3Z_PATH "C:/ginger knight/monster/monster3Z.png"
#define MONSTER3F_PATH "C:/ginger knight/monster/monster3F.png"
#define MONSTER4Z_PATH "C:/ginger knight/monster/monster4Z.png"
#define MONSTER4F_PATH "C:/ginger knight/monster/monster4F.png"
#define BOX_PATH "C:/ginger knight/monster/box.png"
//怪物子弹图片
#define MONSTER1_BULLET "C:/ginger knight/bullet/monster1_bullet.png"
#define MONSTER2_BULLET "C:/ginger knight/bullet/monster2_bullet.png"
#define MONSTER3_BULLET "C:/ginger knight/bullet/monster3_bullet.png"
#define MONSTER4_BULLET "C:/ginger knight/bullet/monster4_bullet.png"
//怪物图片的宽与高
#define PICTURE_WIDTH 40
#define PICTURE_HEIGHT 60
//子弹图片的宽与高
#define BULLET_WIDTH 20
#define BULLET_HEIGHT 20

//子弹弹夹
#define MONSTER_BULLET_NUM 20
#define BULLET_INTERVAL 40
#define SHOOT_DISTANCE 4
//子弹速度
#define MONSTER_BULLET_SPEED 2
//骑士的宽高
#define KNIGHT_WIDTH 40
#define KNIGHT_HEIGHT 60
//音效设置
#define SOUND_BACKGROUND "C:/res/bgm.wav"

//暂停标记
extern bool m_bPause;
//游戏开始（map界面出现）标记
extern bool m_bMapStart;
//游戏结束标记
extern bool m_bOver;

//武器配置
enum{
OLD_PISTOL,ZHONGCAIZHE,XIANGWEISHE,WEAPON_TYPE
};
const QString WEAPON_IMGS[WEAPON_TYPE]={
    "C:/ginger knight/player/weapon1.png",
    "C:/ginger knight/player/weapon2.png",
    "C:/ginger knight/player/weapon3.png",

};
//子弹配置
const QString BULLET_IMGS[WEAPON_TYPE][2]={
    "C:/ginger knight/player/bullet1.png",
    "C:/ginger knight/player/bullet2.png",
    "C:/ginger knight/player/bullet3.jpg",
    "C:/ginger knight/player/bullet4.jpg",
    "C:/ginger knight/player/bullet5.jpg",
    "C:/ginger knight/player/bullet6.jpg",
};
const int BULLET_POWER[WEAPON_TYPE][2]={
    1,2,3,4,4,5
};

#endif // CONFIG_H
