#ifndef ELEMENT_H
#define ELEMENT_H

#include "icon.h"
#include "unit.h"
#include <iostream>
#include <vector>
class GameObject {

public:
  GameObject(Icon icon, Position pos = {0, 0});
  virtual ~GameObject();
  virtual void update();
  Icon getIcon() const;
  Position getPosition() const;

protected:
  Position _pos;
  Icon _icon;
};

inline Icon GameObject::getIcon() const { return _icon; }

inline Position GameObject::getPosition() const { return _pos; }
#endif
