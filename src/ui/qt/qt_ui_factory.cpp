#include "qt_ui_factory.hpp"

#include <utility>

#include "game_window.hpp"
#include "qt_box.hpp"
#include "qt_ship.hpp"
#include "qt_enemy.hpp"
#include "qt_money.hpp"
#include "qt_full_box.hpp"
#include "qt_flying_enemy.hpp"
#include "qt_jumping_enemy.hpp"
#include "qt_floating_platform.hpp"

using hatkid::QtUIFactory;

QtUIFactory::QtUIFactory(
    biv::Game* game,
    GameWindow* window
)
    : biv::UIFactory(game),
      window(window) {}

QtUIFactory::~QtUIFactory() {
    window->setGameMap(nullptr);
    clear_data();
}

biv::GameMap* QtUIFactory::get_game_map(
    int height,
    int width
) {
    if (!gameMap) {
        gameMap = std::make_unique<QtGameMap>(
            height,
            width,
            window
        );

        window->setGameMap(gameMap.get());
    }

    return gameMap.get();
}

biv::Mario* QtUIFactory::get_mario() {
    return mario.get();
}

void QtUIFactory::clear_data() {
    game->remove_objs();

    if (gameMap) {
        gameMap->remove_objs();
    }

    objects.clear();
    mario.reset();
}

void QtUIFactory::create_box(
    const biv::Coord& topLeft,
    int width,
    int height
) {
    auto box = std::make_unique<QtBox>(
        topLeft,
        width,
        height
    );

    game->add_map_movable(box.get());
    game->add_static_obj(box.get());

    gameMap->addObject(box.get());

    objects.push_back(std::move(box));
}

void QtUIFactory::create_ship(
    const biv::Coord& topLeft,
    int width,
    int height
){

  auto ship = std::make_unique<QtShip>(
    topLeft,
    width,
    height
  );

  game->add_map_movable(ship.get());
  game->add_static_obj(ship.get());

  gameMap->addObject(ship.get());

  objects.push_back(std::move(ship));

}

void QtUIFactory::create_mario(
    const biv::Coord& topLeft,
    int width,
    int height
) {
    if (mario) {
        game->remove_collisionable(mario.get());
        game->remove_movable(mario.get());
        game->remove_move_collisionable(mario.get());
        game->remove_mario();

        gameMap->removeObject(mario.get());

        mario.reset();
    }

    mario = std::make_unique<QtMario>(
        topLeft,
        width,
        height
    );

    game->add_collisionable(mario.get());
    game->add_movable(mario.get());
    game->add_move_collisionable(mario.get());
    game->add_mario(mario.get());

    gameMap->addObject(mario.get());
}

void QtUIFactory::create_enemy(
    const biv::Coord& topLeft,
    int width,
    int height,
    float horizontalSpeed
) {
    auto enemy = std::make_unique<QtEnemy>(
        topLeft,
        width,
        height,
        horizontalSpeed
    );

    game->add_map_movable(enemy.get());
    game->add_movable(enemy.get());
    game->add_collisionable(enemy.get());
    game->add_move_collisionable(enemy.get());

    gameMap->addObject(enemy.get());

    objects.push_back(std::move(enemy));
}

void QtUIFactory::create_money(
    const biv::Coord& topLeft,
    int width,
    int height
) {
  auto money = std::make_unique<QtMoney>(
        topLeft,
        width,
        height
  );
  game->add_map_movable(money.get());
  game->add_movable(money.get());
  game->add_collisionable(money.get());

  gameMap->addObject(money.get());

  objects.push_back(std::move(money));

}

void QtUIFactory::create_full_box(
    const biv::Coord& topLeft,
    int width,
    int height
) {
    auto fullBox = std::make_unique<QtFullBox>(
        topLeft,
        width,
        height,
        this
    );

    game->add_collisionable(fullBox.get());
    game->add_map_movable(fullBox.get());
    game->add_static_obj(fullBox.get());

    gameMap->addObject(fullBox.get());

    objects.push_back(std::move(fullBox));
}

void QtUIFactory::create_flying_enemy(
    const biv::Coord& topLeft,
    int width,
    int height,
    float horizontalSpeed
) {
    auto enemy = std::make_unique<QtFlyingEnemy>(
        topLeft,
        width,
        height,
        horizontalSpeed
    );

    game->add_map_movable(enemy.get());
    game->add_movable(enemy.get());
    game->add_collisionable(enemy.get());
    game->add_move_collisionable(enemy.get());

    gameMap->addObject(enemy.get());

    objects.push_back(std::move(enemy));
}

void QtUIFactory::create_jumping_enemy(
    const biv::Coord& topLeft,
    int width,
    int height,
    float horizontalSpeed
){
  auto jumpingEnemy = std::make_unique<QtJumpingEnemy>(
        topLeft,
        width,
        height,
        horizontalSpeed
    );

    game->add_map_movable(jumpingEnemy.get());
    game->add_movable(jumpingEnemy.get());
    game->add_collisionable(jumpingEnemy.get());
    game->add_move_collisionable(jumpingEnemy.get());

    gameMap->addObject(jumpingEnemy.get());

    objects.push_back(std::move(jumpingEnemy));
}

void QtUIFactory::create_floating_platform(
    const biv::Coord& topLeft,
    int width,
    int height,
    int floatingRange,
    float horizontalSpeed
) {
    auto platform = std::make_unique<QtFloatingPlatform>(
        topLeft,
        width,
        height,
        mario.get(),
        floatingRange,
        horizontalSpeed
    );

    game->add_map_movable(platform.get());
    game->add_movable(platform.get());
    game->add_static_obj(platform.get());
    game->add_collisionable(platform.get());
    game->add_floating_platform(platform.get());

    gameMap->addObject(platform.get());

    objects.push_back(std::move(platform));
}
