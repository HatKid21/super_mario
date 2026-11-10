#include "qt_jumping_enemy.hpp"

using hatkid::QtJumpingEnemy;

QtJumpingEnemy::QtJumpingEnemy(
    const biv::Coord& topLeft,
    int width,
    int height,
    float horizontalSpeed
)
    : biv::Rect(topLeft, width, height),
      biv::JumpingEnemy(topLeft, width, height, horizontalSpeed),
      sprite(":/sprites/jumping_enemy.png") {}

const QPixmap& QtJumpingEnemy::getSprite() const noexcept {
    return sprite;
}
