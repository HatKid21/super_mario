#pragma once

#include <QMap>
#include <QPixmap>
#include <QString>

namespace hatkid {
    class Sprites {
        private:
            QMap<QString, QPixmap> cache;

            Sprites() = default;

            Sprites(const Sprites&) = delete;
            Sprites& operator=(const Sprites&) = delete;
            static Sprites& instance();

        public:
            static const QPixmap& get(const QString& path);
            static void clear();
    };
}
