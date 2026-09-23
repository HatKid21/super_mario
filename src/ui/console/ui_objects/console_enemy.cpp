#include "console_enemy.hpp"

using biv::ConsoleEnemy;

ConsoleEnemy::ConsoleEnemy(
	const Coord& top_left, const int width, const int height,
	const float horizontal_speed
)
	: Enemy(top_left, width, height, horizontal_speed) {}

char ConsoleEnemy::get_brush() const noexcept {
	return 'e';
}
