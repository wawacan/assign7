#include "gameObject.h"
#include "environment.h"

GameObject::GameObject(Icon icon, Position pos) : _icon(icon), _pos(pos) {
}
GameObject::~GameObject() {}

void GameObject::update() {
}

