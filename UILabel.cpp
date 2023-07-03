//
//  TextScore.cpp
//  Breakout
//
//  Created by Anthony Moran on 02/07/2023.
//

#include <string>

#include "Config.hpp"
#include "UILabel.hpp"

std::string font_filepath = std::string(SDL_GetBasePath()) + "Assets/calibri.ttf";
TTF_Font* font = NULL;

UILabel::UILabel(std::string text) {
	UpdateText(text);
	text_rect.x = 0;
	text_rect.y = 0;
}

void UILabel::Render(SDL_Renderer *renderer) {
	if (update_texture) {
		UpdateTexture(renderer);
	}
	
	SDL_RenderCopy(renderer, textTexture, &text_rect, &rect);
}

void UILabel::UpdateText(std::string text) {
	textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), text_colour);
	text_rect.w = textSurface->w;
	text_rect.h = textSurface->h;
	update_texture = true;
}

void UILabel::UpdateTexture(SDL_Renderer *renderer) {
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SetSize(text_rect.w, text_rect.h);
	
	SDL_FreeSurface(textSurface);
	update_texture = false;
}
