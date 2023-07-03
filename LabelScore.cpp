//
//  LabelScore.cpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#include "Config.hpp"
#include "LabelScore.hpp"

LabelScore::LabelScore() : UILabel(std::to_string(score)) {
	label_score = this;
	SetPosition(window_width / 2, window_height / 8);
}

void LabelScore::brick_hit_received() {
	UpdateText(std::to_string(score));
}
