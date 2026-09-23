#include "console_jumping_enemy.hpp"

using biv::ConsoleJumpingEnemy;

ConsoleJumpingEnemy::ConsoleJumpingEnemy(
	const Coord& top_left, const int width, const int height,
	const float horizontal_speed
)
	: JumpingEnemy(top_left, width, height, horizontal_speed){}

char ConsoleJumpingEnemy::get_brush() const noexcept{
	return 'j';
}
