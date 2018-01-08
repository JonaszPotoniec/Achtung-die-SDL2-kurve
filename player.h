#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>
#include <SDL2/SDL.h>

class player{
private:
  double positionX = 400;
  double positionY = 400;
  int R, G, B;
  double rotation = 0;
  double speed = 0.01;
  double sensitivity = 10000;
  int lastMoveTicks = 0;
public:
  void setColor(int red, int green, int blue);
  void draw(SDL_Renderer* renderer);
  void move(int* ticks);
  void input(SDL_Event* evnt, int* ticks);
};

 #endif
