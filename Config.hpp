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
#include "UIObject.hpp"
#include "GameObject.hpp"
#include "LabelScore.hpp"
#include "Tag.h"
#include "ObjectType.h"

extern int window_width;
extern int window_height;

extern SDL_Colour background_colour;

extern std::vector<UIObject*> UIObjects;
extern std::vector<GameObject*> GameObjects;

extern void add_object(Object* object);
extern void remove_object(Object* object);
extern UIObject* get_uiobject_by_tag(Tag tag);
extern GameObject* get_gameobject_by_tag(Tag tag);

extern int score;
extern int lives;

extern LabelScore* label_score;
extern void brick_hit(GameObject* brick);

#endif /* Config_hpp */
