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
public:
	Ball();
	~Ball();
	
	void OnCollision(GameObject* other, CollisionInfo info) override;
	void OnExitWindow(ExitWindowInfo info) override;
};

#endif /* Ball_hpp */
