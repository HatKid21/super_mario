/**
	- Если создавать класс FlyableEenemy, JumpableEnemy и другие виды врагов, 
		то почему их нельзя наследовать от Enemy?
*/

#pragma once

#include "base_enemy.hpp"

namespace biv {
	class Enemy : public BaseEnemy {
		public:
			using BaseEnemy::BaseEnemy;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
