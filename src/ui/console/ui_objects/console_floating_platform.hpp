#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "floating_platform.hpp"
#include "mario.hpp"

namespace biv{
	class ConsoleFloatingPlatform : public FloatingPlatform, public ConsoleUIObjectRectAdapter{
		public:
			ConsoleFloatingPlatform(
				const Coord& top_left, const int width, const int height, Mario* mario,
				const int floating_range = 10,
				const float horizontal_speed = 0.3f
			);

			char get_brush() const noexcept override;
	};
}
