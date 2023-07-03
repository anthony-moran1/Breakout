//
//  LabelScore.hpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#ifndef LabelScore_hpp
#define LabelScore_hpp

#include "UILabel.hpp"

class LabelScore : public UILabel {
public:
	LabelScore();
	void brick_hit_received();
};

#endif /* LabelScore_hpp */
