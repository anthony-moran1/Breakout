//
//  TextScore.cpp
//  Breakout
//
//  Created by Anthony Moran on 02/07/2023.
//

#include <string>

#include "Config.hpp"
#include "UILabel.hpp"
#include "UIButton.hpp"

std::string font_filepath = std::string(SDL_GetBasePath()) + "Assets/calibri.ttf";
TTF_Font* font = NULL;

UILabel::UILabel(std::string text) {
	UpdateText(text);
}

void UILabel::Render(SDL_Renderer *renderer) {
	if (update_texture) {
		UpdateTexture(renderer);
	}
	
	SDL_RenderCopy(renderer, textTexture, NULL, &rect);
}

void UILabel::UpdateText(std::string text) {
	textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), text_colour);
	text_size.x = textSurface->w;
	text_size.y = textSurface->h;
	update_texture = true;
}

void UILabel::UpdateTexture(SDL_Renderer *renderer) {
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SetSize(text_size.x, text_size.y);
	
	SDL_FreeSurface(textSurface);
	update_texture = false;
	
	if (parent != nullptr) {
		parent->OnLabelUpdateTexture();
	}
}
