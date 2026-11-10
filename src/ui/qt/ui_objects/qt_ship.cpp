#include "qt_ship.hpp"

using hatkid::QtShip;

QtShip::QtShip(
  const biv::Coord& topLeft,
  int width,
  int height
) : 
  biv::Rect(topLeft,width,height),
  biv::Ship(topLeft,width,height),
  sprite(":/sprites/ground.png"){}

const QPixmap& QtShip::getSprite() const noexcept{
  return sprite;
}
