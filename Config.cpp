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

std::vector<GameObject*> GameObjects;
void add_gameobject(GameObject* gameobject) {
	GameObjects.push_back(gameobject);
}
void remove_gameobject(GameObject* gameobject) {
	GameObjects.erase(std::remove(GameObjects.begin(), GameObjects.end(), gameobject), GameObjects.end());
}

int score = 0;
