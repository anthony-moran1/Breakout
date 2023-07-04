#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>

#include "Object.hpp"
#include "CollisionInfo.h"
#include "ExitWindowInfo.h"

class GameObject : public Object {
protected:
	int speed = 200;
	bool freeze = false;

public:
	SDL_Point move_direction;
	bool solid = true;
	
	GameObject();
	
	void ApplyVelocity(float deltaTime);
	bool GetIntersectingWith(GameObject* other);
	virtual void OnCollision(GameObject* other, CollisionInfo info) {};
	virtual void OnExitWindow(ExitWindowInfo info) {};
};

#endif
