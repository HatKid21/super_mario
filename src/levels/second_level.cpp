#include "second_level.hpp"

using biv::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool SecondLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* SecondLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void SecondLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	//extra
	ui_factory->create_floating_platform({100,12},7,2);
	ui_factory->create_full_box({94,2},4,4);

	//initial layout
	ui_factory->create_ship({20, 25}, 40, 2);
	ui_factory->create_ship({60, 20}, 10, 7);
	ui_factory->create_ship({80, 25}, 20, 2);
	ui_factory->create_ship({120, 20}, 10, 7);
	ui_factory->create_ship({150, 25}, 40, 2);
	ui_factory->create_ship({210, 20}, 10, 7);

	//enemy
	ui_factory->create_enemy({20,15},3,2);
	ui_factory->create_enemy({55,15},3,2);

	ui_factory->create_jumping_enemy({65,15},3,2);

	ui_factory->create_flying_enemy({124,3},3,2);

	ui_factory->create_enemy({92,15},3,2);
	ui_factory->create_flying_enemy({100,18},3,2);
	
	ui_factory->create_enemy({155,15},3,2);
	ui_factory->create_jumping_enemy({151,15},3,2);
	ui_factory->create_jumping_enemy({181,18},3,2);

}
