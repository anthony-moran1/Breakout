#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>

#include "Object.hpp"
#include "CollisionInfo.h"
#include "ExitWindowInfo.h"

class GameObject : public Object {
protected:
	int speed = 200;

public:
	SDL_Point move_direction;
	bool solid = true;
	
	void ApplyVelocity(float deltaTime);
	bool GetIntersectingWith(GameObject* other);
	virtual void OnCollision(GameObject* other, CollisionInfo info) {};
	virtual void OnExitWindow(ExitWindowInfo info) {};
};

#endif
