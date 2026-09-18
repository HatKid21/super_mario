#pragma once

#include "rect_map_movable_adapter.hpp"
#include "move_collisionable.hpp"

namespace biv{
	class FloatingPlatform : public RectMapMovableAdapter, public MoveCollisionable{
		private:
			const int FLOATING_RANGE = 10;
			int start_x;
		public:
			FloatingPlatform(const Coord& top_left, const int width, const int height);

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
