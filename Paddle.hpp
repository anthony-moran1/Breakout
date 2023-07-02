//
//  Paddle.hpp
//  Breakout
//
//  Created by Anthony Moran on 29/06/2023.
//

#ifndef Paddle_hpp
#define Paddle_hpp

#include "GameObject.hpp"

class Paddle : public GameObject {
public:
	Paddle();
	~Paddle();
	
	void Event(SDL_Event event);
};

#endif /* Paddle_hpp */
