#pragma once

#include "movable.hpp"
#include "collisionable.hpp"

namespace biv {
    class MoveCollisionable : public Movable, public Collisionable {
        public:
            MoveCollisionable() = default;

			MoveCollisionable(
				const Coord& top_left,
				const int width,
				const int height,
				const float vspeed,
				const float hspeed
			) : Movable(top_left, width, height, vspeed, hspeed) {}

            virtual void move_platform(MoveCollisionable* fp) noexcept;
    };
}
