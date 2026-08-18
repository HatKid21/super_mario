#include <cmath>

#include "flying_enemy.hpp"

namespace biv {
    FlyingEnemy::FlyingEnemy(const Coord& top_left, const int width, const int height)
        : BaseEnemy(top_left, width, height),start_x(top_left.x) {
	vspeed = 0;
    }

    void FlyingEnemy::move_horizontally() noexcept{
    	if (std::abs(top_left.x - start_x) > 10){
		hspeed = -hspeed;
	}
	top_left.x += hspeed;
    }

    void FlyingEnemy::move_vertically() noexcept {
	if (is_active()) {
		return;
	}

	if (vspeed < MAX_V_SPEED) {
		vspeed += V_ACCELERATION;
	}
	top_left.y += vspeed;
    }

    void FlyingEnemy::process_vertical_static_collision(Rect* obj) noexcept {
    }

    void FlyingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
        hspeed = -hspeed;
	move_horizontally();
    }
}
