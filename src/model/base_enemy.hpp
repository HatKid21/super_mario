#pragma once

#include "rect_map_movable_adapter.hpp"
#include "move_collisionable.hpp"
#include "speed.hpp"

namespace biv {
    class BaseEnemy : public RectMapMovableAdapter, public MoveCollisionable {
    public:
        BaseEnemy(const Coord& top_left, const int width, const int height);
        virtual ~BaseEnemy() = default;

        Rect get_rect() const noexcept override;
        Speed get_speed() const noexcept override;
        void process_mario_collision(Collisionable* mario) noexcept override;

        void process_horizontal_static_collision(Rect*) noexcept override = 0;
        void process_vertical_static_collision(Rect*) noexcept override = 0;
    };
}
