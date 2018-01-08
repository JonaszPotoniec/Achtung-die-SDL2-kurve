#include <cmath>
#include <SDL2/SDL.h>
#include "player.h"
#include <unistd.h>

void player::setColor(int red, int green, int blue){
  R = red; G = green; B = blue;
}

void player::draw(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor( renderer, R, G, B, 0xFF );
  SDL_RenderDrawPoint( renderer, positionX, positionY );
}

void player::move(int* ticks){
  printf("%f %i %f  \n", rotation, SDL_GetTicks() - lastMoveTicks, rotation/sensitivity);

  positionX += sin(rotation) * speed * ticks[0];
  positionY += cos(rotation) * speed * ticks[0];
}

void player::input(SDL_Event* evnt, int* ticks){
  if( evnt[0].key.keysym.sym == SDLK_LEFT && SDL_GetTicks() - lastMoveTicks > 200){
    rotation++;
    lastMoveTicks = SDL_GetTicks();
  }else if( evnt[0].key.keysym.sym == SDLK_RIGHT && SDL_GetTicks() - lastMoveTicks > 200){
    rotation--;
    lastMoveTicks = SDL_GetTicks();
  }

  if(rotation > 360)
    rotation = 0;
  else if(rotation < 0)
    rotation = 360;

}
