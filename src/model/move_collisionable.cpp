#include "move_collisionable.hpp"

using biv::MoveCollisionable;

void MoveCollisionable::move_platform(MoveCollisionable* fp) noexcept {
    move_horizontal_offset(fp->get_speed().h);
}
