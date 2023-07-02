//
//  CollisionInfo.h
//  Breakout
//
//  Created by Anthony Moran on 29/06/2023.
//

#ifndef CollisionInfo_h
#define CollisionInfo_h

struct CollisionInfo {
	bool from_left = false;
	bool from_right = false;
	bool from_up = false;
	bool from_down = false;
	
	bool horisontal() {
		return from_left || from_right;
	}
	
	bool vertical() {
		return from_up || from_down;
	}
};

#endif /* CollisionInfo_h */
