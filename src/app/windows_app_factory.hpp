#pragma once

#include "app_factory.hpp"
#include "ui_factory.hpp"
#include "keyboard.hpp"
#include "os_control_settings.hpp"

namespace hatkid{
    class WindowsAppFactory : public AppFactory{
        public:
            WindowsAppFactory(int& argc, char** argv);

            biv::UIFactory* getFactory(biv::Game* game) override;
            biv::KeyBoard* getKeyboard() override;
            std::chrono::milliseconds getFrameDelay() const override;
            biv::OSControlSettings* getControlSettings(
                    int mapHeight,
                    int mapWidth
                    ) override;

            void show() override;

            bool loopInit() override;

            void destroyKeyboard(biv::KeyBoard* keyboard) override;
            
            void clear() override;

    };
}
