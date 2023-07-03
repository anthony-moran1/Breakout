//
//  SceneMain.cpp
//  Breakout
//
//  Created by Anthony Moran on 03/07/2023.
//

#include "Config.hpp"
#include "SceneMain.hpp"

#include "Paddle.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "LabelScore.hpp"

SceneMain::SceneMain() {
	Paddle* paddle = new Paddle();
	Ball* ball = new Ball();
	LabelScore* text_score = new LabelScore();

	add_scene_object(paddle);
	add_scene_object(ball);
	add_scene_object(text_score);

	// Spawn bricks
	// Calculating number of bricks to fill area
	const SDL_Point BRICK_START = {0, window_height / 4};
	const SDL_Point ALL_BRICKS_SIZE = {window_width, window_height / 4};
	//	const SDL_Rect ALL_BRICK_RECT = {BRICK_START.x, BRICK_START.y, ALL_BRICKS_SIZE.x, ALL_BRICKS_SIZE.y};
	const SDL_Point BRICK_PADDING_WALL = {window_width / 10, 5};
	const SDL_Point BRICK_PADDING_BRICK = {5, 10};

	const SDL_Point NUM_BRICKS = {
		(ALL_BRICKS_SIZE.x - BRICK_PADDING_WALL.x * 2) / (Brick::Size.x + BRICK_PADDING_BRICK.x),
		(ALL_BRICKS_SIZE.y - BRICK_PADDING_WALL.y * 2) / (Brick::Size.y + BRICK_PADDING_BRICK.y)
	};

	const SDL_Point SPARE_SPACE = {
		ALL_BRICKS_SIZE.x - BRICK_PADDING_WALL.x * 2 - (Brick::Size.x + BRICK_PADDING_BRICK.x) * NUM_BRICKS.x + BRICK_PADDING_BRICK.x,
		ALL_BRICKS_SIZE.y - BRICK_PADDING_WALL.y * 2 - (Brick::Size.y + BRICK_PADDING_BRICK.y) * NUM_BRICKS.y + BRICK_PADDING_BRICK.y
	};

	const SDL_Point SPARE_SPACE_INDIVIDUAL = {
		SPARE_SPACE.x / (NUM_BRICKS.x),
		SPARE_SPACE.y / (NUM_BRICKS.y)
	};

	Brick* brick;
	for (int row=0; row<NUM_BRICKS.y; row++) {
		int brick_y = BRICK_START.y + BRICK_PADDING_WALL.y + (Brick::Size.y + BRICK_PADDING_BRICK.y + SPARE_SPACE_INDIVIDUAL.y) * row + SPARE_SPACE_INDIVIDUAL.y / 2;

		for (int col=0; col<NUM_BRICKS.x; col++) {
			int brick_x = BRICK_START.x + BRICK_PADDING_WALL.x + (Brick::Size.x + BRICK_PADDING_BRICK.x + SPARE_SPACE_INDIVIDUAL.x) * col + SPARE_SPACE_INDIVIDUAL.x / 2;
			brick = new Brick();
			brick->SetPosition(brick_x, brick_y);
			add_scene_object(brick);
		}
	}
}
