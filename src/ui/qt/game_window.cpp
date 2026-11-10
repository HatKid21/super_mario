#include "game_window.hpp"

#include <QColor>
#include <QPainter>
#include <QRect>


using hatkid::GameWindow;

GameWindow::GameWindow(QWidget* parent) : QWidget(parent){
  setWindowTitle("Super Mario");
  resize(1000,600);
}

void GameWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    mario_sprite.load(":/sprites/mario.png");

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
