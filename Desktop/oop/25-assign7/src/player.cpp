#include "player.h"
#include "environment.h"

Player::Player(Icon icon, Position pos) : GameObject(icon, pos), _dir(NONE), _isGhost(false), _isAlive(true), _ghostTimer(0){}

void Player::update(){
    if (_dir == UP && _pos.y() != 0) {
        _pos.y()--;
    } else if (_dir == LEFT && _pos.x() != 0) {

        _pos.x()--;
    } else if (_dir == DOWN && _pos.y() < GAME_WINDOW_HEIGHT - 1) {

        _pos.y()++;
    } else if (_dir == RIGHT && _pos.x() < GAME_WINDOW_WIDTH - 1) {

        _pos.x()++;
    }
    _dir = NONE;
    // 移動之後如果是鬼魂更新鬼魂倒計時
    tick();
}

void Player::setDirection(Direction dir){ 
    _dir = dir;
}

void Player::tick(){
    if(_isGhost && _isAlive){
        _ghostTimer--;
        if(_ghostTimer <= 0){
            _isAlive = false;
        }
    }
}

void Player::becomeGhost(){
    _isGhost = true;
    // 10 秒內要吃到藥
    _ghostTimer = 10;
}

void Player::kill(){
    _isAlive = false;
}

void Player::recover(){
    _isGhost = false;
    _ghostTimer = 0;
}

bool Player::isDead() const{
    return !_isAlive;
}

bool Player::isInGhostForm() const{
    return _isGhost;
}
