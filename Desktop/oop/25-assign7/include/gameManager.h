#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "player.h"
#include "bomb.h"
#include "star.h"
#include "medicine.h"
#include "view.h"
#include <vector>

class GameManager {
public:
    GameManager();
    ~GameManager();

    void handleInput(Direction dir);
    void update();
    void updateView(View& view);

    bool isGameOver() const;
    bool isWin() const;

private:
    Player* _player;
    std::vector<Bomb*> _bombs;
    Star* _star;
    Medicine* _medicine;

    int _score;
    // 需要吃到幾顆星星
    const int STAR_TARGET = 5;
    // 處理碰撞
    void handleCollisions();
    // 更新炸彈掉落位置
    void refreshBombs();
    // 變成鬼魂時生成藥
    void spawnMedicine();
    // 將藥移除
    void removeMedicine();
    // 尋找空位避免隨機產生時發生兩個物件剛好在同一格的情形
    Position randomEmptyPosition() const;
};

#endif
