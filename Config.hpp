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
#include "Object.hpp"
#include "GameObject.hpp"
#include "TextScore.hpp"
#include "Tags.h"

extern int window_width;
extern int window_height;

extern SDL_Colour background_colour;

extern std::vector<Object*> Objects;
extern std::vector<GameObject*> GameObjects;

extern void add_object(Object* object);
extern void remove_object(Object* object);
extern void add_gameobject(GameObject* object);
extern void remove_gameobject(GameObject* object);

extern Object* get_object_by_tag(Tags tag);

extern int score;
extern int lives;

extern TextScore* text_score;
extern TextScore* get_text_score();
extern void brick_hit(GameObject* brick);

#endif /* Config_hpp */
