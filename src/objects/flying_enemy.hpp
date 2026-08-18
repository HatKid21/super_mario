#pragma once

#include "base_enemy.hpp"

namespace biv{
	class FlyingEnemy : public BaseEnemy{
		private:
			const float start_x;
		public:
			FlyingEnemy(const Coord& top_left, const int width, const int height);

			void move_vertically() noexcept override;
			void move_horizontally() noexcept override;
			
			void process_horizontal_static_collision(Rect* obj) noexcept override;
        		void process_vertical_static_collision(Rect* obj) noexcept override;
	};
}
