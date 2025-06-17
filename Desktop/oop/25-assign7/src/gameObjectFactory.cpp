#include "gameObjectFactory.h"
#include "iconFactory.h"
#include "environment.h"
#include <random>

std::random_device rd;
std::mt19937 engine(rd());
std::uniform_int_distribution<int> distX(0, GAME_WINDOW_WIDTH - 1);
std::uniform_int_distribution<int> distY(0, GAME_WINDOW_HEIGHT - 1);

Player* SimpleGameObjectFactory::playerObject() {
    return new Player(IconFactory::NxMColor(Size(1, 1), RED), Position(distX(engine), distY(engine)));
}

Bomb* SimpleGameObjectFactory::bombObject() {
    return new Bomb(IconFactory::NxMColor(Size(1, 1), BLUE), Position(distX(engine), distY(engine)));
}

Star* SimpleGameObjectFactory::starObject() {
    return new Star(IconFactory::NxMColor(Size(1, 1), YELLOW), Position(distX(engine), distY(engine)));
}

Medicine* SimpleGameObjectFactory::medicineObject() {
    return new Medicine(IconFactory::NxMColor(Size(1, 1), GREEN), Position(distX(engine), distY(engine)));
}
