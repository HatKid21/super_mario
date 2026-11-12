#pragma once

#include <QPixmap>
#include <QRectF>
#include <QSizeF>

namespace hatkid {
    class QtUIObject {
        public:
            virtual ~QtUIObject() = default;

            virtual QRectF getBounds() const noexcept = 0;
            virtual const QPixmap& getSprite() const noexcept = 0;

            virtual QSizeF getTileSize() const noexcept {
                return QSizeF(0, 0);
            }
    };
}
