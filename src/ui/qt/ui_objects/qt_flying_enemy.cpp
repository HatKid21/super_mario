#include "qt_flying_enemy.hpp"
#include "sprites.hpp"

using hatkid::QtFlyingEnemy;

QtFlyingEnemy::QtFlyingEnemy(
    const biv::Coord& topLeft,
    int width,
    int height,
    float horizontalSpeed
)
    : biv::Rect(topLeft, width, height),
      biv::FlyingEnemy(topLeft, width, height, horizontalSpeed),
      sprite(Sprites::get(":/sprites/flying_enemy.png")) {}

const QPixmap& QtFlyingEnemy::getSprite() const noexcept {
    return sprite;
}
