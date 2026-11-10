#include "game_window.hpp"

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
  mario_sprite.load(":/sprites/mario.png");

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

    painter.fillRect(
        rect(),
        QColor(135, 206, 235)
    );

    painter.fillRect(
    0,
    height() - 80,
    width(),
    80,
    QColor(139, 90, 43)
    );
    const QRect mario_rect(
      100,
      height() - 80 - 48,
      32,
      48
    );

    if (mario_sprite.isNull()) {
      painter.fillRect(
          mario_rect,
          QColor(220, 50, 50)
      );
    } else {
        painter.drawPixmap(
            mario_rect,
            mario_sprite
        );
    };
}
