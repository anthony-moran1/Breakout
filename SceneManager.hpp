//
//  SceneManager.hpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include "Scene.hpp"

extern Scene* scene_start;
extern Scene* scene_main;
extern Scene** first_scene;
extern Scene* current_scene;

extern void initialise_scenes();
extern void load_first_scene();
extern void load_scene(Scene* scene);

#endif /* SceneManager_hpp */
