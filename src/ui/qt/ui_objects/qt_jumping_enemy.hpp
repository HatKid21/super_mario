#pragma once

#include <QPixmap>

#include "jumping_enemy.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace hatkid {
    class QtJumpingEnemy
        : public biv::JumpingEnemy,
          public QtUIObjectRectAdapter {
        private:
            QPixmap sprite;

        public:
            QtJumpingEnemy(
                const biv::Coord& topLeft,
                int width,
                int height,
                float horizontalSpeed = 0.2f
            );

            const QPixmap& getSprite() const noexcept override;
    };
}
