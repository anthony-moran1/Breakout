//
//  Anchor.h
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#ifndef Anchor_h
#define Anchor_h

enum AnchorX {
	left,
	centerx,
	right
};

enum AnchorY {
	up,
	centery,
	down
};

struct Anchor {
	AnchorX x;
	AnchorY y;
};

#endif /* Anchor_h */
