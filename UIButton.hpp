//
//  UIButton.hpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#ifndef UIButton_hpp
#define UIButton_hpp

#include <string>

#include "UIObject.hpp"
class UILabel;

class UIButton : public UIObject {
public:
	UIButton(std::string text, void(*on_click)());
	
	void Event(SDL_Event event) override;
	void Render(SDL_Renderer* renderer) override;
	
	void AssignLabel(UILabel* label);
	void OnLabelUpdateTexture();
	
private:
	void (*on_click)();
	SDL_Point padding = {10, 7};
	UILabel* label = nullptr;
};

#endif /* UIButton_hpp */
