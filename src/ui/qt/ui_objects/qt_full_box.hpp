#pragma once

#include <QPixmap>

#include "full_box.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace hatkid {
    class QtFullBox
        : public biv::FullBox,
          public QtUIObjectRectAdapter {
        private:
            QPixmap activeSprite;
            QPixmap usedSprite;

        public:
            QtFullBox(
                const biv::Coord& topLeft,
                int width,
                int height,
                biv::UIFactory* uiFactory
            );

            const QPixmap& getSprite() const noexcept override;
    };
}
