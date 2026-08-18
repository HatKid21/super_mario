#include "jumping_enemy.hpp"

using biv::JumpingEnemy;

JumpingEnemy::JumpingEnemy(const Coord& top_left,const int width, const int height)
	: BaseEnemy(top_left,width,height){
	hspeed = 0;
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

