#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "frameGenerator.h"
#include "mountain.h"
#include "tree.h"
#include "cloud.h"
#include <iostream>

const std::string NAME = "nfang";
const int WIDTH = 640;
const int HEIGHT = 480;

void reduceFraction (int &numerator, int &denominator)
{
	if (numerator < 0)
		numerator *= -1;
	if (denominator < 0)
		denominator *= -1;
	for (int i = denominator * numerator; i > 1; i--) {  
  	if ((denominator % i == 0) && (numerator % i == 0)) {  
    	denominator /= i;  
      numerator /= i;  
    }                  
  }
}

void addPoints (std::vector<SDL_Point> &points,SDL_Point start,SDL_Point end)
{
	int num = end.y-start.y;
	int den = end.x-start.x;
	
	int isNeg = 1; //slope down
	// exlusive or if any of them but not both are negative
	if ((num < 0) ^ (den < 0))
		isNeg = -1; //slope up

	reduceFraction(num,den);

	SDL_Point p = {start.x, start.y};

	for (int i = p.x; i < end.x; i++)
	{
		if(i%den < num)
			p.y+=(isNeg);
		p.x++;

		points.push_back(p);
	}

}

// go from (182, 190, 255) to (255, 190, 255)
void drawBackground(SDL_Renderer* rend){
	// sky gradient
	SDL_Color c = {182, 190, 244, 255};	
	for (int y = 0; y < HEIGHT/2; y++){
		if (y%3 == 0 )
			c.r++;
		if (c.r > 255)
			c.r = 255;
		SDL_SetRenderDrawColor(rend, c.r, c.g, c.b, c.a);
		SDL_RenderDrawLine(rend, 0, y, WIDTH,y);
	}
	// water gradient
	c = {84, 158, 255, 255};
	for (int y = HEIGHT/2; y < HEIGHT; y++){
		if (y%3 == 0){
			c.r++;
			c.g++;
		}	
		SDL_SetRenderDrawColor(rend, c.r, c.g, c.b, c.a);
		SDL_RenderDrawLine(rend,0,y, WIDTH, y);
	}
	// water lines/waves
	SDL_SetRenderDrawColor(rend, 255,255,255,255);
	
	for (int y = 310; y < HEIGHT; y+= 15){
		if (y%2 == 0){
			for (int x = 0; x < WIDTH; x+= 50){
				SDL_RenderDrawLine(rend, x, y, x+30, y);
			}
		}
		else{
			for (int x = -15; x < WIDTH; x+=50){
				SDL_RenderDrawLine(rend, x, y, x+30,y);
			}
		}
	}
}

void renderEverything(SDL_Renderer* rend, Cloud c1, Cloud c2, Mountain m1, 
											Mountain m2, Mountain m3, Mountain m4, Tree t1, Tree t2){
	drawBackground(rend);
	c1.drawCloud();
	m1.drawMountain();
	m2.drawMountain();
	c2.drawCloud();
	m3.drawMountain();
	m4.drawMountain();
	t1.drawTree();
	t2.drawTree();
}

//Overloaded Output Operator
std::ostream& operator<<(std::ostream& out, const Tree& t){
	return out << "\"That's a crooked tree. We'll send him to {"
						 << t.getPosition().x << ", " << t.getPosition().y 
						 << "}.\" - Bob Ross";
}

