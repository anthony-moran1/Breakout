//
//  UIButton.cpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#include "UIButton.hpp"

UIButton::UIButton(std::string text, void(*on_click)()) : UILabel(text), on_click(on_click) {
	UpdateText(text);
}

void UIButton::Event(SDL_Event event) {
	if (event.type == SDL_MOUSEBUTTONUP) {
		if (event.button.button == SDL_BUTTON_LEFT) {
			on_click();
		}
	}
}
