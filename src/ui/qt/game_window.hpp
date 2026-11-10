#pragma once

#include <QWidget>
#include <QPixmap>


namespace hatkid {
    class GameWindow : public QWidget {
        private:
          QPixmap mario_sprite;
        public:
            explicit GameWindow(QWidget* parent = nullptr);
        protected:
            void paintEvent(QPaintEvent* event) override;
    };
}
