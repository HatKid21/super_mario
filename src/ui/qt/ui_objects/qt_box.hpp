#pragma once

#include <QPixmap>

#include "box.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace hatkid{
  class QtBox : public biv::Box, public QtUIObjectRectAdapter{
    private:
      QPixmap sprite;

    public:
      QtBox(
          const biv::Coord& topLeft,
          int width,
          int height
      );

      const QPixmap& getSprite() const noexcept override;
      QSizeF getTileSize() const noexcept override;
  };
}
