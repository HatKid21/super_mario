#include "qt_keyboard.hpp"

#include <Qt>

using hatkid::QtKeyboard;

QtKeyboard::QtKeyboard(QObject* parent)
    : QObject(parent) {}

void QtKeyboard::on() {
    reset();
    enabled = true;
}

void QtKeyboard::off() {
    enabled = false;
    reset();
}

void QtKeyboard::reset() {
    pressedKeys.clear();

    jumpRequested = false;
    exitRequested = false;
}

void QtKeyboard::pressKey(int key) {
    if (!enabled) {
        return;
    }

    if (pressedKeys.contains(key)) {
        return;
    }

    pressedKeys.insert(key);

    if (key == Qt::Key_Space) {
        jumpRequested = true;
    }

    if (key == Qt::Key_Q || key == Qt::Key_Escape) {
        exitRequested = true;
    }
}

void QtKeyboard::releaseKey(int key) {
    pressedKeys.remove(key);
}

biv::UserInput QtKeyboard::get_user_input() {
    using biv::UserInput;

    if (!enabled) {
        return UserInput::NO_INPUT;
    }

    if (exitRequested) {
        exitRequested = false;
        return UserInput::EXIT;
    }

    if (jumpRequested) {
        jumpRequested = false;
        return UserInput::MARIO_JUMP;
    }

    const bool left_pressed =
        pressedKeys.contains(Qt::Key_A)
        || pressedKeys.contains(Qt::Key_Left);

    const bool right_pressed =
        pressedKeys.contains(Qt::Key_D)
        || pressedKeys.contains(Qt::Key_Right);

    if (left_pressed && !right_pressed) {
        return UserInput::MAP_RIGHT;
    }

    if (right_pressed && !left_pressed) {
        return UserInput::MAP_LEFT;
    }

    return UserInput::NO_INPUT;
}
