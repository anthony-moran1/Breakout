#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>

#include "GameObject.hpp"
#include "Config.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "Ball.hpp"
#include "TextScore.hpp"

int main() {	
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialise the SDL2 library\n";
        return -1;
    }
	
	if (TTF_Init() == -1) {
		std::cout << "Failed to initialise the TTF library\n";
		return -1;
	}
	
	font = TTF_OpenFont(font_filepath.c_str(), 28);
	if (font == NULL) {
		std::cout << "Could not load font from file path: " << font_filepath << std::endl;
		return -1;
	}
	
    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		window_width, window_height, 0
	);

    if (!window) {
        std::cout << "Failed to create window\n";
        return -1;
    }
	
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
    Paddle* paddle = new Paddle();
	Ball* ball = new Ball();
	TextScore* text_score = new TextScore(renderer);
	
	add_gameobject(paddle);
	add_gameobject(ball);
	add_object(text_score);
	
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
			add_gameobject(brick);
		}
	}
	
	Uint32 last_ticks = SDL_GetTicks();
	Uint32 current_ticks;
	Uint32 delta_ticks;
	float delta_time;

    SDL_Event event;
    bool gameloop = true;

    while (gameloop) {
		// Framerate Calculating
		current_ticks = SDL_GetTicks();
		delta_ticks = current_ticks - last_ticks;
		last_ticks = current_ticks;
		delta_time = delta_ticks / 1000.0;
		
		// Inputting
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                gameloop = false;
            }

			paddle->Event(event);
        }
		
		// Updating
		for (Object* object : Objects) {
			object->Update(delta_time);
		}
		
		// Apply Velocity
		for (GameObject* gameobject : GameObjects) {
			gameobject->ApplyVelocity(delta_time);
		}

		// Rendering
		SDL_SetRenderDrawColor(renderer, background_colour.r, background_colour.g, background_colour.b, background_colour.a);
		SDL_RenderClear(renderer);
		
		for (Object* object : Objects) {
			object->Render(renderer);
		}
		
//		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
//		SDL_RenderDrawRect(renderer, &ALL_BRICK_RECT);
		
		SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	
	TTF_CloseFont(font);
	TTF_Quit();
    SDL_Quit();

    return 0;
}
