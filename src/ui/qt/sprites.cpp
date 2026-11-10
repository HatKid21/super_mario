#include "sprites.hpp"

#include <QDebug>

using hatkid::Sprites;

const QPixmap& Sprites::get(const QString& path) {
    Sprites& storage = instance();

    auto it = storage.cache.constFind(path);

    if (it == storage.cache.cend()) {
        QPixmap sprite;

        if (!sprite.load(path)) {
            qWarning() << "Cannot load sprite:" << path;
        }

        storage.cache.insert(path, sprite);

        it = storage.cache.constFind(path);
    }

    return it.value();
}

Sprites& Sprites::instance() {
    static Sprites storage;
    return storage;
}

void Sprites::clear() {
    instance().cache.clear();
}
