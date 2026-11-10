#pragma once

#include <vector>

#include <QRect>

#include "game_map.hpp"
#include "qt_ui_object.hpp"

class QPainter;

namespace hatkid {
    class GameWindow;

    class QtGameMap : public biv::GameMap {
        private:
            GameWindow* window;
            std::vector<QtUIObject*> objects;

        public:
            QtGameMap(
                int height,
                int width,
                GameWindow* window
            );

            void addObject(QtUIObject* object);
            void removeObject(QtUIObject* object);

            void clear() noexcept override;
            void refresh() noexcept override;
            void remove_objs() override;
            void show() const noexcept override;

            void draw(
                QPainter& painter,
                const QRect& viewport
            ) const;
    };
}
