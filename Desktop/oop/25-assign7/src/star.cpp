#include "star.h"

Star::Star(Icon icon, Position pos) : GameObject(icon, pos), _starStatus(false){}

void Star::update(){
    if (_starStatus) {
        // 如果被收集了則更新位置
        setPosition(_newPos);
        _starStatus = false;
    }
}

void Star::beCollected(){
    _starStatus = true;
}

void Star::setPosition(Position newPos){
    _pos = newPos;
}

void Star::refreshStar(Position pos) {
    beCollected();
    _newPos = pos;
}
