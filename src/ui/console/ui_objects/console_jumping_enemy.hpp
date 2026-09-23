#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "jumping_enemy.hpp"

namespace biv{
	class ConsoleJumpingEnemy : public JumpingEnemy, public ConsoleUIObjectRectAdapter {
		public:
			ConsoleJumpingEnemy(
				const Coord& top_left, const int width, const int height,
				const float horizontal_speed = 0.0f
			);

			char get_brush() const noexcept override;
	};
}
