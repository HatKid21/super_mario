#pragma once

#include <QApplication>

#include "app_factory.hpp"
#include "game_window.hpp"

namespace hatkid{
    class QtAppFactory : public AppFactory{
        private:
            QApplication app;
            GameWindow window;
        public:
            QtAppFactory(int& argc, char** argv);

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
