#pragma once

#include <QPixmap>

#include "money.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace hatkid {
    class QtMoney
        : public biv::Money,
          public QtUIObjectRectAdapter {
        private:
            QPixmap sprite;

        public:
            QtMoney(
                const biv::Coord& topLeft,
                int width,
                int height
            );

            const QPixmap& getSprite() const noexcept override;
    };
}
