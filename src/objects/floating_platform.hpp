#pragma once

#include "rect_map_movable_adapter.hpp"
#include "move_collisionable.hpp"
#include "mario.hpp"

namespace biv{
	class FloatingPlatform : public RectMapMovableAdapter, public MoveCollisionable{
		private:
			const int floating_range;
			int start_x;
			Mario* mario;
		public:
			FloatingPlatform(
				const Coord& top_left, const int width, const int height, Mario* mario,
				const int floating_range = 10,
				const float horizontal_speed = 0.3f
			);

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
