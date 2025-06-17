#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"

class Player : public GameObject {
    public:
        Player(Icon icon, Position pos);
        // 更新移動
        void update() override;
        // 設置玩家移動方向
        void setDirection(Direction);
        // 變成鬼魂後的倒數
        void tick();
        // 踩到炸彈變成鬼魂型態
        void becomeGhost();
        // 玩家死亡
        void kill();
        // 吃到藥變回玩家
        void recover();
        // 判斷玩家是不是死了
        bool isDead() const;
        // 判斷玩家是否為鬼魂狀態
        bool isInGhostForm() const;

    private:
        // 移動方向
        Direction _dir;
        bool _isGhost;
        // 變成鬼魂狀態之後的倒數
        int _ghostTimer;
        bool _isAlive;
};

#endif
