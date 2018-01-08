#include <SDL2/SDL.h>
#include <unistd.h>
#include "player.h"
#include "player.cpp"

bool init();
void input();

const int resolutionX = 1280;
const int resolutionY = 720;
int mouseX, mouseY;
SDL_Window* window = NULL;
SDL_Renderer* windowRenderer = NULL;
SDL_Event evnt;
bool run = true;


int main(){
  run = init();

  SDL_SetRenderDrawColor( windowRenderer, 0, 0, 0, 0xFF );
  SDL_RenderClear( windowRenderer );

  while(run){
    input();
    SDL_SetRenderDrawColor( windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderDrawPoint( windowRenderer, mouseX, mouseY );
    printf("%i  %i\n", mouseX, mouseY);
    SDL_RenderPresent( windowRenderer );
  }
}

bool init(){
	//init everything
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
  		printf("Failed to initialize SDL, error: %s\n", SDL_GetError());
      return 0;
  }

	window = SDL_CreateWindow("Achtung", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, resolutionX, resolutionY, SDL_WINDOW_SHOWN/* | SDL_WINDOW_FULLSCREEN_DESKTOP*/);
	if (window == 0){
    printf("Failed to create window, error: %s\n", SDL_GetError());
    return 0;
  }

	windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (windowRenderer == 0){
    printf("Can't create renderer, error: %s\n", SDL_GetError());
    return 0;
  }
  return 1;
}

void input(){
  SDL_GetMouseState(&mouseX, &mouseY);
  while(SDL_PollEvent(&evnt)){
    if(evnt.type == SDL_QUIT)
      run = false;
  }
}
