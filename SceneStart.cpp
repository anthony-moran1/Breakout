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
#include "UILabel.hpp"

SceneStart::SceneStart() {
	UILabel* title_label = new UILabel("Breakout");
	title_label->SetPosition(window_width / 2, window_height / 4);
	
	UIButton* start_button = new UIButton("Start", [] {
		load_scene(scene_main);
	});
	start_button->SetPosition(window_width / 2, window_height / 2);
	start_button->SetSize(96, 32);
	
	add_scene_object(title_label);
	add_scene_object(start_button);
}
