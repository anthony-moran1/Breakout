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
	
	SetPosition(window_width / 2, window_height * .9);
	SetSize(96, 8);
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
