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
	
	rect.w = 8;
	rect.h = 8;
	rect.x = (window_width - rect.w) / 2;
	rect.y = (window_height - rect.h) / 3 * 2;
	
	move_direction.x = -1;
	move_direction.y = 1;
	
	speed = 200;
}

void Ball::OnCollision(GameObject* other, CollisionInfo info) {
	switch (other->tag) {
		case TPaddle:
			if (info.vertical()) {
				move_direction.y *= -1;
			} else {
				if (SameDirectionAs(other)) {
					return;
				}
				move_direction.x *= -1;
			}
			
			if (info.from_left) {
				rect.x = other->rect.x+other->rect.w;
			}
			if (info.from_right) {
				rect.x = other->rect.x-rect.w;
			}
			if (info.from_up) {
				rect.y = other->rect.y+other->rect.h;
				std::cout << "from up\n";
			}
			if (info.from_down) {
				rect.y = other->rect.y-rect.h;
				std::cout << "from down\n";
			}
			break;
			
		case TBrick:
			if (info.vertical()) {
				move_direction.y *= -1;
			} else {
				if (SameDirectionAs(other)) {
					return;
				}
				move_direction.x *= -1;
			}
			
			remove_gameobject(other);
			score++;
			std::cout << "Score: " << score << std::endl;
			break;
			
		case TUndefined:
			break;
	}
}

void Ball::OnExitWindow(ExitWindowInfo info) {
	if (info.horisontal) {
		move_direction.x *= -1;
	}
	
	if (info.vertical) {
		move_direction.y *= -1;
	}
}
