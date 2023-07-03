//
//  Brick.cpp
//  Breakout
//
//  Created by Anthony Moran on 29/06/2023.
//

#include "Brick.hpp"

SDL_Point Brick::Size = {48, 16};

Brick::Brick() {
	tag = TBrick;

	SetSize(Brick::Size.x, Brick::Size.y);
	
	colour.r = 0xCC;
	colour.g = 0xCC;
	colour.b = 0xCC;
	colour.a = 0xFF;
	
	anchor.x = left;
	anchor.y = up;
}
