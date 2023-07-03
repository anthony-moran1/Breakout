//
//  Config.cpp
//  Breakout
//
//  Created by Anthony Moran on 29/06/2023.
//

#include <algorithm>
#include <map>
#include "Config.hpp"

int window_width = 480;
int window_height = 720;

SDL_Colour background_colour = {0xEE, 0xEE, 0xEE, 0xFF};

std::vector<UIObject*> UIObjects;
std::vector<GameObject*> GameObjects;

void add_object(Object* object) {
	switch (object->object_type) {
		case OUI:
			UIObjects.push_back(dynamic_cast<UIObject*>(object));
			break;
		case OGame:
			GameObjects.push_back(dynamic_cast<GameObject*>(object));
			break;
		case OUndefined:
			break;
	}
}

void remove_object(Object* object) {
	switch (object->object_type) {
		case OUI:
			UIObjects.erase(std::remove(UIObjects.begin(), UIObjects.end(), object), UIObjects.end());
			break;
		case OGame:
			GameObjects.erase(std::remove(GameObjects.begin(), GameObjects.end(), object), GameObjects.end());
			break;
		case OUndefined:
			break;
	}
}

UIObject* get_uiobject_by_tag(Tag tag) {
	for (UIObject* object : UIObjects) {
		if (object->tag != tag) {
			continue;
		}
		return object;
	}
	return nullptr;
}

GameObject* get_gameobject_by_tag(Tag tag) {
	for (GameObject* gameobject : GameObjects) {
		if (gameobject->tag != tag) {
			continue;
		}
		return gameobject;
	}
	return nullptr;
}

int score = 0;
int lives = 3;

LabelScore* label_score = nullptr;

void brick_hit(GameObject* brick) {
	remove_object(brick);
	score++;
	label_score->brick_hit_received();
}
