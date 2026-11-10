#include "qt_full_box.hpp"
#include "sprites.hpp"

using hatkid::QtFullBox;

QtFullBox::QtFullBox(
    const biv::Coord& topLeft,
    int width,
    int height,
    biv::UIFactory* uiFactory
)
    : biv::Rect(topLeft, width, height),
      biv::FullBox(topLeft, width, height, uiFactory),
      activeSprite(Sprites::get(":/sprites/question_block.png")),
      usedSprite(Sprites::get(":/sprites/used_block.png")) {}

const QPixmap& QtFullBox::getSprite() const noexcept {
    return is_active() ? activeSprite : usedSprite;
}
