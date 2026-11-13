#include "windows_app_factory.hpp"

#include "console_ui_factory.hpp"
#include "windows_control_settings.hpp"
#include "windows_keyboard.hpp"

using hatkid::WindowsAppFactory;

WindowsAppFactory::WindowsAppFactory(int&, char**) {
}

biv::KeyBoard* WindowsAppFactory::getKeyboard(){
    return new biv::WindowsKeyBoard();
}

biv::UIFactory* WindowsAppFactory::getFactory(biv::Game* game){
    return new biv::ConsoleUIFactory(game);
}

biv::OSControlSettings* WindowsAppFactory::getControlSettings(
        int,
        int
        ){
    return new biv::WindowsControlSettings();
}

std::chrono::milliseconds WindowsAppFactory::getFrameDelay() const{
    return std::chrono::milliseconds(10);
}

void WindowsAppFactory::show() {
}

bool WindowsAppFactory::loopInit() {
    return true;
}

void WindowsAppFactory::destroyKeyboard(biv::KeyBoard* keyboard){
    delete keyboard;
}

void WindowsAppFactory::clear(){
}


