#pragma once

#include "app_factory.hpp"

namespace hatkid{
    class LinuxAppFactory : public AppFactory{
        public:
            LinuxAppFactory(int& argc, char** argv);

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
