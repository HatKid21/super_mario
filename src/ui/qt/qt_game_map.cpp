#include "qt_game_map.hpp"

#include <algorithm>

#include <QColor>
#include <QPainter>

#include "game_window.hpp"

using hatkid::QtGameMap;

QtGameMap::QtGameMap(
    int height,
    int width,
    GameWindow* window
  ) : biv::GameMap(height,width), window(window){

}

void QtGameMap::addObject(QtUIObject* object){
  objects.push_back(object);
}

void QtGameMap::removeObject(QtUIObject* object){
  objects.erase(
    std::remove(objects.begin(), objects.end(),object),
    objects.end()
  );
}

void QtGameMap::remove_objs(){
  objects.clear();
}

void QtGameMap::clear() noexcept {
}

void QtGameMap::refresh() noexcept {
}

void QtGameMap::show() const noexcept {
    window->update();
}

void QtGameMap::draw(
    QPainter& painter,
    const QRect& viewport
) const {
    painter.save();

    painter.setClipRect(viewport);

    painter.translate(viewport.x(), viewport.y());

    painter.scale(
        static_cast<qreal>(viewport.width()) / width,
        static_cast<qreal>(viewport.height()) / height
    );

    painter.fillRect(
        QRectF(0, 0, width, height),
        QColor(135, 206, 235)
    );

    painter.fillRect(
        QRectF(0, height - 3, width, 3),
        QColor(40, 110, 220)
    );

    for (const QtUIObject* object : objects) {
        const QRectF bounds = object->getBounds();
        const QPixmap& sprite = object->getSprite();

        if (sprite.isNull()) {
            painter.fillRect(
                bounds,
                QColor(220, 50, 50)
            );
        } else {
            painter.drawPixmap(
                bounds,
                sprite,
                QRectF(sprite.rect())
            );
        }
    }

    painter.restore();
}

