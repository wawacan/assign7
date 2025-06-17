#include "gameManager.h"
#include "gameObjectFactory.h"
#include <algorithm>
#include <random>
#include <thread>     
#include <chrono>

extern std::mt19937 engine;
extern std::uniform_int_distribution<int> distX, distY;

GameManager::GameManager()
    : _player(SimpleGameObjectFactory::playerObject()),
    _star(SimpleGameObjectFactory::starObject()),
    _medicine(nullptr), _score(0) {
        for (int i = 0; i < 3; i++) {
            _bombs.push_back(SimpleGameObjectFactory::bombObject());
        }
    }

GameManager::~GameManager() {
    delete _player;
    delete _star;
    if (_medicine) delete _medicine;
    for (auto b : _bombs){
        delete b;
    }
}

void GameManager::handleInput(Direction dir) {
    _player->setDirection(dir);
}

void GameManager::update() {
    bool mes = true;    
    if(mes){
        // std::cout << "Collect 5 stars to win the game!" << std::flush;

        // 等待一點時間再清除
        // std::this_thread::sleep_for(std::chrono::seconds(3));

        // 清除這行訊息
        // std::cout << "\r\033[K" << std::flush;
        mes = false;
    }

    _player->update();
    _star->update();
    for (auto& b : _bombs){
        b->update();
    }
    if (_medicine) {
        _medicine->update();
        if (_medicine->isExpired()){
            removeMedicine();
        }
    }
    refreshBombs();
    handleCollisions();
}

void GameManager::handleCollisions() {
    for (auto& b : _bombs) {
        if (_player->getPosition() == b->getPosition()) {
            if (_player->isInGhostForm()) {
                // std::cout << "Your soul have been killed. YOU LOSE." << std::endl << std::flush;

                // std::this_thread::sleep_for(std::chrono::seconds(3));

                // 清除這行訊息
                // std::cout << "\r\033[K" << std::flush;
                _player->kill();
            } else {
                // std::cout << "💥💥💥💥💥💥" << std::endl << "You've been killed by a bomb 😫\nfind the medicine in 10 seconds to recover and watch out the bomb\nthey'll kill your soul directedly!!" << std::endl << std::flush;

                // std::this_thread::sleep_for(std::chrono::seconds(3));

                // 清除這行訊息
                // std::cout << "\r\033[K" << std::flush;
                _player->becomeGhost();
                if (!_medicine){
                    spawnMedicine();
                }
            }
            break;
        }
    }

    if (_medicine && _player->isInGhostForm() && _player->getPosition() == _medicine->getPosition()) {
        // std::cout << "Got medicine💊!! NOW recover!!!" << std::endl << std::flush;

        // std::this_thread::sleep_for(std::chrono::seconds(3));

        // 清除這行訊息
        // std::cout << "\r\033[K" << std::flush;
        _player->recover();
        removeMedicine();
    }

    if (_player->getPosition() == _star->getPosition()) {
        ++_score;
        // std::cout << "You've got " << _score << " stars!" << std::endl << std::flush;

        // std::this_thread::sleep_for(std::chrono::seconds(3));

        // 清除這行訊息
        // std::cout << "\r\033[K" << std::flush;
        if (_score < STAR_TARGET) {
            _star->refreshStar(randomEmptyPosition());
        } else {
            // std::cout << "✨You've collected all stars✨" << std::endl << std::flush;

            // std::this_thread::sleep_for(std::chrono::seconds(3));

            // 清除這行訊息
            // std::cout << "\r\033[K" << std::flush;
            delete _star;
            _star = nullptr;
        }
    }
}

void GameManager::refreshBombs() {
    for (auto& b : _bombs) {
        if (b->isExpired()) {
            // 換位置
            Position newPos = randomEmptyPosition();
            b->refresh(newPos);
        }
    }
}

void GameManager::spawnMedicine() {
    _medicine = SimpleGameObjectFactory::medicineObject();
}

void GameManager::removeMedicine() {
    delete _medicine;
    _medicine = nullptr;
}

Position GameManager::randomEmptyPosition() const {
    Position pos;
    pos = Position(distX(engine), distY(engine));
    while(true){
        bool flag = false;
        for(const auto &b : _bombs){
            if(pos == b->getPosition()){
                flag = true;
                break;
            }
        }
        if(pos == _player->getPosition() || (_medicine && pos == _medicine->getPosition()) || flag){
            pos = Position(distX(engine), distY(engine));
        }else{
            break;
        }
    }
    return pos;
}

void GameManager::updateView(View& view) {
    view.updateGameObject(_player);
    if (_star) view.updateGameObject(_star);
    for (auto b : _bombs) view.updateGameObject(b);
    if (_medicine) view.updateGameObject(_medicine);
}

bool GameManager::isGameOver() const {
    return _player->isDead();
}

bool GameManager::isWin() const {
    return _score >= STAR_TARGET;
}
