#pragma once

#include <QPixmap>

#include "mario.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace hatkid {
    class QtMario
        : public biv::Mario,
          public QtUIObjectRectAdapter {
        private:
            QPixmap sprite;

        public:
            QtMario(
                const biv::Coord& topLeft,
                int width,
                int height
            );

            const QPixmap& getSprite() const noexcept override;
    };
}
