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
	int min_speed = 200;
	int max_speed = 800;
	
public:
	Ball();
	~Ball();
	
	void Event(SDL_Event event) override;
	void Update(float deltaTime) override;
	
	void Reset();
	void SetPosition(int x, int y, bool spawn=true);
	
	void OnCollision(GameObject* other, CollisionInfo info) override;
	void OnExitWindow(ExitWindowInfo info) override;
};

#endif /* Ball_hpp */
