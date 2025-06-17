#ifndef STAR_H
#define STAR_H

#include "gameObject.h"

class Star : public GameObject {
public:
    Star(Icon icon, Position pos);
    void update() override;
    // 設置新位置
    void refreshStar(Position pos);

private:
    // 玩家收集星星後呼叫（是否更新位置的依據）
    void beCollected();
    // 設置位置
    void setPosition(Position newPos);
    // 目前是否被玩家收集
    bool _starStatus;
    // 等待更新的新位置
    Position _newPos;
};

#endif
