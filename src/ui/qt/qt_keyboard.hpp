#pragma once

#include <QObject>
#include <QSet>

#include "keyboard.hpp"

namespace hatkid {
  class QtKeyboard : public QObject, public biv::KeyBoard{
    Q_OBJECT
  
    private:
      QSet<int> pressedKeys;
      bool enabled = false;
      bool jumpRequested = false;
      bool exitRequested = false;

    public:
      explicit QtKeyboard(QObject* parent = nullptr);

      biv::UserInput get_user_input() override;

      void on() override;
      void off() override;

    public slots:
      void pressKey(int key);
      void releaseKey(int key);
      void reset();
  };
}
