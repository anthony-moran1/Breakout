//
//  Paddle.cpp
//  Breakout
//
//  Created by Anthony Moran on 29/06/2023.
//

#include "Paddle.hpp"
#include "Config.hpp"

Paddle::Paddle() {
	tag = TPaddle;
	
	colour.r = 0;
	colour.g = 0;
	colour.b = 0;

	rect.w = 96;
	rect.h = 8;
	rect.x = (window_width - rect.w) / 2;
	rect.y = window_height * .9 - rect.h;
}

void Paddle::Event(SDL_Event event) {
	switch (event.type) {
		case SDL_KEYDOWN:
			if (event.key.repeat > 0) {
				break;
			}
			
			switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					move_direction.x -= 1;
					break;
				case SDLK_RIGHT:
					move_direction.x += 1;
					break;
			}
			break;
			
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					move_direction.x += 1;
					break;
				case SDLK_RIGHT:
					move_direction.x -= 1;
					break;
			}
			break;
	}
}
