#include "qt_box.hpp"
#include "sprites.hpp"

using hatkid::QtBox;

QtBox::QtBox(
    const biv::Coord& topLeft,
    int width,
    int height
)
    : biv::Rect(topLeft, width, height),
      biv::Box(topLeft, width, height),
      sprite(Sprites::get(":/sprites/brick.png")) {}

const QPixmap& QtBox::getSprite() const noexcept {
    return sprite;
}
