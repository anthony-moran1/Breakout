//
//  TextScore.hpp
//  Breakout
//
//  Created by Anthony Moran on 02/07/2023.
//

#ifndef TextScore_hpp
#define TextScore_hpp

#include <SDL2_ttf/SDL_ttf.h>
#include <string>

#include "UIObject.hpp"

extern std::string font_filepath;
extern TTF_Font* font;

class UILabel : public UIObject {
protected:
	SDL_Colour text_colour = {0x22, 0x22, 0x22, 0xFF};
	SDL_Rect text_rect;
	
	SDL_Surface* textSurface;
	SDL_Texture* textTexture;
	bool update_texture = false;
	
public:
	UILabel(std::string text);

	void Render(SDL_Renderer* renderer) override;
	
	void UpdateText(std::string text);
	void UpdateTexture(SDL_Renderer* renderer);
};

#endif /* TextScore_hpp */
