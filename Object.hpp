//
//  Object.hpp
//  Breakout
//
//  Created by Anthony Moran on 02/07/2023.
//

#ifndef Object_hpp
#define Object_hpp

#include <SDL2/SDL.h>
#include "Tag.h"
#include "ObjectType.h"
#include "Anchor.h"

class Object {
protected:
	SDL_Colour colour;
	
public:
	Tag tag = TUndefined;
	ObjectType object_type = OUndefined;
	SDL_Rect rect;
	Anchor anchor = {centerx, centery};
	
	virtual void Event(SDL_Event event) {};
	virtual void Update(float deltaTime) {};
	virtual void Render(SDL_Renderer* renderer);
	
	void SetPosition(int x, int y);
	void SetSize(int w, int h);
};

#endif /* Object_hpp */
