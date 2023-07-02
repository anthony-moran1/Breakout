//
//  Object.cpp
//  Breakout
//
//  Created by Anthony Moran on 02/07/2023.
//

#include "Object.hpp"

void Object::Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderFillRect(renderer, &rect);
}

void Object::SetPosition(int x, int y) {
	rect.x = x;
	rect.y = y;
}
