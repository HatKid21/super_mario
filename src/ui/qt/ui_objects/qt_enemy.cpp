#include "qt_enemy.hpp"

using hatkid::QtEnemy;

QtEnemy::QtEnemy(
    const biv::Coord& topLeft,
    int width,
    int height,
    float horizontalSpeed
)
    : biv::Rect(topLeft, width, height),
      biv::Enemy(topLeft, width, height, horizontalSpeed),
      sprite(":/sprites/enemy.png") {}

const QPixmap& QtEnemy::getSprite() const noexcept {
    return sprite;
}
