#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory){
	init_data();
}

bool ThirdLevel::is_final() const noexcept{
	return true;
}

biv::GameLevel* ThirdLevel::get_next(){
	return next;
}


void ThirdLevel::init_data(){
	//mario spawn
	ui_factory->create_mario({39, 10}, 3, 3);

	//first island
	ui_factory->create_ship({30,25},50,5);

	//jump tunnel 
	ui_factory->create_ship({100,27},73,1);
	ui_factory->create_ship({105,18},1,7);
	ui_factory->create_ship({106,18},5,1);
	ui_factory->create_jumping_enemy({111,20},2,2);
	ui_factory->create_jumping_enemy({120,20},2,2);
	ui_factory->create_jumping_enemy({129,20},2,2);
	ui_factory->create_jumping_enemy({138,20},2,2);
	ui_factory->create_jumping_enemy({147,20},2,2);
	ui_factory->create_ship({104,14},50,1);
	ui_factory->create_ship({113,18},7,1);
	ui_factory->create_ship({122,18},7,1);
	ui_factory->create_ship({131,18},7,1);
	ui_factory->create_ship({140,18},7,1);
	ui_factory->create_ship({149,18},10,1);

	//bonus above
	ui_factory->create_full_box({110,5},4,4);
	ui_factory->create_box({114,5},6,4);
	ui_factory->create_full_box({120,5},4,4);
	ui_factory->create_box({124,5},6,4);
	ui_factory->create_full_box({130,5},4,4);
	ui_factory->create_box({134,5},6,4);
	ui_factory->create_full_box({140,5},4,4);
	ui_factory->create_enemy({125,2},3,2);
	ui_factory->create_enemy({135,10},3,2);
	ui_factory->create_enemy({105,10},3,2);

	
	//second island
	ui_factory->create_ship({173,25},10,5);

	//floating platforms
	ui_factory->create_floating_platform({200,22},6,2);
	ui_factory->create_floating_platform({230,17},6,2);
	ui_factory->create_floating_platform({260,13},6,2);
	ui_factory->create_floating_platform({290,15},6,2);

	//third island
	ui_factory->create_ship({330,25},150,5);

	ui_factory->create_flying_enemy({350,20},3,2);
	ui_factory->create_flying_enemy({370,17},3,2);
	ui_factory->create_flying_enemy({389,21},3,2);
	ui_factory->create_flying_enemy({397,15},3,2);
	ui_factory->create_flying_enemy({410,19},3,2);
	ui_factory->create_flying_enemy({423,13},3,2);
	ui_factory->create_enemy({350,20},3,2);
	ui_factory->create_enemy({400,20},3,2);
	ui_factory->create_enemy({385,20},3,2);
	
	ui_factory->create_full_box({385,15},4,4);
	ui_factory->create_full_box({450,15},4,4);

	//last bridge
	ui_factory->create_box({498,20},25,3);
	ui_factory->create_full_box({510,11},4,4);
	ui_factory->create_enemy({510,16},3,2);

	//finish island
	ui_factory->create_ship({540,25},10,5);
}
