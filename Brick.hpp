//
//  Brick.hpp
//  Breakout
//
//  Created by Anthony Moran on 29/06/2023.
//

#ifndef Brick_hpp
#define Brick_hpp

#include "GameObject.hpp"

class Brick : public GameObject {
public:
	Brick();
	~Brick();
	
	static SDL_Point Size;
};

#endif /* Brick_hpp */
