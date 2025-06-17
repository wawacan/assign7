#include "timeObject.h"

TimeObject::TimeObject(Icon icon, Position pos)
    : GameObject(icon, pos) {
    _timer = time(nullptr);
}

void TimeObject::resetTimer() {
    _timer = time(nullptr);
}

bool TimeObject::isExpired(double limit) const {
    time_t now = time(nullptr);
    return difftime(now, _timer) >= limit;
}
