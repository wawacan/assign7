#include "icon.h"

class IconFactory {

public:
    // 新增可以設定Icon的文字 預設為空白
    static Icon NxMColor(Size size, Color color, const std::string& typeString = " ");
};