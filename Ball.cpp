//
//  Ball.cpp
//  Breakout
//
//  Created by Anthony Moran on 29/06/2023.
//

#include "Ball.hpp"
#include "Config.hpp"

class Paddle;

Ball::Ball() {
	colour.r = 0x88;
	colour.g = 0x88;
	colour.b = 0x88;
	colour.a = 0xFF;
	
	SetPosition(window_width / 2, window_height / 3 * 2);
	SetSize(8, 8);
	
	move_direction.x = -1;
	move_direction.y = 1;
	
	speed = 200;
}

void Ball::Reset() {
	if (lives <= 0) {
		remove_object(this);
		return;
	}
	
	lives--;
	rect.x = spawn_point.x;
	rect.y = spawn_point.y;
}

void Ball::SetPosition(int x, int y, bool spawn) {
	GameObject::SetPosition(x, y);
	
	if (!spawn) {
		return;
	}
	spawn_point.x = x;
	spawn_point.y = y;
}

void Ball::OnCollision(GameObject* other, CollisionInfo info) {
	switch (other->tag) {
		case TPaddle:
			if (info.vertical()) {
				move_direction.y *= -1;
			} else {
				move_direction.x *= -1;
			}
			break;
			
		case TBrick:
			if (info.vertical()) {
				move_direction.y *= -1;
			}
			if (info.horisontal()){
				move_direction.x *= -1;
			}
			
			brick_hit(other);
			break;
			
		default:
			break;
	}
	
	if (other->solid) {
		if (info.from_left) {
			rect.x = other->rect.x+other->rect.w;
		}
		if (info.from_right) {
			rect.x = other->rect.x-rect.w;
		}
		if (info.from_up) {
			rect.y = other->rect.y+other->rect.h;
		}
		if (info.from_down) {
			rect.y = other->rect.y-rect.h;
		}
	}
}

void Ball::OnExitWindow(ExitWindowInfo info) {
	if (info.horisontal()) {
		move_direction.x *= -1;
	}
	
	if (info.from_left) {
		rect.x = 0;
	} else if (info.from_right) {
		rect.x = window_width-rect.w;
	}
	
	if (info.from_up) {
		rect.y = 0;
		move_direction.y *= -1;
	} else if (info.from_down) {
		Reset();
	}
}
