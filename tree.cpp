#include "tree.h"
#include <cstdlib>
#include <ctime>

Tree::Tree(SDL_Renderer* rend, SDL_Point p, const int h) : 
renderer(rend), POSITION(p), HEIGHT(h)
{
	leaves.reserve(HEIGHT/5);
	makeLeaves();
}

// stores the randomly generated rects to the vector
void Tree::makeLeaves()
{
	SDL_Point posCopy = POSITION;
	SDL_Rect r = {posCopy.x, posCopy.y,10,500};
	for (int i = 0; i < HEIGHT/5; i++){
		srand(time(0)+rand());
		posCopy.y+=(rand()%20+5);
		r = { posCopy.x-rand()%85+10,posCopy.y,
					rand()%50+50+(i/3),rand()%20+5+(i/3) };
		leaves.push_back(r);
	}
}

//draws treetrunks w/ 2 rects
void Tree::drawTrunks()
{
	SDL_SetRenderDrawColor(renderer, 43, 63, 62, 255);
  SDL_Rect r1 = {POSITION.x,POSITION.y,10,500};
	SDL_RenderFillRect(renderer, &r1 );
	SDL_Rect r2 = {POSITION.x+3, POSITION.y-4,4,4};
	SDL_RenderFillRect(renderer, &r2);
}

// draws trunk and all the leaves
void Tree::drawTree()
{	
	drawTrunks();
	for (int i = 0; i < (int)leaves.size();i++)
	{
		SDL_RenderFillRect(renderer, &leaves[i]);
	}
}

// swaying in the wind
void Tree::moveTree(int x)
{
	if (x%10<5){
		for (int i = 0; i < (int)leaves.size(); i++){
			leaves[i].x+=1;
		}
	}
	else
	{
		for (int i = 0; i < (int)leaves.size(); i++) {
			leaves[i].x-=1;
		}
	}
}

SDL_Point Tree::getPosition() const {
	return POSITION;
}
