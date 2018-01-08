#ifndef PLAYER_H
#define PLAYER_H

class player{
private:
  int positionX;
  int positionY;
  int R, G, B;
public:
  void setColor(int red, int green, int blue);
  void draw();
};
