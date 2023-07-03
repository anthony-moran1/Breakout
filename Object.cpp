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
	switch (anchor.x) {
		case left:
			rect.x = x;
			break;
		case centerx:
			rect.x = x - rect.w / 2;
			break;
		case right:
			rect.x = x - rect.w;
			break;
	}
	
	switch (anchor.y) {
		case up:
			rect.y = y;
			break;
		case centery:
			rect.y = y - rect.h / 2;
			break;
		case down:
			rect.y = y - rect.h;
			break;
	}
}

void Object::SetSize(int w, int h) {
	int w_dif = w - rect.w;
	int h_dif = h - rect.h;
	rect.w = w;
	rect.h = h;
	
	switch (anchor.x) {
		case left:
			break;
		case centerx:
			rect.x -= w_dif / 2;
			break;
		case right:
			rect.x -= w_dif;
			break;
	}
	
	switch (anchor.y) {
		case up:
			break;
		case centery:
			rect.y -= h_dif / 2;
			break;
		case down:
			rect.y -= h_dif;
			break;
	}
}
