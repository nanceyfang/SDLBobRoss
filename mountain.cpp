#include "mountain.h"
#include <vector>

Mountain::Mountain(SDL_Renderer* rend,SDL_Color c,std::vector<SDL_Point> p,
									 const int b):renderer(rend), COLOR(c), border(p), bottom(b)
{}

void Mountain::drawMountain() {

  SDL_SetRenderDrawColor(renderer, COLOR.r, COLOR.g, COLOR.b, COLOR.a);

  for (int i = 0; i < (int)border.size(); i++)
  {
    for (int j = 0; border[i].y + j < bottom; j++)
      SDL_RenderDrawPoint(renderer, border[i].x, border[i].y + j);
  }
}
