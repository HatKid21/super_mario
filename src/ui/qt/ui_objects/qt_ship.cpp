#include "qt_ship.hpp"
#include "sprites.hpp"

using hatkid::QtShip;

QtShip::QtShip(
  const biv::Coord& topLeft,
  int width,
  int height
) : 
  biv::Rect(topLeft,width,height),
  biv::Ship(topLeft,width,height),
  sprite(Sprites::get(":/sprites/ground.png")){}

const QPixmap& QtShip::getSprite() const noexcept{
  return sprite;
}

QSizeF QtShip::getTileSize() const noexcept {
    return QSizeF(3, 1);
}
