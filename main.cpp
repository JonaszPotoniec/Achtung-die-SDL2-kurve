#include <SDL2/SDL.h>
#include <unistd.h>
#include "player.h"
#include "player.cpp"

bool init();
void input();

const int resolutionX = 800;
const int resolutionY = 600;
int mouseX, mouseY;
SDL_Window* window = NULL;
SDL_Renderer* windowRenderer = NULL;
SDL_Event evnt;
bool run = true;
int ticks;
int *deltaTicks = new int;

int main(){
  run = init();

  SDL_SetRenderDrawColor( windowRenderer, 0, 0, 0, 0xFF );
  SDL_RenderClear( windowRenderer );

  player playerObject;
  playerObject.setColor(255, 255, 255);

  while(run){
    deltaTicks[0] = ticks - SDL_GetTicks();
    ticks = SDL_GetTicks();

    input();
    if(evnt.type == SDL_KEYDOWN){
      playerObject.input(&evnt, deltaTicks);
    }

    playerObject.move(deltaTicks);

    playerObject.draw(windowRenderer);

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
  //SDL_GetMouseState(&mouseX, &mouseY);
  while(SDL_PollEvent(&evnt)){
    if(evnt.type == SDL_QUIT)
      run = false;
  }
}
