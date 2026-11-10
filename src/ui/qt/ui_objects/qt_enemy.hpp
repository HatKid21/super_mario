#pragma once

#include <QPixmap>

#include "enemy.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace hatkid {
    class QtEnemy
        : public biv::Enemy,
          public QtUIObjectRectAdapter {
        private:
            QPixmap sprite;

        public:
            QtEnemy(
                const biv::Coord& topLeft,
                int width,
                int height,
                float horizontalSpeed = 0.2f
            );

            const QPixmap& getSprite() const noexcept override;
    };
}
