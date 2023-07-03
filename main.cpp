#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>

#include "GameObject.hpp"
#include "Config.hpp"
#include "SceneManager.hpp"

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
	
	initialise_scenes();
	load_first_scene();
	
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
			
			for (UIObject* uiobject : UIObjects) {
				uiobject->Event(event);
			}
			
			for (GameObject* gameobject : GameObjects) {
				gameobject->Event(event);
			}
        }
		
		// Updating
		for (GameObject* gameobject : GameObjects) {
			gameobject->Update(delta_time);
		}
		
		for (Object* object : UIObjects) {
			object->Update(delta_time);
		}
		
		// Apply Velocity
		for (GameObject* gameobject : GameObjects) {
			gameobject->ApplyVelocity(delta_time);
		}

		// Rendering
		SDL_SetRenderDrawColor(renderer, background_colour.r, background_colour.g, background_colour.b, background_colour.a);
		SDL_RenderClear(renderer);
		
		for (GameObject* gameobject : GameObjects) {
			gameobject->Render(renderer);
		}
		
		for (Object* object : UIObjects) {
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
