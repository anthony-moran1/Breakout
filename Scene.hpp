//
//  Scene.hpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <vector>
#include "UIObject.hpp"
#include "GameObject.hpp"

class Scene {
private:
	std::vector<UIObject*> UIObjects;
	std::vector<GameObject*> GameObjects;
	
protected:
	void add_scene_object(Object* object);
	void remove_scene_object(Object* object);
	
public:
	void load();
	void unload();
};

#endif /* Scene_hpp */
