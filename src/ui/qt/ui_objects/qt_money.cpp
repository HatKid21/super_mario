#include "qt_money.hpp"
#include "sprites.hpp"

using hatkid::QtMoney;

QtMoney::QtMoney(
    const biv::Coord& topLeft,
    int width,
    int height
)
    : biv::Rect(topLeft, width, height),
      biv::Money(topLeft, width, height),
      sprite(Sprites::get(":/sprites/money.png")) {}

const QPixmap& QtMoney::getSprite() const noexcept {
    return sprite;
}
