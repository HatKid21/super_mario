#pragma once

#include <QPixmap>

#include "ship.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace hatkid {
  class QtShip : public biv::Ship, public QtUIObjectRectAdapter{  
    private:
      QPixmap sprite;
    public:
      QtShip(
        const biv::Coord& topLeft,
        int width,
        int height
      );

      const QPixmap& getSprite() const noexcept override;
  };
}
