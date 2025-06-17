#ifndef TIME_OBJECT_H
#define TIME_OBJECT_H
#include "gameObject.h"
#include <ctime>

using namespace std;

// 有倒數計時的object
class TimeObject : public GameObject {
public:
    TimeObject(Icon icon, Position pos);
    // 重設倒數計時
    void resetTimer();
    // 檢查是否已經超過倒數時間
    bool isExpired(double limit) const;
protected:
    // 用來計時
    time_t _timer;
};

#endif
