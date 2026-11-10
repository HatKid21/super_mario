#pragma once

#include <QPixmap>
#include <QRectF>

namespace hatkid {
    class QtUIObject {
        public:
            virtual ~QtUIObject() = default;

            virtual QRectF getBounds() const noexcept = 0;
            virtual const QPixmap& getSprite() const noexcept = 0;
    };
}
