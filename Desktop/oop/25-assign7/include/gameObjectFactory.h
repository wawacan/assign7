#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include "player.h"
#include "bomb.h"
#include "star.h"
#include "medicine.h"

struct SimpleGameObjectFactory {
    static Player* playerObject();
    static Bomb* bombObject();
    static Star* starObject();
    static Medicine* medicineObject();
};

#endif
