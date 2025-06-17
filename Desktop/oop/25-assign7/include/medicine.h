#ifndef MEDICINE_H
#define MEDICINE_H

#include "timeObject.h"
#include <ctime>
#include <vector>

class Medicine : public TimeObject {
public:
    Medicine(Icon icon, Position pos);
    void update() override;
    // 判斷倒計時是否結束
    bool isExpired() const;
private:
    int _frameCount;
    vector<Color> _flashColors;
};

#endif
