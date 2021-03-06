#include <SDL.h>

// Cloud object that can be made and drawn

class Cloud {
public:
	Cloud(SDL_Renderer*, SDL_Point, const int);
	void drawCloud();
	void moveCloud();
private: 
	SDL_Renderer* const renderer;
	SDL_Point position;
	const int WIDTH;
};
