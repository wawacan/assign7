#include "iconFactory.h"

// 根據傳入字串製作Icon
Icon IconFactory::NxMColor(Size size, Color color, const std::string& typeString) {

  Icon icon;
  for (int h = 0; h < size.height(); ++h) {

    std::vector<Cell> row;

    for (int w = 0; w < size.width(); ++w) {
      row.emplace_back(Cell(color, typeString));
    }

    icon.emplace_back(row);
  }

  return icon;
}