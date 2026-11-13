#pragma once

#include <chrono>

#include "keyboard.hpp"
#include "ui_factory.hpp"
#include "os_control_settings.hpp"

namespace hatkid{
    class AppFactory{
        public:
            virtual ~AppFactory() = default;

            virtual biv::KeyBoard* getKeyboard() = 0;
            virtual biv::UIFactory* getFactory(biv::Game* game) = 0;
            virtual std::chrono::milliseconds getFrameDelay() const = 0;
            virtual biv::OSControlSettings* getControlSettings(
                    int mapHeight,
                    int mapWidth
                    ) = 0;

            virtual void show() = 0;

            virtual bool loopInit() = 0;

            virtual void destroyKeyboard(biv::KeyBoard* keyboard) = 0;
            
            virtual void clear() = 0;

    };
}
