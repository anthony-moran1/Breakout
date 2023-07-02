//
//  Config.cpp
//  Breakout
//
//  Created by Anthony Moran on 29/06/2023.
//

#include <algorithm>
#include "Config.hpp"

int window_width = 480;
int window_height = 720;

SDL_Colour background_colour = {0xEE, 0xEE, 0xEE, 0xFF};

std::vector<Object*> Objects;
std::vector<GameObject*> GameObjects;

void add_object(Object* object) {
	Objects.push_back(object);
}
void remove_object(Object* object) {
	Objects.erase(std::remove(Objects.begin(), Objects.end(), object), Objects.end());
}

void add_gameobject(GameObject* gameobject) {
	add_object(gameobject);
	GameObjects.push_back(gameobject);
}
void remove_gameobject(GameObject* gameobject) {
	remove_object(gameobject);
	GameObjects.erase(std::remove(GameObjects.begin(), GameObjects.end(), gameobject), GameObjects.end());
}

Object* get_object_by_tag(Tags tag) {
	for (Object* object : Objects) {
		if (object->tag != tag) {
			continue;
		}
		return object;
	}
	return nullptr;
}

int score = 0;
int lives = 3;

TextScore* text_score = nullptr;
TextScore* get_text_score() {
	if (text_score == nullptr) {
		return dynamic_cast<TextScore*>(get_object_by_tag(TScore));
	}
	return text_score;
}

void brick_hit(GameObject* brick) {
	remove_gameobject(brick);
	score++;
	get_text_score()->brick_hit_received();
}
std::vector<void (*)()> brick_hit_delegate;
