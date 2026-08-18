#pragma once

#include "base_enemy.hpp"

namespace biv {
	class JumpingEnemy: public BaseEnemy{
		private:
			const float JUMP_STRENGTH = 1;
		public:
			JumpingEnemy(const Coord& top_left, const int width, const int height);

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;

			//void jump() noexcept;
	};
}
