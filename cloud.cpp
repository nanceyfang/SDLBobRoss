#include "cloud.h"

Cloud::Cloud(SDL_Renderer* rend, SDL_Point p, const int w) : 
						 renderer(rend), position(p), WIDTH(w)
{}

// draws w/ rects w/ a lower alpha
void Cloud::drawCloud() {
	SDL_Rect r1 = {position.x, position.y, 170, 50};
	SDL_Rect r2 = {position.x-40, position.y+15, 120, 70};
	SDL_Rect r3 = {position.x+5, position.y+30, 145, 60};
	SDL_Rect r4 = {position.x-70, position.y+80, 15, 10};
	SDL_Rect r5 = {position.x+170, position.y+90, 15, 5};

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 237, 247, 255, 120);
	SDL_RenderFillRect(renderer, &r1);
	SDL_RenderFillRect(renderer, &r2);
	SDL_RenderFillRect(renderer, &r3);
	SDL_RenderFillRect(renderer, &r4);
	SDL_RenderFillRect(renderer, &r5);
}

// move the clouds through the sky
void Cloud::moveCloud(){
	position.x+=5;
	if (position.x > WIDTH + 50)
		position.x = -200;
}
