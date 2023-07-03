//
//  Scene.cpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#include "Config.hpp"
#include "Scene.hpp"

void Scene::add_scene_object(Object *object) {
	switch (object->object_type) {
		case OUI:
			this->UIObjects.push_back(dynamic_cast<UIObject*>(object));
			break;
		case OGame:
			this->GameObjects.push_back(dynamic_cast<GameObject*>(object));
			break;
		case OUndefined:
			break;
	}
}

void Scene::remove_scene_object(Object *object) {
	switch (object->object_type) {
		case OUI:
			this->UIObjects.erase(std::remove(this->UIObjects.begin(), this->UIObjects.end(), object), this->UIObjects.end());
			break;
		case OGame:
			this->GameObjects.erase(std::remove(this->GameObjects.begin(), this->GameObjects.end(), object), this->GameObjects.end());
			break;
		case OUndefined:
			break;
	}
}

void Scene::load() {
	for (UIObject* uiobject : UIObjects) {
		add_object(uiobject);
	}
	
	for (GameObject* gameobject : GameObjects) {
		add_object(gameobject);
	}
}

void Scene::unload() {
	for (UIObject* uiobject : UIObjects) {
		remove_object(uiobject);
	}
	
	for (GameObject* gameobject : GameObjects) {
		remove_object(gameobject);
	}
}
