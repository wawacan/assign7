#include "bomb.h"

Bomb::Bomb(Icon icon, Position pos) : TimeObject(icon, pos), _needRefresh(false){
}

void Bomb::update(){
    if (_needRefresh) {
        setPosition(_newPos);
        resetTimer();
        _needRefresh = false;
    }
}

bool Bomb::isExpired() const{
    return TimeObject::isExpired(5.0);
}

void Bomb::refresh(Position pos) {
    _newPos = pos;
    _needRefresh = true;
}

void Bomb::setPosition(Position newPos){
    _pos = newPos;
}
