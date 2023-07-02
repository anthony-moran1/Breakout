//
//  TextScore.cpp
//  Breakout
//
//  Created by Anthony Moran on 02/07/2023.
//

#include <string>

#include "Config.hpp"
#include "TextScore.hpp"

std::string font_filepath = std::string(SDL_GetBasePath()) + "Assets/calibri.ttf";
TTF_Font* font = NULL;

TextScore::TextScore(SDL_Renderer* renderer) {
	tag = TScore;
	
	textSurface = TTF_RenderUTF8_Blended(font, std::to_string(score).c_str(), text_colour);
	text_rect.x = 0;
	text_rect.y = 0;
	text_rect.w = textSurface->w;
	text_rect.h = textSurface->h;
	update_texture = true;
}

void TextScore::Render(SDL_Renderer *renderer) {
	if (update_texture) {
		UpdateTexture(renderer);
	}
	
	SDL_RenderCopy(renderer, textTexture, &text_rect, &rect);
}

void TextScore::UpdateTexture(SDL_Renderer *renderer) {
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	rect.w = text_rect.w;
	rect.h = text_rect.h;
	rect.x = (window_width - rect.w) / 2;
	rect.y = (window_height / 4 - rect.h) / 2;
	
	SDL_FreeSurface(textSurface);
	update_texture = false;
}

void TextScore::brick_hit_received() {
	textSurface = TTF_RenderUTF8_Blended(font, std::to_string(score).c_str(), text_colour);
	text_rect.w = textSurface->w;
	text_rect.h = textSurface->h;
	update_texture = true;
}
