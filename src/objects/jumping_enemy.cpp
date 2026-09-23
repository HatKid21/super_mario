#include "jumping_enemy.hpp"

using biv::JumpingEnemy;

JumpingEnemy::JumpingEnemy(
	const Coord& top_left,const int width, const int height,
	const float horizontal_speed
)
	: BaseEnemy(top_left,width,height,horizontal_speed){
}

void JumpingEnemy::process_horizontal_static_collision(Rect*) noexcept{
	return;
}

void JumpingEnemy::process_vertical_static_collision(Rect*) noexcept{
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
	}
	jump();
}

//void JumpingEnemy::jump() noexcept{
//	vspeed -= JUMP_STRENGTH;
//}
