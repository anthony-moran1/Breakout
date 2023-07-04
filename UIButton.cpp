//
//  UIButton.cpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#include <iostream>

#include "UIButton.hpp"
#include "UILabel.hpp"

UIButton::UIButton(std::string text, void(*on_click)()) : on_click(on_click) {
	colour.r = 0x88;
	colour.g = 0x88;
	colour.b = 0x88;
	
	label = new UILabel(text);
	label->anchor.x = left;
	label->anchor.y = up;
	label->parent = this;
}

void UIButton::Event(SDL_Event event) {
	if (event.type == SDL_MOUSEBUTTONUP) {
		if (event.button.button == SDL_BUTTON_LEFT) {
			on_click();
		}
	}
}

void UIButton::Render(SDL_Renderer *renderer) {
	UIObject::Render(renderer);
	
	if (label != nullptr) {
		label->Render(renderer);
	}
}

void UIButton::OnLabelUpdateTexture() {
	SetSize(label->rect.w + padding.x * 2, label->rect.h + padding.y * 2);
	label->SetPosition(rect.x + padding.x, rect.y + padding.y);
}
