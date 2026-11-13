#include "linux_app_factory.hpp"

#include <ncurses.h>

#include "console_ui_factory.hpp"
#include "linux_control_settings.hpp"
#include "linux_keyboard.hpp"

using hatkid::LinuxAppFactory;

LinuxAppFactory::LinuxAppFactory(int&, char**) {
}

biv::KeyBoard* LinuxAppFactory::getKeyboard(){
    return new biv::LinuxKeyboard();
}

biv::UIFactory* LinuxAppFactory::getFactory(biv::Game* game){
    return new biv::ConsoleUIFactory(game);
}

biv::OSControlSettings* LinuxAppFactory::getControlSettings(
        int mapHeight,
        int mapWidth
        ){
    return new biv::LinuxControlSettings(mapHeight, mapWidth);
}

std::chrono::milliseconds LinuxAppFactory::getFrameDelay() const{
    return std::chrono::milliseconds(33);
}

void LinuxAppFactory::show() {

}

bool LinuxAppFactory::loopInit(){
    return true;
}

void LinuxAppFactory::destroyKeyboard(biv::KeyBoard* keyboard){
    delete keyboard;
}

void LinuxAppFactory::clear(){
    endwin();
}

