#pragma once

#include "qt_ui_object.hpp"
#include "rect.hpp"

namespace hatkid {
    class QtUIObjectRectAdapter
        : virtual public biv::Rect,
          public QtUIObject {
        public:
            QRectF getBounds() const noexcept override;
    };
}
