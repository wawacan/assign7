#include "medicine.h"
#include "iconFactory.h"

Medicine::Medicine(Icon icon, Position pos)
    : TimeObject(icon, pos), _frameCount(0) {
        _flashColors = {GREEN, CYAN};
    }
void Medicine::update() {
    _frameCount++;
    const int cycle = 10;
    if (_frameCount % cycle == 0) {
        Color c = _flashColors[(_frameCount / cycle) % _flashColors.size()];
        _icon = IconFactory::NxMColor(Size(1, 1), c);
    }
}
bool Medicine::isExpired() const {
    return TimeObject::isExpired(15.0);
}
