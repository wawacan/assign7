#ifndef BOMB_H
#define BOMB_H

#include "timeObject.h"
#include <ctime>
using namespace std;

class Bomb : public TimeObject {
    public:
        Bomb(Icon icon, Position pos);
        void update() override;
        // 判斷時間是否結束需要更換炸彈位置
        bool isExpired() const;
        // 更新的新位置
        void refresh(Position pos);
    private:
        void setPosition(Position newPos);
        bool _needRefresh;
        Position _newPos;
};

#endif
