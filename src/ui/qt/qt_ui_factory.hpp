#pragma once

#include <memory>
#include <vector>

#include "ui_factory.hpp"

#include "qt_game_map.hpp"
#include "qt_ui_object.hpp"
#include "qt_mario.hpp"

namespace hatkid {
    class GameWindow;

    class QtUIFactory : public biv::UIFactory {
        private:
            GameWindow* window;

            std::unique_ptr<QtGameMap> gameMap;
            std::unique_ptr<QtMario> mario;

            std::vector<std::unique_ptr<QtUIObject>> objects;

        public:
            QtUIFactory(biv::Game* game, GameWindow* window);
            ~QtUIFactory();

            void clear_data() override;

            biv::GameMap* get_game_map(
                int height,
                int width
            ) override;

            biv::Mario* get_mario() override;

            void create_box(
                const biv::Coord& topLeft,
                int width,
                int height
            ) override;

            void create_ship(
                const biv::Coord& topLeft,
                int width,
                int height
            ) override;

            void create_mario(
                const biv::Coord& topLeft,
                int width,
                int height
            ) override;

            void create_enemy(
                const biv::Coord& topLeft,
                int width,
                int height,
                float horizontalSpeed = 0.2f
            ) override;

            void create_money(
                const biv::Coord& topLeft,
                int width,
                int height
            ) override;

            void create_full_box(
                const biv::Coord& topLeft,
                int width,
                int height
            ) override;

            void create_flying_enemy(
                const biv::Coord& topLeft,
                int width,
                int height,
                float horizontalSpeed = 0.2f
            ) override;

            void create_jumping_enemy(
                const biv::Coord& topLeft,
                int width,
                int height,
                float horizontalSpeed = 0.0f
            ) override;

            void create_floating_platform(
                const biv::Coord& topLeft,
                int width,
                int height,
                int floatingRange = 10,
                float horizontalSpeed = 0.3f
            ) override;
    };
}
