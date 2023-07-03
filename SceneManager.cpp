//
//  SceneManager.cpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#include "SceneManager.hpp"
#include "SceneStart.hpp"
#include "SceneMain.hpp"

Scene* scene_start;
Scene* scene_main;
Scene** first_scene = &scene_start;
Scene* current_scene = nullptr;

void initialise_scenes() {
	scene_start = new SceneStart();
	scene_main = new SceneMain();
}

void load_first_scene() {
	load_scene(*first_scene);
}

void load_scene(Scene* scene) {
	if (current_scene != nullptr) {
		current_scene->unload();
	}
	scene->load();
	current_scene = scene;
}
