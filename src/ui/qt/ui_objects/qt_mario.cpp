#include "qt_mario.hpp"

using hatkid::QtMario;

QtMario::QtMario(
    const biv::Coord& topLeft,
    int width,
    int height
)
    : biv::Rect(topLeft, width, height),
      biv::Mario(topLeft, width, height),
      sprite(":/sprites/mario.png") {}

const QPixmap& QtMario::getSprite() const noexcept {
    return sprite;
}
