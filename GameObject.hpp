#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "Tags.h"
#include "CollisionInfo.h"
#include "ExitWindowInfo.h"

class GameObject {
protected:
	SDL_Colour colour;
	int speed = 200;

public:
	Tags tag = TUndefined;
	SDL_Rect rect;
	SDL_Point move_direction;
	
	virtual void Event(SDL_Event event) {};
	virtual void Update(float deltaTime) {};
	void Render(SDL_Renderer* renderer);
	
	void SetPosition(int x, int y);
	void ApplyVelocity(float deltaTime);
	bool GetIntersectingWith(GameObject* other);
	bool SameDirectionAs(GameObject* other);
	virtual void OnCollision(GameObject* other, CollisionInfo info) {};
	virtual void OnExitWindow(ExitWindowInfo info) {};
};

#endif