int main(void) {
  SDL_Renderer *renderer;
  SDL_Window *window;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer( WIDTH, HEIGHT, 0, &window, &renderer );

  SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
  SDL_RenderClear(renderer);

	//draw backgroundGradient
	drawBackground(renderer);

	//Cloudssss
	Cloud cloud1(renderer, {100, 2}, WIDTH);
	cloud1.drawCloud();
	Cloud cloud2(renderer, {440,30}, WIDTH);
	cloud2.drawCloud();

	//make vector of points that specify the top border for the mountains
	std::vector<SDL_Point> mtPoints;
	mtPoints.reserve(WIDTH); // reserve for length of painting

	// from point (0, 150) to (100, 70)
	SDL_Point startPt = {0, 150};
	SDL_Point endPt = {90, 70};

	mtPoints.push_back(startPt);
	addPoints(mtPoints, startPt, endPt);

	startPt = endPt;
	endPt = {120,90};
	addPoints(mtPoints, startPt,endPt);

	startPt = endPt;
	endPt = {210,40};
	addPoints(mtPoints, startPt, endPt);

	startPt = endPt;
	endPt = {280, 100};
	addPoints(mtPoints, startPt, endPt);

	startPt = endPt;
	endPt = {340, 110};
	addPoints(mtPoints, startPt, endPt);

	startPt = endPt;
	endPt = {355, 125};
	addPoints(mtPoints, startPt, endPt);	

	startPt = endPt;
	endPt = {400, 100};
	addPoints(mtPoints, startPt, endPt);	

	startPt = endPt;
	endPt = {500, 220};
	addPoints(mtPoints, startPt, endPt);	

	//draw Mountain 
	SDL_Color c = {143, 149, 181, 255};
	Mountain mount(renderer, c, mtPoints, 300);
	mount.drawMountain();

//	draw Snowcaps
	c = {227,242,241,255};
	Mountain caps(renderer, c, mtPoints, 110);
	caps.drawMountain();

	//draw hills
	std::vector<SDL_Point> hPoints;	
	hPoints.reserve(WIDTH);

	startPt = {10, 300};
	endPt = {30, 295};
	hPoints.push_back(startPt);
	addPoints(hPoints, startPt, endPt);

	startPt = endPt;
	endPt = {100, 250};
	addPoints(hPoints, startPt, endPt);

	startPt = endPt;
	endPt = {200, 240};
	addPoints(hPoints, startPt, endPt);

	startPt = endPt;
	endPt = {240, 260};
	addPoints(hPoints, startPt, endPt);

	startPt = endPt;
	endPt = {350, 200};
	addPoints(hPoints, startPt, endPt);

	startPt = endPt;
	endPt = {390, 220};
	addPoints(hPoints, startPt, endPt);

	startPt = endPt;
	endPt = {490, 150};
	addPoints(hPoints, startPt, endPt);

	startPt = endPt;
	endPt = {WIDTH, 90};
	addPoints(hPoints, startPt, endPt);

	c = {116, 191, 155, 255};
	Mountain hill1(renderer, c, hPoints, 300);
	hill1.drawMountain();

	//hill2 drawing
	std::vector<SDL_Point> hPoints2;
	hPoints.reserve(WIDTH);
	c = {84, 132, 118, 255};

	startPt = {10, 300};
	endPt = {80, 293};
	hPoints2.push_back(startPt);
	addPoints(hPoints2, startPt, endPt);

	startPt = endPt;
	endPt = {110, 280};
	addPoints(hPoints2, startPt, endPt);

	startPt = endPt;
	endPt = {140, 250};
	addPoints(hPoints2, startPt, endPt);

	startPt = endPt;
	endPt = {200, 270};
	addPoints(hPoints2, startPt, endPt);

	startPt = endPt;
	endPt = {380, 250};
	addPoints(hPoints2, startPt, endPt);

	startPt = endPt;
	endPt = {460, 265};
	addPoints(hPoints2, startPt, endPt);

	startPt = endPt;
	endPt = {510, 275};
	addPoints(hPoints2, startPt, endPt);

	startPt = endPt;
	endPt = {WIDTH, 220};
	addPoints(hPoints2, startPt, endPt);

	Mountain hill2(renderer, c, hPoints2, 300);
	hill2.drawMountain();

	//Draw Trees
	SDL_Point treeTop = {550, 50};
	Tree tree1(renderer, treeTop, HEIGHT);
	tree1.drawTree();
	treeTop = {400, 150};
	Tree tree2(renderer, treeTop, HEIGHT);
	tree2.drawTree();

	SDL_Surface *image = SDL_LoadBMP("bob.bmp");
	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	SDL_Rect pos = {-3, 280, 210, 210};

	SDL_RenderCopy(renderer, texture, NULL, &pos);

	//Print Tree Positions
	std::cout << tree1 << std::endl;
	std::cout << tree2 << std::endl;

  FrameGenerator frameGen(renderer, window, WIDTH, HEIGHT, NAME);
  frameGen.makeFrame();

	int i = 0, x = 0;

	SDL_Event event;
  const Uint8* keystate;
  while ( true ) {
    keystate = SDL_GetKeyboardState(0);
    if (keystate[SDL_SCANCODE_ESCAPE]) { break; }
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        break;
      }
    }
		
	//try to animate	
		if(i%50000==0){
			
			renderEverything (renderer, cloud1, cloud2, mount, caps, hill1, hill2, 
											tree1, tree2);
			SDL_RenderPresent(renderer);
			cloud1.moveCloud();
			cloud2.moveCloud();
			SDL_RenderCopy(renderer, texture, NULL, &pos);
			tree1.moveTree(x);
			tree2.moveTree(x);
			SDL_RenderPresent(renderer);
			SDL_RenderClear(renderer);
			x++;
		}
		i++;
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
