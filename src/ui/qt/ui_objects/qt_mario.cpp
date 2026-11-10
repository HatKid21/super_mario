#include "qt_mario.hpp"
#include "sprites.hpp"

using hatkid::QtMario;

QtMario::QtMario(
    const biv::Coord& topLeft,
    int width,
    int height
)
    : biv::Rect(topLeft, width, height),
      biv::Mario(topLeft, width, height),
      sprite(Sprites::get(":/sprites/mario.png")) {}

const QPixmap& QtMario::getSprite() const noexcept {
    return sprite;
}
