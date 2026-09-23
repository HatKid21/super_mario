#include "console_flying_enemy.hpp"

using biv::ConsoleFlyingEnemy;

ConsoleFlyingEnemy::ConsoleFlyingEnemy(
	const Coord& top_left, const int width, const int height,
	const float horizontal_speed
)
	: FlyingEnemy(top_left, width, height, horizontal_speed){}

char ConsoleFlyingEnemy::get_brush() const noexcept{
	return 'f';
}
