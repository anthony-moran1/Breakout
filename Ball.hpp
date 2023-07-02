//
//  Ball.hpp
//  Breakout
//
//  Created by Anthony Moran on 29/06/2023.
//

#ifndef Ball_hpp
#define Ball_hpp

#include "GameObject.hpp"

class Ball : public GameObject {
private:
	SDL_Point spawn_point;
	
public:
	Ball();
	~Ball();
	
	void Reset();
	void SetPosition(int x, int y, bool spawn=true);
	
	void OnCollision(GameObject* other, CollisionInfo info) override;
	void OnExitWindow(ExitWindowInfo info) override;
};

#endif /* Ball_hpp */
