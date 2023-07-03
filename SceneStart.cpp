//
//  SceneStart.cpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#include "Config.hpp"
#include "SceneManager.hpp"
#include "SceneStart.hpp"
#include "UIButton.hpp"

SceneStart::SceneStart() {
	UIButton* start_button = new UIButton("Start", [] {
		load_scene(scene_main);
	});
	start_button->SetPosition(window_width / 2, window_height / 2);
	
	add_scene_object(start_button);
}
