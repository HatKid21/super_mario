#include "console_floating_platform.hpp"

using biv::ConsoleFloatingPlatform;

ConsoleFloatingPlatform::ConsoleFloatingPlatform(
	const Coord& top_left, const int width, const int height, Mario* mario,
	const int floating_range, const float horizontal_speed
)
	: FloatingPlatform(top_left,width,height,mario,floating_range,horizontal_speed){}

char ConsoleFloatingPlatform::get_brush() const noexcept{
	return '*';
}
