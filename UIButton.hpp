//
//  UIButton.hpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#ifndef UIButton_hpp
#define UIButton_hpp

#include <string>

#include "UILabel.hpp"

class UIButton : public UILabel {
public:
	UIButton(std::string text, void(*on_click)());
	void Event(SDL_Event event);
	
private:
	void (*on_click)();
};

#endif /* UIButton_hpp */
