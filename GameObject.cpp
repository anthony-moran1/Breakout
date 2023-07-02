#include "Config.hpp"
#include "GameObject.hpp"

void GameObject::ApplyVelocity(float deltaTime) {
	SDL_FPoint move_direction_normalised = {
		(float) move_direction.x,
		(float) move_direction.y
	};
	
	if (move_direction.x != 0 && move_direction.y != 0) {
		move_direction_normalised.x /= M_SQRT2;
		move_direction_normalised.y /= M_SQRT2;
	}
 
	SDL_Point move = {
		(int) round(move_direction_normalised.x * speed * deltaTime),
		(int) round(move_direction_normalised.y * speed * deltaTime)
	};
	
	rect.x += move.x;
	rect.y += move.y;
	
	// Collision checking
	for (GameObject* gameobject : GameObjects) {
		if (gameobject == this || !GetIntersectingWith(gameobject)) {
			continue;
		}
		
		CollisionInfo info;
		
		rect.x -= move.x;
		if (GetIntersectingWith(gameobject)) {
			rect.y -= move.y;
			if (rect.y >= gameobject->rect.y+gameobject->rect.h) {
				info.from_up = true;
			} else {
				info.from_down = true;
			}
			rect.y += move.y;
		}
		rect.x += move.x;
		
		rect.y -= move.y;
		if (GetIntersectingWith(gameobject)) {
			rect.x -= move.x;
			if (rect.x >= gameobject->rect.x+gameobject->rect.w) {
				info.from_left = true;
			} else {
				info.from_right = true;
			}
			move.x += move.x;
		}
		rect.y += move.y;
		
		OnCollision(gameobject, info);
	}
	
	// Keep in bounds
	ExitWindowInfo info;

	if (rect.x < 0) {
		rect.x = 0;
		info.from_left = true;
	} else if (rect.x + rect.w > window_width) {
		rect.x = window_width - rect.w;
		info.from_right = true;
	}
	
	if (rect.y < 0) {
		rect.y = 0;
		info.from_up = true;
	} else if (rect.y + rect.h > window_height) {
		rect.y = window_height - rect.h;
		info.from_down = true;
	}
	
	if (info.any()) {
		OnExitWindow(info);
	}
}

bool GameObject::GetIntersectingWith(GameObject *other) {
	return SDL_HasIntersection(&rect, &other->rect);
}
