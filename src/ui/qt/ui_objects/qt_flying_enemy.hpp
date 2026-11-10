#pragma once

#include <QPixmap>

#include "flying_enemy.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace hatkid {
    class QtFlyingEnemy
        : public biv::FlyingEnemy,
          public QtUIObjectRectAdapter {
        private:
            QPixmap sprite;

        public:
            QtFlyingEnemy(
                const biv::Coord& topLeft,
                int width,
                int height,
                float horizontalSpeed = 0.2f
            );

            const QPixmap& getSprite() const noexcept override;
    };
}
