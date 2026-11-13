#include "qt_app_factory.hpp"

#include "qt_ui_factory.hpp"
#include "sprites.hpp"

using hatkid::QtAppFactory;

QtAppFactory::QtAppFactory(int& argc, char** argv)
    : app(argc,argv), 
    window(){
}

biv::KeyBoard* QtAppFactory::getKeyboard(){
    return window.getKeyboard();
}

biv::UIFactory* QtAppFactory::getFactory(biv::Game* game){
    return new QtUIFactory(game, &window);
}

biv::OSControlSettings* QtAppFactory::getControlSettings(int,int){
    return nullptr;
}

std::chrono::milliseconds QtAppFactory::getFrameDelay() const{
    return std::chrono::milliseconds(33);
}

void QtAppFactory::show(){
    window.show();
}

bool QtAppFactory::loopInit(){
    QApplication::processEvents();

    return window.isVisible();
}

void QtAppFactory::destroyKeyboard(biv::KeyBoard*){
}

void QtAppFactory::clear(){
    Sprites::clear();
}
