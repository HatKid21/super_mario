#pragma once

#include "ship.hpp"
#include "movable.hpp"
#include "collisionable.hpp"
#include "game.hpp"

namespace biv{
	class FloatingPlatform : public Ship, public Movable, public Collisionable{
		private:
			Mario* mario;
			const int FLOATING_RANGE = 10;
			int start_x;
		public:
			FloatingPlatform(const Coord& top_left, const int width, const int height,Mario* mario);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			void move_horizontally() noexcept override;
			void move_vertically() noexcept override;

			void move_map_left() noexcept override;
			void move_map_right() noexcept override;

			void process_horizontal_static_collision(Rect* obj) noexcept;
			void process_mario_collision(Collisionable* mario) noexcept;
			void process_vertical_static_collision(Rect* obj) noexcept;
			
	};
}
