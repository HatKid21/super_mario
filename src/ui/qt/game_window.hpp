#pragma once

#include <QWidget>

#include "qt_keyboard.hpp"


namespace hatkid {
    class QtGameMap;
    class GameWindow : public QWidget {
      Q_OBJECT
        private:
          QtGameMap* gameMap = nullptr;
          QtKeyboard* keyboard;
        public:
            explicit GameWindow(QWidget* parent = nullptr);
            biv::KeyBoard* getKeyboard() const;
            void setGameMap(QtGameMap* map);
        protected:
            void paintEvent(QPaintEvent* event) override;

            void keyPressEvent(QKeyEvent* event) override;
            void keyReleaseEvent(QKeyEvent* event) override;
            void focusOutEvent(QFocusEvent* event) override;
        signals:
          void keyPressed(int key);
          void keyReleased(int key);
          void inputResetRequested();
    };
}
