#include "qt_floating_platform.hpp"

using hatkid::QtFloatingPlatform;

QtFloatingPlatform::QtFloatingPlatform(
    const biv::Coord& topLeft,
    int width,
    int height,
    biv::Mario* mario,
    int floatingRange,
    float horizontalSpeed
)
    : biv::Rect(topLeft, width, height),
      biv::FloatingPlatform(
          topLeft,
          width,
          height,
          mario,
          floatingRange,
          horizontalSpeed
      ),
      sprite(":/sprites/flying_platform.png") {}

const QPixmap& QtFloatingPlatform::getSprite() const noexcept {
    return sprite;
}
