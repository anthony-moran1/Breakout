//
//  Object.hpp
//  Breakout
//
//  Created by Anthony Moran on 02/07/2023.
//

#ifndef Object_hpp
#define Object_hpp

#include <SDL2/SDL.h>
#include "Tags.h"

class Object {
protected:
	SDL_Colour colour;
	
public:
	Tags tag = TUndefined;
	SDL_Rect rect;
	
	virtual void Event(SDL_Event event) {};
	virtual void Update(float deltaTime) {};
	virtual void Render(SDL_Renderer* renderer);
	
	void SetPosition(int x, int y);
};

#endif /* Object_hpp */
