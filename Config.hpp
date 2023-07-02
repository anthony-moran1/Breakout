//
//  Config.hpp
//  Breakout
//
//  Created by Anthony Moran on 29/06/2023.
//

#ifndef Config_hpp
#define Config_hpp

#include <SDL2/SDL.h>
#include <vector>
#include "GameObject.hpp"

extern int window_width;
extern int window_height;

extern SDL_Colour background_colour;

extern std::vector<GameObject*> GameObjects;
extern void add_gameobject(GameObject* gameobject);
extern void remove_gameobject(GameObject* gameobject);

extern int score;

#endif /* Config_hpp */
