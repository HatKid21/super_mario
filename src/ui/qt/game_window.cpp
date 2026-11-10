#include "game_window.hpp"
#include "qt_game_map.hpp"

#include <QColor>
#include <QPainter>
#include <QRect>
#include <QFocusEvent>
#include <QKeyEvent>


using hatkid::GameWindow;

GameWindow::GameWindow(QWidget* parent) : QWidget(parent), keyboard(new QtKeyboard(this)){
  setWindowTitle("Super Mario");
  resize(1000,600);
  setFocusPolicy(Qt::StrongFocus);

  connect(
    this, &GameWindow::keyPressed,
    keyboard, &QtKeyboard::pressKey
  );

  connect(
      this, &GameWindow::keyReleased,
      keyboard, &QtKeyboard::releaseKey
  );

  connect(
      this, &GameWindow::inputResetRequested,
      keyboard, &QtKeyboard::reset
  );

}

biv::KeyBoard* GameWindow::getKeyboard() const {
    return keyboard;
}

void GameWindow::keyPressEvent(QKeyEvent* event) {
    if (event->isAutoRepeat()) {
        return;
    }

    emit keyPressed(event->key());
}

void GameWindow::keyReleaseEvent(QKeyEvent* event) {
    if (event->isAutoRepeat()) {
        return;
    }

    emit keyReleased(event->key());
}

void GameWindow::focusOutEvent(QFocusEvent* event) {
    emit inputResetRequested();

    QWidget::focusOutEvent(event);
}

void GameWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    if (gameMap != nullptr) {
        gameMap->draw(painter, rect());
    } else {
        painter.fillRect(
            rect(),
            QColor(135, 206, 235)
        );
    }
}

void GameWindow::setGameMap(QtGameMap* map) {
    gameMap = map;
    update();
}
