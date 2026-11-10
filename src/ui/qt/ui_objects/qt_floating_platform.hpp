#pragma once

#include <QPixmap>

#include "floating_platform.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace hatkid {
    class QtFloatingPlatform
        : public biv::FloatingPlatform,
          public QtUIObjectRectAdapter {
        private:
            QPixmap sprite;

        public:
            QtFloatingPlatform(
                const biv::Coord& topLeft,
                int width,
                int height,
                biv::Mario* mario,
                int floatingRange = 10,
                float horizontalSpeed = 0.3f
            );

            const QPixmap& getSprite() const noexcept override;
    };
}
